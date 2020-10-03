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
  void addStatus(int _status) {
    file << getCurrentDateTime();
    switch (_status) {
    case NOTICE:
      file << " [NOTICE]:";
      break;
    case ERROR:
      file << " [ERROR] :";
      break;
    case 256:
      file << " [Nlog]  :";
      break;
    }
  }

public:
  enum STATUS {
    NOTICE = 0,
    ERROR = 1,
    // Nlog = 256
  };

  Nlog(std::string _filename) : file(_filename, std::ios::app) {
    isfileopen = file.is_open();
    addStatus(256);
    file << "-------Nlog was declared-------\n";
  }

  ~Nlog() {
    addStatus(256);
    file << "-----Destructor was called-----\n";
    file.close();
  }

  void put(std::string _word,int _status) {
    addStatus(_status);
    file << _word << "\n";
  }
};
