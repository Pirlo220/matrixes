#include <logger.hpp>
#include <sys/stat.h>
#include <cstring>
int mkpath(std::string s,mode_t mode)
{
  size_t pre=0,pos;
  std::string dir;
  int mdret;

  if(s[s.size()-1]!='/'){
    // force trailing / so we can handle everything in loop
    s+='/';
  }

  while((pos=s.find_first_of('/',pre))!=std::string::npos){
    dir=s.substr(0,pos++);
    pre=pos;
    if(dir.size()==0) continue; // if leading / first time is 0 length
    if((mdret=mkdir(dir.c_str(),mode)) && errno!=EEXIST){
      return mdret;
    }
  }
  return mdret;
}

void log(string data){
 
  std::ofstream outfile;
  int mkdirretval;
  mkdirretval=mkpath("./logs", 0755);
  string date =  UtilsLibrary::get_current_date_as_string();
  string url = "./logs/" + date;
  outfile.open(url.c_str(), std::ios_base::app);
  if(outfile.is_open()){
    string info = "[" + UtilsLibrary::get_current_time_as_string() + "] :: " ;
    info += data ;
    outfile << info << endl; 
    outfile.close();
  } else {
    cerr << "Error al escribir en log" << endl;
  }
  
}
