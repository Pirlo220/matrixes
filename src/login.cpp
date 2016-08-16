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

int init_login(){
  const char BACKSPACE=127;
  const char RETURN=10;
  string password;
  string user = "sergio";
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

bool is_granted(std::string user, std::string mPass){
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
			    "SELECT id " 
			    "FROM users " 			   
			    "WHERE name=" + txn.quote(user) +		    
			    "AND password=" + txn.quote(mPass));
  return (r.size() == 1);
}

void increment_attempt_per_user(std::string user){
}

std::string get_coded_password(std::string mPass){

}
