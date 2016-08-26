#include <logger.hpp>
#include <sys/stat.h>
#include <cstring>
#include <sodium.h>

string get_file_content(string url);
string get_content_hash(string data);

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
  get_file_content(url);
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

void log_error(string data){
  string error = "ERROR :: " + data;
  log(error);
}

string get_content_hash(string data){
  unsigned char hash[crypto_generichash_BYTES];
  const unsigned char *data_p = new unsigned char[data.length()+1];

  crypto_generichash(hash, sizeof hash, ((const unsigned char *)data), strlen(data_p), NULL, 0);
  string t(hash, 0, sizeof hash);
  return t;
}

string get_file_content(string url){
  string line;
  ifstream myfile (url);
  if (myfile.is_open())
    {
      while ( getline (myfile,line) )
	{
	  cout << line << '\n';
	}
      myfile.close();
    }

  else cout << "Unable to open file"; 
}


