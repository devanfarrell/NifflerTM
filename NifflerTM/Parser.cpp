//
//  Parser.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#include "Parser.hpp"

void Parser::descriptionParse(std::__1::ifstream * definitionFile)
{
    bool statesFound = false;
    
    while(!statesFound)
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        std::locale loc;
        std::string toFind ("states:");
        
        
        if ( definitionFile->good() )
        {
            getline (*definitionFile, unmanipulatedStr);
        }
        else
        {
            return;
        }
      
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        
        std::size_t found = tempStr.find(toFind);
        
        if (found!=std::string::npos)
        {
            description.push_back(unmanipulatedStr.substr(0,found));
            statesFound = true;
        }
        else
        {
            if(unmanipulatedStr.size() > 0)
            {
                description.push_back(unmanipulatedStr + "\n");
            }
            else
            {
                description.push_back("\n");
            }
        }
    }
    return;
}
void Parser::statesParse(std::__1::ifstream * definitionFile)
{
    int statesFound = 0;
    int errors = 0;
    int foundEndOfStates = 0;
    std::locale loc;
    
    
    while(!statesFound && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        (*definitionFile) >> unmanipulatedStr;
        
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "states:")
        {
            statesFound++;
        }
    }
    while(!foundEndOfStates && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        (*definitionFile) >> unmanipulatedStr;
        
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "input_alphabet:")
        {
            foundEndOfStates++;
        }
        else if(tempStr == "tape_alphabet:" || tempStr == "transition_function:" || tempStr == "inital_state:" || tempStr == "blank_character:" || tempStr == "final_states:" || tempStr == "states:")
        {
            //This section is used because it will make error checking more thorough in the other sections even though the entire parsing will be thrown away because of this error. The error statement will be caught in validater
            foundEndOfStates++;
            errors++;
        }
        else
        {
            states.push_back(unmanipulatedStr);
        }
    }
    return;
}
void Parser::inputAlphabetParse(std::__1::ifstream * definitionFile)
{
    int inputAlphabetFound = 0;
    int errors = 0;
    int foundEndOfInputAlphabet = 0;
    std::locale loc;
    
    while(!inputAlphabetFound && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        if ( definitionFile->good() )
        {
            (*definitionFile) >> unmanipulatedStr;
        }
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "input_alphabet:")
        {
            inputAlphabetFound++;
        }
    }
    while(!foundEndOfInputAlphabet && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        (*definitionFile) >> unmanipulatedStr;
        
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "tape_alphabet:")
        {
            foundEndOfInputAlphabet++;
        }
        else if(tempStr == "input_alphabet:" || tempStr == "transition_function:" || tempStr == "inital_state:" || tempStr == "blank_character:" || tempStr == "final_states:" || tempStr == "states:")
        {
            //This section is used because it will make error checking more thorough in the other sections even though the entire parsing will be thrown away because of this error. The error statement will be caught in validater
            foundEndOfInputAlphabet++;
            errors++;
        }
        else
        {
            inputAlphabet.push_back(unmanipulatedStr);
        }
    }
    return;
}
void Parser::tapeAlphabetParse(std::__1::ifstream * definitionFile)
{
    int tapeAlphabetFound = 0;
    int errors = 0;
    int foundEndOfTapeAlphabet = 0;
    std::locale loc;
    
    while(!tapeAlphabetFound && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        (*definitionFile) >> unmanipulatedStr;
        
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "tape_alphabet:")
        {
            tapeAlphabetFound++;
        }
    }
    while(!foundEndOfTapeAlphabet && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        (*definitionFile) >> unmanipulatedStr;
        
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "transition_function:")
        {
            foundEndOfTapeAlphabet++;
        }
        else if(tempStr == "input_alphabet:" || tempStr == "tape_alphabet:" || tempStr == "inital_state:" || tempStr == "blank_character:" || tempStr == "final_states:" || tempStr == "states:")
        {
            //This section is used because it will make error checking more thorough in the other sections even though the entire parsing will be thrown away because of this error. The error statement will be caught in validater
            foundEndOfTapeAlphabet++;
            errors++;
        }
        else
        {
            tapeAlphabet.push_back(unmanipulatedStr);
        }
    }
    
    return;
}
void Parser::transitionFunctionParse(std::__1::ifstream * definitionFile)
{
    int transitionFunctionsFound = 0;
    int errors = 0;
    int foundEndOfTransitionFunctions = 0;
    std::locale loc;
    
    while(!transitionFunctionsFound && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        (*definitionFile) >> unmanipulatedStr;
        
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "transition_function:")
        {
            transitionFunctionsFound++;
        }
    }
    while(!foundEndOfTransitionFunctions && definitionFile->good())
    {
        std::string unmanipulatedStr;
        std::string tempStr;
        
        (*definitionFile) >> unmanipulatedStr;
        
        for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
        {
            tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
        }
        if(tempStr == "initial_state:")
        {
            foundEndOfTransitionFunctions++;
        }
        else if(tempStr == "input_alphabet:" || tempStr == "tape_alphabet:" || tempStr == "transition_function:" || tempStr == "blank_character:" || tempStr == "final_states:" || tempStr == "states:")
        {
            //This section is used because it will make error checking more thorough in the other sections even though the entire parsing will be thrown away because of this error. The error statement will be caught in validater
            foundEndOfTransitionFunctions++;
            errors++;
        }
        else
        {
            transitionFunction.push_back(unmanipulatedStr);
        }
    }
    return;
}
void Parser::initialStateParse(std::__1::ifstream * definitionFile)
{
  int initialStateFound = 0;
  int errors = 0;
  int foundEndOfInitialState = 0;
  std::locale loc;
  
  while(!initialStateFound && definitionFile->good())
  {
    std::string unmanipulatedStr;
    std::string tempStr;
    
    
    (*definitionFile) >> unmanipulatedStr;
    
    for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
    {
      tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
    }
    if(tempStr == "initial_state:")
    {
      initialStateFound++;
    }
  }
  while(!foundEndOfInitialState && definitionFile->good())
  {
    std::string unmanipulatedStr;
    std::string tempStr;
    
    (*definitionFile) >> unmanipulatedStr;
    
    for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
    {
      tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
    }
    if(tempStr == "blank_character:")
    {
      foundEndOfInitialState++;
    }
    else if(tempStr == "input_alphabet:" || tempStr == "tape_alphabet:" || tempStr == "inital_state:" || tempStr == "transition_function:" || tempStr == "final_states:" || tempStr == "states:")
    {
      //This section is used because it will make error checking more thorough in the other sections even though the entire parsing will be thrown away because of this error. The error statement will be caught in validater
      foundEndOfInitialState++;
      errors++;
    }
    else
    {
      initialState.push_back(unmanipulatedStr);
    }
  }
}
void Parser::blankCharacterParse(std::__1::ifstream * definitionFile)
{
  int blankCharacterFound = 0;
  int errors = 0;
  int foundEndOfBlankCharacter = 0;
  std::locale loc;
  
  while(!blankCharacterFound && definitionFile->good())
  {
    std::string unmanipulatedStr;
    std::string tempStr;
    
    (*definitionFile) >> unmanipulatedStr;
    
    for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
    {
      tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
    }
    if(tempStr == "blank_character:")
    {
      blankCharacterFound++;
    }
  }
  while(!foundEndOfBlankCharacter && definitionFile->good())
  {
    std::string unmanipulatedStr;
    std::string tempStr;
    
    (*definitionFile) >> unmanipulatedStr;
    
    for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
    {
      tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
    }
    if(tempStr == "final_states:")
    {
      foundEndOfBlankCharacter++;
    }
    else if(tempStr == "input_alphabet:" || tempStr == "tape_alphabet:" || tempStr == "inital_state:" || tempStr == "transition_function:" || tempStr == "blank_character:" || tempStr == "states:")
    {
      //This section is used because it will make error checking more thorough in the other sections even though the entire parsing will be thrown away because of this error. The error statement will be caught in validater
      foundEndOfBlankCharacter++;
      errors++;
    }
    else
    {
      blankCharacter.push_back(unmanipulatedStr);
    }
  }
  return;
}
void Parser::finalStatesParse(std::__1::ifstream * definitionFile)
{
  int statesFound = 0;
  int foundEndOfStates = 0;
  std::locale loc;
  
  
  while(!statesFound && definitionFile->good())
  {
    std::string unmanipulatedStr;
    std::string tempStr;
    
    (*definitionFile) >> unmanipulatedStr;
    
    for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
    {
      tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
    }
    if(tempStr == "final_states:")
    {
      statesFound++;
    }
  }
  while(!foundEndOfStates && definitionFile->good())
  {
    std::string unmanipulatedStr;
    std::string tempStr;
    
    (*definitionFile) >> unmanipulatedStr;
    
    for(std::string::size_type i = 0; i < unmanipulatedStr.length(); i++)
    {
      tempStr = tempStr + std::tolower(unmanipulatedStr[i], loc);
    }
    
    if(tempStr == "tape_alphabet:" || tempStr == "transition_function:" || tempStr == "inital_state:" || tempStr == "blank_character:" || tempStr == "final_states:" || tempStr == "states:" || tempStr == "input_alphabet:")
    {
      //This section is used because it will make error checking more thorough in the other sections even though the entire parsing will be thrown away because of this error. The error statement will be caught in validater
      foundEndOfStates++;
    }
    else
    {
      finalStates.push_back(unmanipulatedStr);
    }
  }
  return;
}
void Parser::keywordOrderParse(std::__1::ifstream * definitionFile)
{
    
}


Validator * Parser::definitionParse(std::__1::ifstream * definitionFile)
{
   
  descriptionParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  statesParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  inputAlphabetParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  tapeAlphabetParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  transitionFunctionParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  initialStateParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  blankCharacterParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  finalStatesParse(definitionFile);
  definitionFile->clear();
  definitionFile->seekg(0, std::ios::beg);
  keywordOrderParse(definitionFile);
  
  
  Validator * validator = new Validator(description, states, inputAlphabet, tapeAlphabet, transitionFunction, initialState,blankCharacter, finalStates, keywordOrder);
  
  return validator;
}
