#ifndef TM_hpp
#define TM_hpp

#include "TM_Facade.hpp"

#include <string>

class TM
{
private: // associations
  TM_Facade* tmFacade;
  
private: // attributes
  bool hasLoaded;
  
private: // methods
  void commandLogic();
  
public: // methods
  TM();
  ~TM();
  
  bool load(std::string fileName);
  void initiate();
};

#endif /* TM_hpp */
