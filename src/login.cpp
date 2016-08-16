#include <string>
#include "login.hpp"
#include <iostream>
#include <pqxx/pqxx>
#include <stdio.h>

const std::string ACCESS = "password";

int login(){
  char c = ' ';
  std::string password;
  std::string user="sergio";	
  std::cout << "Please type in your password: \n";
  //do{		
    c=getchar();
    std::cout << "HERE 0";
    putchar(c);
    if(c==13){
      std::cout << "HERE 1";
      std::cout << "\nPlease type in your password: \n";
      password = "";
    }
    if(c >= 33 && c <= 122){//[0-9][A-Z,a-z]
      password += c;
      std::cout << "HERE 2";
      std::cout << '*';
    }
    else if (c == 8){//backspace implementation
      std::cout << "HERE 3";
      std::cout << '\b';
      std::cout << ' ';
      std::cout << '\b';
      password = password.substr(0, password.size()-1);
    }	
    //}while(!isGranted(user, password));	
    return isGranted(user, password);
}

bool isGranted(std::string user, std::string mPass){
  //return (mPass == ACCESS);
  int i = 0;
  pqxx::connection c("dbname=matrixes user=matrixuser");
  pqxx::work txn(c);

  pqxx::result r = txn.exec(
			    "SELECT id " 
			    "FROM users " 			   
			    "WHERE name=" + txn.quote(user) +		    
			    "AND password=" + txn.quote(mPass));
  std::cout << mPass << "\n";

  return (r.size() == 1);
}

std::string get_coded_pass(std::string mPass){

}
