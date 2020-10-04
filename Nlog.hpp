/////////////////////////////
//   _   _ _               //
//  | \ | | | ___   __ _   //
//  |  \| | |/ _ \ / _` |  //
//  | |\  | | (_) | (_| |  //
//  |_| \_|_|\___/ \__, |  //
//                 |___/   //
//     Made by NULLCT      //
/////////////////////////////

#pragma once
#include <ctime>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <iomanip>
#include <sstream>

namespace Nlog{
  enum STATUS{
    NOTICE = 0,
    ERROR  = 1
  };
  const std::string getDate(int _statustype){
    std::string str;

    //Time
    time_t nowtime = time(nullptr);
    str = ctime(&nowtime);

    //Status
    switch(_statustype){
      case NOTICE:
        str+=" [NOTICE]:";
        break;

      case ERROR:
        str+=" [ERROR] :";
        break;

      case 256:
        str+=" [Nlog]  :";
        break;

      default:
        str+=" [NOTICE]:";
        break;
    }

    return str;
  }

  class Nlogger {
    std::ofstream file;
    bool isfileopen;

  public:
    Nlogger(std::string _filename) : file(_filename, std::ios::app) {
      isfileopen = file.is_open();
      file << getDate(255) << "-------Nlog was declared-------\n";
    }
    ~Nlogger() {
      file << getDate(255) << "-----Destructor was called-----\n";
      file.close();
    }
    bool isopen() { return isfileopen; }
    template<class T> inline void operator << (T _input){
      file << _input;
    }
  };
}
