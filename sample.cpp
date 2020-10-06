//This is sample
//Run this and check foo.log

#include "Nlog.hpp"

int main(){
  Nlog::Nlogger log("foo.log");

  log << Nlog::getDate(Nlog::NOTICE)+"Can you see this?\n";
}
