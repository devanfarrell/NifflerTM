#include "Validator.hpp"
#include "TM_Definition.hpp"

#include <iostream>
#include <string>
#include <fstream>


bool Validator::isValidDefinition()
{
  int errors = 0;
  bool valid;
  
  
  errors += statesValidation();
  errors += statesDuplicityValidation();
  
  errors += inputAlphabetValidation();
  errors += inputAlphabetDuplicityValidation();

  errors += tapeAlphabetValidation();
  errors += tapeAlphabetDuplicityValidation();
  
  errors += initialStateMultiplicityValidation();
  errors += blankMultiplicityValidation();
  
  errors += finalStatesDuplicityValidation();
  
  errors += inputInTapeValidation();
  errors += initialStateInStatesValidation();
  errors += blankNotInInputAlphabetValidation();
  errors += blankInTapeAlphabetValidation();
  errors += finalStatesinStatesValidation();

  errors += basicTransitionTest();
  //TODO errors += nonDeterministicValidation();
  
  if (!errors) valid = true;
  else valid = false;
  
  return valid;
}

TM_Definition * Validator::constructDefinition()
{
  tmDefinition = new TM_Definition(description, states,inputAlphabet, tapeAlphabet, transitionFunction, initialState, blankCharacter, finalStates);
  return tmDefinition;
}

Input_Strings * Validator::constructInputStrings()
{
    inputStrings = new Input_Strings;
    return inputStrings;
}
void Validator::validateInputFile(std::string fileName)
{
  std::ifstream inputStringFile;
  std::string fileToOpen = fileName + ".str";
  inputStringFile.open(fileToOpen);
  if(inputStringFile.is_open())
  {
    while(inputStringFile.good())
    {
      std::string testLine;
      getline(inputStringFile, testLine);
      bool valid = testInputString(testLine);
      if(valid) inputStrings->appendString(testLine);
    }
    inputStringFile.close();
  }
}
bool Validator::testInputString(std::string inputString)
{
  bool valid = true; //true unless proven otherwise
  for(size_t i =0; i < inputString.length() && valid; i++)
  {
    valid = tmDefinition->isInputLetter(inputString[i]); //
  }
  if(inputString.length() == 1 && inputString == "\\")
     {
       valid = true;
     }
  else if(inputString.length() == 0) valid = false;
  return valid;
}




// begin validations

int Validator::statesValidation()
{
  int errors = 0;
  for(size_t i = 0; i < states.size(); i++)
  {
    if( !((int)states[i].find_first_of("\[]<>)")==-1) )
    {
      std::cout << "ERROR IN STATES: " << states[i] << " contains one of the illegal characters \\ [  ] < >  " << std::endl;
      errors++;
    }
  }
  return errors;
}

int Validator::statesDuplicityValidation()
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
          std::cout << "ERROR IN STATES: " << states[i] << " declared multiple times" << std::endl;
          errors++;
        }
      }
    }
  }
  else
  {
    std::cout << "ERROR IN STATES: No states declared" << std::endl;
    errors++;
  }
  return errors;
}


int Validator::inputAlphabetValidation()
{
  int errors = 0;
  for(size_t i = 0; i < inputAlphabet.size(); i++)
  {
    if(inputAlphabet[i].length() > 1)
    {
      std::cout << "ERROR IN INPUT_ALPHABET: '" << inputAlphabet[i] << "' is longer than a single character" << std::endl;
      errors++;
    }
    if( !((int)inputAlphabet[i].find_first_of("\[]<>)")==-1) )
    {
      std::cout << "ERROR IN INPUT_ALPHABET: '" << inputAlphabet[i] << "' contains one of the illegal characters \\ [  ] < >  " << std::endl;
      errors++;
    }
  }
  return errors;
}

int Validator::inputAlphabetDuplicityValidation()
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
          std::cout << "ERROR IN INPUT_ALPHABET: '" << inputAlphabet[i] << "' declared multiple times" << std::endl;
          errors++;
        }
      }
    }
  }
  return errors;
}

int Validator::tapeAlphabetValidation()
{
  int errors = 0;
  for(size_t i = 0; i < tapeAlphabet.size(); i++)
  {
    if(tapeAlphabet[i].length() > 1)
    {
      std::cout << "ERROR IN TAPE_ALPHABET: '" << inputAlphabet[i] << "' is longer than a single character" << std::endl;
      errors++;
    }
    if( !((int)inputAlphabet[i].find_first_of("\[]<>)")==-1) )
    {
      std::cout << "ERROR IN TAPE_ALPHABET: '" << inputAlphabet[i] << "' contains one of the illegal characters \\ [  ] < >  " << std::endl;
      errors++;
    }
  }
  return errors;
}

