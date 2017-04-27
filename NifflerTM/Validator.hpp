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
    Input_Strings * inputStrings;
    
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
              std::vector<int> keywordOrder_in):
    description(description_in),
    states(states_in),
    inputAlphabet(inputAlphabet_in),
    tapeAlphabet(tapeAlphabet_in),
    transitionFunctionStrings(transitionFunction_in),
    initialState(initialState_in),
    blankCharacter(blankCharacter_in),
    finalStates(finalStates_in),
    keywordOrder(keywordOrder_in)
    {
    }
    ////////////// end constructor /////////////
    
    
    bool isValidDefinition();
    TM_Definition * constructDefinition();
    Input_Strings * constructInputStrings();
    void validateInputFile(std::string fileName);
    void testInputString(std::string inputString);
  
  
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
  //if there is no r or l as tape characters or states, do advancedTransitionTest to remove mojar cascading errors
};

#endif /* Validator_hpp */
