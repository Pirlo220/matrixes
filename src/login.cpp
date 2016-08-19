#include <string>
#include "login.hpp"
#include <iostream>
#include <pqxx/pqxx>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sodium.h>
#include <cstring>

using namespace std;

#define OUT_LEN 128
#define OPSLIMIT 500000
#define MEMLIMIT 5000000
#define KEY_LEN crypto_box_SEEDBYTES
//user  - "password"
//user2 - " password2" 

void update_password_user(const char* user_passw, string user_name){
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c); 
  txn.exec(
	   "UPDATE users "
	   "SET password = " + txn.quote(user_passw) +
	   "WHERE name = " + txn.quote(user_name));

  txn.commit();  
}

bool is_valid_passw(string user_name, string user_passw, string stored_passw){
  int init_sodium = sodium_init();// 0 on Success, -1 on failure, 1 the library is already initialized;
  if(init_sodium == -1){
    cerr << "exception caught: " << "Error initalizing Sodium Library" << endl;
    return -1;
  }
  bool result = false;
  char hashed_password[crypto_pwhash_scryptsalsa208sha256_STRBYTES];
  const char* user_p = user_passw.c_str();
  const char* stored_p = stored_passw.c_str();
  if (crypto_pwhash_scryptsalsa208sha256_str
      (hashed_password, user_p, strlen(user_p),
       OPSLIMIT,
       MEMLIMIT) != 0) {
    cout << "out of memory"<<endl;
    return false;
  }
  if (crypto_pwhash_scryptsalsa208sha256_str_verify
      (stored_p, user_p, strlen(user_p)) != 0) {
    result = false;
  } else {
    result = true;
    update_password_user(hashed_password, user_name);
  }
  return result;
}


int getch() {
  int ch;
  struct termios t_old, t_new;

  tcgetattr(STDIN_FILENO, &t_old);
  t_new = t_old;
  t_new.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &t_new);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &t_old);
  return ch;
}

std::string get_user_input(string message, bool maskared){
  const char BACKSPACE=127;
  const char RETURN=10;
  unsigned char ch=0;
  string user_value = "";
  cout << message;
  while(((ch=getch()) !='\n') && ch != EOF){//!= RETURN){    
    if(ch == BACKSPACE){
      if(user_value.length() != 0){
	cout <<"\b \b";
	user_value.resize(user_value.length()-1);
      }   
    } else {
      user_value += ch;
      if(maskared) {
	cout << '*';
      } else {
	cout << ch;
      }
    }    
  }
  cout <<endl;
  return user_value;
}

int init_login(){   
  string user = get_user_input( "Please type in your user name: ", false);
  string password = get_user_input( "Please type in your password: ", true);  
  return is_granted(user, password);
}

bool is_granted(std::string user_name, std::string user_passw){
  if(is_user_locked(user_name)){
    throw LockedUserException();  
  }
  bool result = false;
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
			    "SELECT id, password " 
			    "FROM users " 			   
			    "WHERE name=" + txn.quote(user_name));
  if(r.size() == 1){
    result = is_valid_passw(user_name, user_passw,r[0][1].as<string>());
  }
  if(!result) {
    increment_attempt_per_user(user_name);
  } else {
    reset_attempts(user_name);
  }
  return result;
}

void reset_attempts(std::string user_name){
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);
  txn.exec(
	     "UPDATE users "
	     "SET attempts = 0 "
	     "WHERE name = " + txn.quote(user_name));

  txn.commit();
}

bool is_user_locked(std::string user_name){

  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
			    "SELECT id " 
			    "FROM users " 			   
			    "WHERE name=" + txn.quote(user_name) +		    
			    "AND attempts=attempts_allowed");
 return (r.size() == 1);  
}

void increment_attempt_per_user(std::string user_name){
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
			    "SELECT id " 
			    "FROM users " 			   
			    "WHERE name=" + txn.quote(user_name));
  if(r.size() == 1){
    int user_id = r[0][0].as<int>();
    txn.exec(
	     "UPDATE users "
	     "SET attempts = attempts + 1 "
	     "WHERE id = " + txn.quote(user_id));

    txn.commit();
  } 
}


std::string get_coded_password(std::string mPass){

}
