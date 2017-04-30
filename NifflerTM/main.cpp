#include "TM.hpp"

#include <iostream>
#define FILE "/Users/devan/NifflerTM/NifflerTM/infiniteloop"

int main(int argc, const char * argv[]) {
  TM tm;
  bool openAndValid = tm.load(FILE);
  
  if(openAndValid)
  {
    std::cout << "Successfully loaded!" << std::endl;
    tm.initiate();
  }
    return 0;
}
