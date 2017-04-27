#include "TM_Operation.hpp"
#include "Input_Strings.hpp"
#include <iostream>
#include <sstream>

void TM_Operation::deleteStr()
{
  int index = 0;
  getInt(1, index, "Input string number: ");
    if(inputStrings->isString(index))
       {
         inputStrings->deleteString(index);
       }
    else
    {
      std::cout << "Error: string not in list" << std::endl;
    }
}
void TM_Operation::help()
{
  std::cout << std::endl;
  std::cout << "(D)ELETE\t Delete input string from list" << std::endl;
  std::cout << " E(X)IT\t\t Exit application " << std::endl;
  std::cout << "(H)ELP\t\t Help user" << std::endl;
  std::cout << "(I)NSERT\t Insert input string into list" << std::endl;
  std::cout << "(L)IST\t\t List input strings" << std::endl;
  std::cout << "(Q)UIT\t\t Quit operation of Turing machine on input string" << std::endl;
  std::cout << "(R)UN\t\t Run Turing machine on input string" << std::endl;
  std::cout << " S(E)T\t\t Set maximum number of transitions to perform" << std::endl;
  std::cout << " SHO(W)\t\t Show status of application" << std::endl;
  std::cout << "(T)RUNCATE\t Truncate instantaneous description" << std::endl;
  std::cout << "(V)IEW\t\t View Turing machine" << std::endl << std::endl;
}
void TM_Operation::insert()
{
    
}
void TM_Operation::list()
{
  inputStrings->listStrings();
}
void TM_Operation::quit()
{
    
}
void TM_Operation::run()
{
    
}
void TM_Operation::set()
{
    
}
void TM_Operation::show()
{
    
}
void TM_Operation::truncate()
{
    
}
void TM_Operation::view()
{
  tmDefinition->view_definition();
}
       
bool TM_Operation::getPosInt( int&result, std::string prompt)
{
  int ret_value;
  std::string strNumber;
  std::string input;
  std::cout << prompt;
  std::getline(std::cin, input); //get string input
  std::cout << input << std::endl;
  std::istringstream buffer(input); //turns the input into a stream
  if(buffer >> ret_value && std::to_string(ret_value) == input && ret_value > 0)
  {
    result = ret_value;
    return true;
  }
  else
  {
  std::cout << "Error: input was not a positive integer" << std::endl;
  return false;
  }
}
