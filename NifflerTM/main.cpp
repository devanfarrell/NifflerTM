//
//  main.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/12/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#include "TM.hpp"

#include <iostream>
#define FILE "/Users/devan/NifflerTM/NifflerTM/tm.def"
#define NODEFFILE "/Users/devan/NifflerTM/NifflerTM/tm"

int main(int argc, const char * argv[]) {
  TM tm;
  bool openAndValid = tm.load(NODEFFILE);
  
  if(openAndValid)
  {
    std::cout << "Successfully loaded!" << std::endl;
    tm.initiate();
  }
    return 0;
}
