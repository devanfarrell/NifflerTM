//
//  Validator.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#include "Validator.hpp"
#include "TM_Definition.hpp"


bool Validator::isValidDefinition()
{
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
