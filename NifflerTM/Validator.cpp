//
//  Validator.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#include "Validator.hpp"
#include "TM_Definition.hpp"

#include <iostream>


bool Validator::isValidDefinition()
{
  stringsToTransitions();
  return true;
}

TM_Definition * Validator::constructDefinition()
{
  TM_Definition * tmDefinition = new TM_Definition(description, states,inputAlphabet, tapeAlphabet, transitionFunction, initialState, blankCharacter, finalStates);
  return tmDefinition;
}

Input_Strings * Validator::constructInputStrings()
{
    return NULL;
}
void Validator::validateInputFile(std::string fileName)
{
    
}
void Validator::testInputString(std::string inputString)
{
    
}
// begin validations

int Validator::stringsToTransitions()
{
  int errors;
  
  for(std::string::size_type i = 0; i < transitionFunctionStrings.size(); i = i + 5)
  {
    
  }
  
  return errors;
}







int Validator::statesMultiplicityValidation()
{
  int errors = 0;
  if(states.size() > 0)
  {
    for(std::string::size_type i = 0; i < states.size() > 0; i++)
    {
      for(std::string::size_type j = i + 1; j < states.size() > 0; j++)
      {
        if(states[i] == states[j])
        {
          std::cout << "ERROR IN STATES: " << states[i] << " defined multiple times" << std::endl;
          errors++;
        }
      }
    }
  }
  else
  {
    std::cout << "ERROR IN STATES: No states defined" << std::endl;
    errors++;
  }
  return errors;
}

int Validator::inputAlphabetMultiplicityValidation()
{
  int errors = 0;
  if(inputAlphabet.size() > 0)
  {
    for(std::string::size_type i = 0; i < inputAlphabet.size() > 0; i++)
    {
      for(std::string::size_type j = i + 1; j < inputAlphabet.size() > 0; j++)
      {
        if(inputAlphabet[i] == inputAlphabet[j])
        {
          std::cout << "ERROR IN INPUT_ALPHABET: " << inputAlphabet[i] << " defined multiple times" << std::endl;
          errors++;
        }
      }
    }
  }
  else
  {
    std::cout << "ERROR IN INPUT_ALPHABET: No alphabet defined" << std::endl;
    errors++;
  }
  return errors;
}

int Validator::tapeAlphabetMultiplicityValidation()
{
  int errors = 0;
  if(tapeAlphabet.size() > 0)
  {
    for(std::string::size_type i = 0; i < tapeAlphabet.size() > 0; i++)
    {
      for(std::string::size_type j = i + 1; j < tapeAlphabet.size() > 0; j++)
      {
        if(tapeAlphabet[i] == tapeAlphabet[j])
        {
          std::cout << "ERROR IN TAPE_ALPHABET: '" << tapeAlphabet[i] << "' defined multiple times" << std::endl;
          errors++;
        }
      }
    }
  }
  else
  {
    std::cout << "ERROR IN TAPE_ALPHABET: No alphabet defined" << std::endl;
    errors++;
  }
  return errors;
}

int Validator::inputInTapeValidation()
{
  int errors = 0;
  
  for(std::string::size_type i = 0; i < inputAlphabet.size() > 0; )
  {
    for(std::string::size_type j = 0; j < tapeAlphabet.size() > 0; j++)
    {
      if(inputAlphabet[i] == tapeAlphabet[j])
      {
        i++;
        j = tapeAlphabet.size();
      }
      if(inputAlphabet[i] != tapeAlphabet[j] && j == tapeAlphabet.size() - 1)
      {
        std::cout << "ERROR: '" << inputAlphabet[i] << "' included in INPUT_ALPHABET: but not included in TAPE_ALPHABET:" << std::endl;
        i++;
        errors++;
      }
    }
  }
  return errors;
}
int Validator::initialStateMultiplicityValidation()
{
  if(initialState.size() != 1)
  {
    return 1;
  }
  return 0;
}

int Validator::initialStateInStatesValidation()
{
  for(std::string::size_type i = 0; i < states.size(); i++)
  {
    if( initialState[0] == states[i])
    {
      return 0;
    }
  }
  
  std::cout << "ERROR: '" << initialState[0]  << "' included in INITIAL_STATE: but not included in STATES:" << std::endl;
  return 1;
}

int Validator::blankMultiplicityValidation()
{
  if(blankCharacter.size() != 1)
  {
    return 1;
  }
  return 0;
}


int Validator::blankNotInInputAlphabetValidation()
{
  for(std::string::size_type i = 0; i < states.size(); i++)
  {
    if( blankCharacter[0] == inputAlphabet[i])
    {
      std::cout << "ERROR: BLANK_CHARACTER: '" << blankCharacter[0]  << "' included in INPUT_ALPHABET:" << std::endl;
      return 1;
    }
  }
  return 0;
}

int Validator::blankInTapeAlphabetValidation()
{
  for(std::string::size_type i = 0; i < states.size(); i++)
  {
    if( blankCharacter[0] == tapeAlphabet[i])
    {
      return 0;
    }
  }
  std::cout << "ERROR: BLANK_CHARACTER: '" << blankCharacter[0]  << "' not included in TAPE_ALPHABET:" << std::endl;
  return 1;
}

int Validator::finalStatesMultiplicityValidation()
{
  int errors = 0;
  if(finalStates.size() > 0)
  {
    for(std::string::size_type i = 0; i < finalStates.size() > 0; i++)
    {
      for(std::string::size_type j = i + 1; j < finalStates.size() > 0; j++)
      {
        if(finalStates[i] == finalStates[j])
        {
          std::cout << "ERROR IN FINAL_STATES: " << states[i] << " defined multiple times" << std::endl;
          errors++;
        }
      }
    }
  }
  return errors;
}

int Validator::finalStatesinStatesValidation()
{
  int errors = 0;
  
  for(std::string::size_type i = 0; i < finalStates.size() > 0; )
  {
    for(std::string::size_type j = 0; j < states.size() > 0; j++)
    {
      if(finalStates[i] == states[j])
      {
        i++;
        j = states.size();
      }
      if(finalStates[i] != states[j] && j == states.size() - 1)
      {
        std::cout << "ERROR: '" << finalStates[i] << "' included in FINAL_STATES: but not included in STATES:" << std::endl;
        i++;
        errors++;
      }
    }
  }
  return errors;
}

