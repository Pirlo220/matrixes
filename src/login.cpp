#include <string>
#include "login.hpp"
#include <iostream>
#include <pqxx/pqxx>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>


using namespace std;

const std::string ACCESS = "password";

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

int init_login(){ ;
  const char BACKSPACE=127;
  const char RETURN=10;
  std::string password;
  std::string user = "user";
  unsigned char ch=0;
  std::cout << "Please type in your password: ";

  while((ch=getch()) != RETURN){
    if(ch == BACKSPACE){
      if(password.length() != 0){
	std::cout <<"\b \b";
	password.resize(password.length()-1);
      }
    } else {
      password+=ch;
      std::cout <<'*';
    }
  }
  std::cout <<endl;
  return is_granted(user, password);
}

bool is_granted(std::string user_name, std::string mPass){
  if(is_user_locked(user_name)){
    throw LockedUserException();  
  }
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
			    "SELECT id " 
			    "FROM users " 			   
			    "WHERE name=" + txn.quote(user_name) +		    
			    "AND password=" + txn.quote(mPass));
  bool result = (r.size() == 1);
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
