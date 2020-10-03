#pragma once
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

class Nlog {
  std::ofstream file;
  bool isfileopen;

  const std::string getCurrentDateTime() {
    time_t now = time(NULL);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
  }

public:
  enum STATUS{
    NOTICE = 0,
    ERROR = 1,
  };

  Nlog(std::string _filename) : file(_filename) { isfileopen = file.is_open(); }
  void put(std::string _word){
    
  }
};
