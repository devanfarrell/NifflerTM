#include <iostream>
#include "TM_Definition.hpp"
#include "Transition.hpp"

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
  //print description
  for(std::string::size_type i = 0; i < description.size(); i++)
  {
    std::cout << description[i];
  }
  
  //print states
  std::cout << "Q\t = { " ;
  
  for(std::string::size_type i = 0; i < states.size() - 1; i++)
  {
    std::cout << states[i] << ", ";
  }
  std::cout << states[states.size() - 1] << " }"<< std::endl << std::endl;
  
  //print input alphabet
  std::cout << "\u03A3\t = { " ;
  for(std::string::size_type i = 0; i < inputAlphabet.size() - 1; i++)
  {
    std::cout << inputAlphabet[i] << ", ";
  }
  std::cout << inputAlphabet[inputAlphabet.size() - 1] <<" }"<< std::endl << std::endl;
  
  //print tape alphabet
  std::cout << "\u0393\t = { ";
  for(std::string::size_type i = 0; i < tapeAlphabet.size() - 1; i++)
  {
    std::cout << tapeAlphabet[i] << ", ";
  }
  std::cout << tapeAlphabet[tapeAlphabet.size() - 1]  <<" }"<< std::endl<< std::endl;
  
  //print functions
  for(size_t i = 0; i < transitionFunction.size(); i++)
  {
    std::cout << "\u03B4( " << transitionFunction[i].getCurrentState() << ", " << transitionFunction[i].getReadCharacter() << " ) = { " << transitionFunction[i].getWriteCharacter() << ", " << transitionFunction[i].getDestinationState() << ", " << transitionFunction[i].getDirection() << " }" << std::endl;
  }
  std::cout <<std::endl;
  
  //print initial state
  std::cout << "q\u2080\t = { "<< initialState << " }" << std::endl<< std::endl;
  
  //print blank character
  std::cout << "B\t = { "<< blankCharacter << " }" << std::endl<< std::endl;
  
  //print final states
  std::cout << "F\t = { " ;
  for(std::string::size_type i = 0; i < finalStates.size() - 1 && finalStates.size() > 0; i++)
  {
    std::cout << finalStates[i] << ", ";
  }
  if (finalStates.size() > 0)
  {
    std::cout << finalStates[finalStates.size() - 1];
  }
  std::cout << " }"<< std::endl << std::endl;
}

bool TM_Definition::isInputLetter(char testCharacter)
{
  bool found = false;
  for(size_t i = 0; i < inputAlphabet.size(); i++)
  {
    if(testCharacter == inputAlphabet[i])
    {
      found = true;
      i = inputAlphabet.size();
    }
  }
  return found;
}

bool TM_Definition::isFinalState(std::string currentState)
{
  bool found = false;
  for(size_t i = 0; i < finalStates.size(); i++)
  {
    if(currentState == finalStates[i])
    {
      found = true;
       i = finalStates.size();
    }
  }
  return found;
}

std::string TM_Definition::getInitialState( ) const
{
    return initialState;
}

char TM_Definition::getBlankCharacter() const
{
    return blankCharacter;
}

bool TM_Definition::searchTransition( std::string sourceState, char readCharacter, std::string &destinationState, char &writeCharacter, char &moveDirection) const
{
  bool found = false;
  for(size_t i = 0; i < transitionFunction.size(); i++)
  {
    if(sourceState == transitionFunction[i].getCurrentState() && readCharacter == transitionFunction[i].getReadCharacter())
    {
      destinationState = transitionFunction[i].getDestinationState();
      writeCharacter = transitionFunction[i].getWriteCharacter();
      moveDirection = transitionFunction[i].getDirection();
      found = true;
      i = transitionFunction.size();
    }
  }
  return found;
}
