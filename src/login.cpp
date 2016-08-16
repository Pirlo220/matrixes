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

int login(){
  const char BACKSPACE=127;
  const char RETURN=10;
  string password;
  string user = "sergio";
  unsigned char ch=0;
  std::cout << "Please type in your password: "<<endl;

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
  return isGranted(user, password);
}

bool isGranted(std::string user, std::string mPass){
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
			    "SELECT id " 
			    "FROM users " 			   
			    "WHERE name=" + txn.quote(user) +		    
			    "AND password=" + txn.quote(mPass));
  return (r.size() == 1);
}

std::string get_coded_pass(std::string mPass){

}
