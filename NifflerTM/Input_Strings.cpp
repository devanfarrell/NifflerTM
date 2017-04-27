#include "Input_Strings.hpp"

#include <iostream>

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
    inputStrings.erase(inputStrings.begin()+index);
  }
  return true;
}
void Input_Strings::listStrings()
{
  for(std::string::size_type i = 0; i < inputStrings.size(); i++)
  {
    std::cout << "[" << i+1 << "] " << inputStrings[i] << std::endl;
  }
}
bool Input_Strings::isDuplicate(std::string validatedString)
{
  bool found = false;
  for(std::string::size_type i = 0; i < inputStrings.size(); i++)
  {
      if(validatedString == inputStrings[i])
      {
        std::cout << "input string '" << validatedString << "' is a duplicate" << std::endl;
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
    return inputStrings[index];
}
