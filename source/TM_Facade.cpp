#include "TM_Facade.hpp"

#include "TM_Facade.hpp"
#include "Input_Strings.hpp"
#include <iostream>
#include <sstream>

bool TM_Facade::getPosInt(int& result, std::string prompt)
{
  int ret_value = 0;
  bool validity = false;
  std::string input;
  std::cout << prompt; // print prompt
  std::getline(std::cin, input); // get string input
  std::istringstream buffer(input); // turns the input into a stream
  std::cin.clear(); // clears cin
  if (buffer >> ret_value && std::to_string(ret_value) == input
      && ret_value > 0) // check for garbage, truncation, and overflow
  {
    result = ret_value;
    validity = true;
  }
  else if (input.size() == 0)
  {
  }
  else
  {
    std::cout << "Error: input is not a positive integer" << std::endl;
  }
  return validity;
}


TM_Facade::TM_Facade(Validator* validator, TM_Definition* tmDefinition, Input_Strings* inputStrings,
                     std::string fileName)
: fileName(fileName)
{
  this->validator = validator;
  this->tmDefinition = tmDefinition;
  this->inputStrings = inputStrings;
  transitionProcessor = new Transition_Processor(inputStrings, tmDefinition);
}

TM_Facade::~TM_Facade()
{
  delete validator;
  delete transitionProcessor;
  delete inputStrings;
  delete tmDefinition;
  validator = NULL;
  transitionProcessor= NULL;
  inputStrings = NULL;
  tmDefinition = NULL;
}


void TM_Facade::deleteStr()
{
  int index = 0;
  bool validInput = getPosInt(index, "Input string number: ");
  if (validInput)
  {
    if (validInput && inputStrings->isString(index))
    {
      inputStrings->deleteString(index);
    }
    else
    {
      std::cout << "Error: string not in list" << std::endl;
    }
  }
}
void TM_Facade::help()
{
  std::cout << "D\t"
  << "DELETE\t\t"
  << "Delete input string from list" << std::endl;
  std::cout << "X\t"
  << "EXIT\t\t"
  << "Exit application " << std::endl;
  std::cout << "H\t"
  << "HELP\t\t"
  << "Help user" << std::endl;
  std::cout << "I\t"
  << "INSERT\t\t"
  << "Insert input string into list" << std::endl;
  std::cout << "L\t"
  << "LIST\t\t"
  << "List input strings" << std::endl;
  std::cout << "Q\t"
  << "QUIT\t\t"
  << "Quit operation of Turing machine on input string" << std::endl;
  std::cout << "R\t"
  << "RUN\t\t\t"
  << "Run Turing machine on input string" << std::endl;
  std::cout << "E\t"
  << "SET\t\t\t"
  << "Set maximum number of transitions to perform" << std::endl;
  std::cout << "W\t"
  << "SHOW\t\t"
  << "Show status of application" << std::endl;
  std::cout << "T\t"
  << "TRUNCATE\t"
  << "Truncate instantaneous description" << std::endl;
  std::cout << "V\t"
  << "VIEW\t\t"
  << "View Turing machine" << std::endl;
}
void TM_Facade::insert()
{
  std::cout << "Input string: ";
  std::string input;
  std::getline(std::cin, input);
  std::cin.clear();
  bool valid = false;
  if (input.length() > 0)
  {
    valid = validator->testInputString(input);
    if (valid)
    {
      bool isDuplicate = false;
      isDuplicate = inputStrings->isDuplicate(input);
      if (!isDuplicate)
      {
        std::cout << "String added to list!" << std::endl;
        inputStrings->appendString(input);
        inputStrings->manipulate();
      }
      else
        std::cout << "Error: string is a duplicate" << std::endl;
    }
    else
      std::cout << "Error: input string contains characters not in sigma" << std::endl;
  }
}
void TM_Facade::list()
{
  inputStrings->listStrings();
}
void TM_Facade::quit()
{
  transitionProcessor->quitOperation();
}

void TM_Facade::run()
{
  if (transitionProcessor->isOperating())
  {
    transitionProcessor->performTransitions();
  }
  else
  {
    int posInt = 0;
    bool validInput = getPosInt(posInt, "Select input string on which to operate: ");
    if (validInput)
    {
      if (inputStrings->isString(posInt))
      {
        transitionProcessor->initialize(posInt);
        transitionProcessor->performTransitions();
      }
      else
        std::cout << "Error: string not in list" << std::endl;
    }
  }
}
void TM_Facade::set()
{
  int posInt = 0;
  std::string prompt = "Set maximum number of transitions ["
  + std::to_string(transitionProcessor->getMaxTransitions()) + "]: ";
  bool validInput = getPosInt(posInt, prompt);
  if (validInput)
  {
    transitionProcessor->setMaxTransitions(posInt);
    std::cout << "Maximum set to " << posInt << std::endl;
  }
}
void TM_Facade::show()
{
  std::cout << "COURSE: Computer Science 322: Software Engineering" << std::endl;
  std::cout << "SEMESTER: Spring" << std::endl;
  std::cout << "YEAR: 2017" << std::endl;
  std::cout << "INSTRUCTOR: Neil Corrigan" << std::endl;
  std::cout << "AUTHOR: Devan Farrell" << std::endl;
  std::cout << "VERSION: 1.0.0" << std::endl;
  transitionProcessor->showConfigurationSettings();
  std::cout << "TM name: " << fileName << std::endl;
  transitionProcessor->showTMStatus();
}
void TM_Facade::truncate()
{
  int posInt = 0;
  std::string prompt = "Set maximum number of cells ["
  + std::to_string(transitionProcessor->getMaxCells()) + "]: ";
  bool validInput = getPosInt(posInt, prompt);
  if (validInput)
  {
    transitionProcessor->setMaxCells(posInt);
    std::cout << "Maximum set to " << posInt << std::endl;
  }
}
void TM_Facade::view()
{
  tmDefinition->view_definition();
}

void TM_Facade::exit()
{
  inputStrings->save(fileName);
}
