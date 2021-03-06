#ifndef Validator_hpp
#define Validator_hpp

#include "Transition.hpp"
#include "TM_Definition.hpp"
#include "Input_Strings.hpp"

#include <string>
#include <vector>

class Validator
{
  
private: // associations
  Input_Strings* inputStrings;
  TM_Definition* tmDefinition;
  
private: // attributes
  std::vector<std::string> description;
  std::vector<std::string> states;
  std::vector<std::string> inputAlphabet;
  std::vector<std::string> tapeAlphabet;
  std::vector<std::string> transitionFunctionStrings;
  std::vector<Transition> transitionFunction;
  std::vector<std::string> initialState;
  std::vector<std::string> blankCharacter;
  std::vector<std::string> finalStates;
  std::vector<int> keywordOrder;
  
public: // methods
  ////////////// begin constructor /////////////
  Validator(
            std::vector<std::string> description_in,
            std::vector<std::string> states_in,
            std::vector<std::string> inputAlphabet_in,
            std::vector<std::string> tapeAlphabet_in,
            std::vector<std::string> transitionFunction_in,
            std::vector<std::string> initialState_in,
            std::vector<std::string> blankCharacter_in,
            std::vector<std::string> finalStates_in,
            std::vector<int> keywordOrder_in);
  ////////////// end constructor /////////////
  
  
  bool isValidDefinition();
  TM_Definition* constructDefinition();
  Input_Strings* constructInputStrings();
  void validateInputFile(std::string fileName);
  bool testInputString(std::string inputString);
  
  
  //////////validations
private:
  int statesValidation();
  int statesDuplicityValidation();
  
  int inputAlphabetValidation();
  int inputAlphabetDuplicityValidation();
  
  int tapeAlphabetValidation();
  int tapeAlphabetDuplicityValidation();
  int inputInTapeValidation();
  int initialStateMultiplicityValidation();
  int initialStateInStatesValidation();
  int blankMultiplicityValidation();
  int blankNotInInputAlphabetValidation();
  int blankInTapeAlphabetValidation();
  int finalStatesDuplicityValidation();
  int finalStatesinStatesValidation();
  
  int basicTransitionTest();
  int nonDeterministicValidation();
  // TODO optional if there is no r or l as tape characters or states, do advancedTransitionTest
  // to reduce cascading errors
  
  int keywordOrderValidation();
  int keywordDuplicityValidation();
};

#endif /* Validator_hpp */
