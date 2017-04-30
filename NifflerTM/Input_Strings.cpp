#include "Input_Strings.hpp"

#include <iostream>
#include <fstream>

Input_Strings::Input_Strings()
{
  manipulated = false;
}

void Input_Strings::appendString(std::string validatedString)
{
  if(!isDuplicate(validatedString))
  {
    inputStrings.push_back(validatedString);
  }
}
bool Input_Strings::deleteString(int index)
{
  if(isString(index))
  {
    inputStrings.erase(inputStrings.begin()+index - 1);
    manipulated = true;
    std::cout << "Input string deleted!" << std::endl;
  }
  return true;
}
void Input_Strings::listStrings()
{
  for(std::string::size_type i = 0; i < inputStrings.size(); i++)
  {
    std::cout << "[" << i+1 << "] " << inputStrings[i] << std::endl;
  }
  if(inputStrings.size() == 0)
  {
    std::cout << "List is empty" << std::endl;
  }
}
bool Input_Strings::isDuplicate(std::string validatedString)
{
  bool found = false;
  for(std::string::size_type i = 0; i < inputStrings.size(); i++)
  {
      if(validatedString == inputStrings[i])
      {
        found = true;
      }
  }
  return found;
}

bool Input_Strings::isString(int index)
{
  if(index <= inputStrings.size()) return true;
  else return false;
}

std::string Input_Strings::getString(int index)
{
  std::string retString = inputStrings[ (index - 1)];
  return retString;
}

void Input_Strings::manipulate()
{
  manipulated = true;
}

void Input_Strings::save(std::string fileName)
{
  if(manipulated)
  {
      std::ofstream inputStringFile;
    std::string fileToOpen = fileName + ".str";
    inputStringFile.open(fileToOpen);
    if(inputStringFile.is_open())
    {
      for(size_t i = 0; i < inputStrings.size(); i++)
      {
        inputStringFile << inputStrings[i] + "\n";
      }
      inputStringFile.close();
      std::cout << "Input string file successfully overwritten!" << std::endl;
    }
    else std::cout << "Error: Input string file failed to be overwritten!" << std::endl;
  }
}
