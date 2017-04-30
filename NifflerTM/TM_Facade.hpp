#ifndef TM_Facade_hpp
#define TM_Facade_hpp

#include "Validator.hpp"
#include "Transition_Processor.hpp"
#include "Input_Strings.hpp"
#include "TM_Definition.hpp"


class TM_Facade
{
private: //attributes
  std::string fileName;
  Validator * validator;
  Transition_Processor * transitionProcessor;
  Input_Strings * inputStrings;
  TM_Definition * tmDefinition;
  
private: //methods
  bool getPosInt( int&result, std::string prompt);
  
public: // methods
  //constructor and deconstructor
  TM_Facade(Validator * validator, TM_Definition * tmDefinition, Input_Strings * inputStrings, std::string fileName);
  ~TM_Facade();
  
  
  void deleteStr();
  void help();
  void insert();
  void list();
  void quit();
  void run();
  void set();
  void show();
  void truncate();
  void view();
};


#endif /* TM_Facade_hpp */
