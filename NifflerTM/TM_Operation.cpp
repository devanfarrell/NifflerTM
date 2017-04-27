#include "TM_Operation.hpp"
#include "Input_Strings.hpp"
#include <iostream>
#include <sstream>

void TM_Operation::deleteStr()
{
  int index = 0;
  getInt(1, index, "Input string number:");
    if(inputStrings->isString(index))
       {
         inputStrings->deleteString(index);
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
       
bool TM_Operation::getInt(int min, int&result, std::string prompt)
{
  int ret_integer;
  std::string str_number;

  std::cout << prompt;
  std::getline(std::cin, str_number); //get string input
  std::stringstream convert(str_number); //turns the string into a stream
    
  //checks for complete conversion to integer and checks for minimum value
  if(convert >> ret_integer && !(convert >> str_number) && ret_integer >= min)
  {
    result = ret_integer;
    return true;
  }
  std::cin.clear(); //just in case an error occurs with cin (eof(), etc)
  std::cerr << "Input must be >= " << min << std::endl;
  return false;
}
