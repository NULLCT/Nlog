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
  /*
   * Error type:
   *   NOTICE
   *   ERROR
   *   Nlog
   */

  Nlog(std::string _filename) : file(_filename, std::ios::app) {
    isfileopen = file.is_open();
    file << getCurrentDateTime()
         << " [Nlog]  :-------Nlog was declared-------\n";
  }

  ~Nlog() {
    file << getCurrentDateTime()
         << " [Nlog]  :-----Destructor was called-----\n";
    file.close();
  }

  void putNotice(std::string _word) {
    file << getCurrentDateTime() << " [NOTICE]:" << _word << "\n";
  }

  void putError(std::string _word) {
    file << getCurrentDateTime() << " [ERROR] :" << _word << "\n";
  }

  bool isopen() { return isfileopen; }
};
