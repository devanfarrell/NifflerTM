#ifndef Transition_Processor_hpp
#define Transition_Processor_hpp

#include "Input_Strings.hpp"
#include "TM_Definition.hpp"
#include "Tape.hpp"

#include <string>


class Transition_Processor
{
private: // associations
  Input_Strings* inputStrings;
  TM_Definition* tmDefinition;
  Tape* tape;
  
  
private: // attributes
  std::string currentState;
  unsigned long totalTransitions;
  std::string originalInputString;
  bool used;
  bool operating;
  bool accepted;
  bool rejected;
  int maxCells;
  int maxTransitions;
  
private: // methods
  void transitionUpdate(std::string desitinationState, char writeCharacter, char moveDirection);
  void viewInstantaneousDescription();
  void reject();
  void accept();
  
  
public: // methods
  Transition_Processor(Input_Strings* inputStrings, TM_Definition* tmDefinition);
  ~Transition_Processor();
  
  bool isOperating() const;
  void performTransitions();
  void showConfigurationSettings();
  void showTMStatus();
  void initialize(int inputStringIndex);
  void quitOperation();
  int getMaxCells() const;
  void setMaxCells(unsigned int posInt);
  int getMaxTransitions() const;
  void setMaxTransitions(unsigned int posInt);
};


#endif /* Transition_Processor_hpp */
