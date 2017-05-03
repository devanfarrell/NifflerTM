#include "TM.hpp"

#include <iostream>

int main(int argc, const char* argv[])
{
  TM tm;
  
  if (argc > 1)
  {
    bool openAndValid = tm.load(argv[1]);
    
    if (openAndValid)
    {
      std::cout << "Successfully loaded!" << std::endl;
      tm.initiate();
    }
  }
  else
  {
    fprintf(stderr, "Must pass an argument!\n");
    exit(1);
  }
  return 0;
}
