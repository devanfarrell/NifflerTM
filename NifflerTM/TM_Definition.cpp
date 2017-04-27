#include <iostream>
#include "TM_Definition.hpp"

//begin constructor
TM_Definition::TM_Definition(std::vector<std::string> description_in, std::vector<std::string> states_in, std::vector<std::string> inputAlphabet_in,std::vector<std::string> tapeAlphabet_in, std::vector<Transition> transitionFunction_in, std::vector<std::string> initialState_in, std::vector<std::string> blankCharacter_in, std::vector<std::string> finalStates_in):
  description(description_in),
  states(states_in),
  transitionFunction(transitionFunction_in),
  finalStates(finalStates_in)
{
  
  for(int i = 0; i < inputAlphabet_in.size(); i++)
  {
    std::string temp = inputAlphabet_in[i];
    inputAlphabet.push_back(temp[0]);
  }
  
  for(int i = 0; i < tapeAlphabet_in.size(); i++)
  {
    std::string temp = tapeAlphabet_in[i];
    tapeAlphabet.push_back(temp[0]);
  }
  std::string temp = blankCharacter_in[0];
  blankCharacter = temp[0];
  initialState = initialState_in[0];
}//end constructor


void TM_Definition::view_definition()
{
  
}

bool TM_Definition::isInputLetter(char testCharacter)
{
    return true;
}

bool TM_Definition::isFinalState(std::string currentState)
{
    return true;
}

std::string TM_Definition::getInitialState( ) const
{
    return "initialState";
}

char TM_Definition::getBlankCharacter() const
{
    return '-';
}

bool TM_Definition::search_transition( std::string sourceState, char readCharacter, std::string &destinationState, char &writeCharacter, char moveDirection) const
{
    return true;
}