int Validator::tapeAlphabetDuplicityValidation()
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
          std::cout << "ERROR IN TAPE_ALPHABET: '" << tapeAlphabet[i] << "' declared multiple times" << std::endl;
          errors++;
        }
      }
    }
  }
  else
  {
    std::cout << "ERROR IN TAPE_ALPHABET: No characters declared" << std::endl;
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

int Validator::finalStatesDuplicityValidation()
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
          std::cout << "ERROR IN FINAL_STATES: " << states[i] << " declared multiple times" << std::endl;
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








int Validator::basicTransitionTest()
{
  int totalErrors = 0;
  
  for(std::string::size_type i = 0; i < transitionFunctionStrings.size(); )
  {
    int errors = 0;
    bool cascadingError = false;
    
    //check that current state is in states
    bool validCurrentState = false;
    std::string currentState = transitionFunctionStrings[i];
    
    
    for(size_t j = 0; j < states.size(); j++)
    {
      if (currentState == states[j])
      {
        validCurrentState = true;
        j = states.size();
      }
    }
    
    //check that read state is not a final state
    bool currentStateIsFinalState = false;
    
    
    if (i < transitionFunctionStrings.size())
    {
      for(size_t j = 0; j < finalStates.size(); j++)
      {
        if (currentState == finalStates[j])
        {
          currentStateIsFinalState = true;
          j = states.size();
        }
      }
      i++;
    }
    else cascadingError = true;
    
    //check that read letter is in tapeAlphabet
    bool validReadLetter = false;
    std::string readLetter = transitionFunctionStrings[i];
    
    
    if (i < transitionFunctionStrings.size())
    {
      for(size_t j = 0; j < tapeAlphabet.size(); j++)
      {
        if (readLetter == tapeAlphabet[j])
        {
          validReadLetter = true;
          j = tapeAlphabet.size();
        }
      }
      i++;
    }
    else cascadingError = true;
    
    //check that desination state is in states
    bool validDestinationState = false;
    std::string destinationState = transitionFunctionStrings[i];
    
    
    if (i < transitionFunctionStrings.size())
    {
      for(size_t j = 0; j < transitionFunctionStrings.size(); j++)
      {
        if (destinationState == transitionFunctionStrings[j])
        {
          validDestinationState = true;
          j = transitionFunctionStrings.size();
        }
      }
      i++;
    }
    else cascadingError = true;
    
    
    //check that write letter is in tapeAlphabet
    bool validWriteLetter = false;
    std::string writeLetter = transitionFunctionStrings[i];
    
    
    if (i < transitionFunctionStrings.size())
    {
      for(size_t j = 0; j < tapeAlphabet.size(); j++)
      {
        if (writeLetter == tapeAlphabet[j])
        {
          validWriteLetter = true;
          j = tapeAlphabet.size();
        }
      }
      i++;
    }
    else cascadingError = true;
    
    
    //check that direction is a valid direction
    bool validDirection = false;
    std::string direction = transitionFunctionStrings[i];
    
    
    if (i < transitionFunctionStrings.size())
    {
      if(direction == "l" || direction == "L" || direction == "r" || direction == "R")
      {
        validDirection= true;
      }
      i++;
    }
    else cascadingError = true;
    
    
    if(validCurrentState &&  !currentStateIsFinalState && validReadLetter && validDestinationState && validWriteLetter && validDirection)
    {
      transitionFunction.push_back(Transition(currentState, readLetter[0], writeLetter[0], destinationState, direction[0]));
    }
    else
    {
      std::cout << "ERROR: in transition \u03B4(" << currentState << ", " << readLetter << ") = { " << destinationState << ", " << writeLetter << ", " << direction << " }" << std::endl;
      if(!validCurrentState)
      {
        std::cout << "\t" << currentState << " undeclared in states:" << std::endl;
        errors++;
      }
      if(currentStateIsFinalState)
      {
        std::cout << "\t" << currentState << " is a final state, must not transition out of a final state" << std::endl;
        errors++;
      }
      if(!validReadLetter)
      {
        std::cout << "\t" << validReadLetter << " undeclared in tape_alphabet:" << std::endl;
        errors++;
      }
      if(!validDestinationState)
      {
        std::cout << "\t" << destinationState << " undeclared in states:" << std::endl;
        errors++;
      }
      if(!validWriteLetter)
      {
        std::cout << "\t" << writeLetter << " undeclared in tape_alphabet:" << std::endl;
        errors++;
      }
      if(!validDirection)
      {
        std::cout << "\t" << direction << " is not a valid direction, must be 'R' or 'L'" << std::endl;
        errors++;
      }
      
      std::cout << std::endl;
      
      if(cascadingError)
      {
        std::cout << "\n CRITICAL ERROR: PART(S) MISSING FROM TRANSITION(S), LIKELY CAUSED CASCADING ERRORS" << std::endl;
        errors++;
      }
    }
    
    totalErrors += errors;
  }
  return totalErrors;
}
