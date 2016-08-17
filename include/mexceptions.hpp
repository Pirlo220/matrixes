#include <iostream>
#include <exception>

using namespace std;

class LockedUserException: public exception{
public:
  virtual const char* message() const throw(){
    return "Your user is locked please contact administrators";
  }
};
