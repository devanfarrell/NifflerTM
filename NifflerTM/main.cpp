//
//  main.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/12/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#include "TM.hpp"

#include <iostream>

int main(int argc, const char * argv[]) {
  bool openAndValid;
  TM * tm = new TM();
  
  openAndValid = tm->load("file name");
  
  if(openAndValid)
  {
    std::cout << "Successfully loaded!" << std::endl;
    tm->initiate();
  }
  
  delete tm;
    
    return 0;
}
