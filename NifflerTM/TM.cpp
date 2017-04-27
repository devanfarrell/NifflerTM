#include "TM.hpp"
#include "Parser.hpp"
#include "TM_Definition.hpp"
#include "Validator.hpp"

#include <iostream>
#include <string>
#include <fstream>

bool TM::load(std::string fileName)
{
    
    std::ifstream rawDefinitionFile;
    std::cout << fileName << std::endl;
    std::string fileToOpen = fileName + ".def";
    rawDefinitionFile.open(fileToOpen);
    
    if(!hasLoaded)
    {
        if(rawDefinitionFile.is_open())
        {
            
            
            if (rawDefinitionFile.good())
            {
                Parser parser;
                Validator * validator = NULL;
                validator = parser.definitionParse(&rawDefinitionFile);
              bool validDefinition = validator->isValidDefinition();
                
                
                if (validDefinition)
                {
                    TM_Definition * tmDefinition = NULL;
                    Input_Strings * inputStrings = NULL;
                    
                    
                    tmDefinition = validator->constructDefinition();
                    inputStrings = validator->constructInputStrings();
                    validator->validateInputFile(fileName);
                    
                    tmOperation = new TM_Operation(validator, tmDefinition, inputStrings, fileName);
                    
                    
                    hasLoaded = true;
                }
                else
                {
                    delete validator;
                }
            }
            else
            {
                std::cout << "ERROR: File is empty or corrupted" <<  std::endl;
                hasLoaded = false;
            }
        }
        else
        {
            std::cout << "ERROR: Unable to open file '" << fileName << ".def'" << std::endl;
            hasLoaded = false;
        }
        
        rawDefinitionFile.close();
    }
    return hasLoaded;
}
void TM::commandLogic()
{
  bool exit = false;
  while( !exit )
  {
    std::cout << "Command: ";
    {
      std::string input;
      std::getline(std::cin, input);
      std::cout << std::endl;
      if(input == "d" || input == "D")       tmOperation->deleteStr();
      else if(input == "x" || input == "X")  exit = true;
      else if(input == "h" || input == "H")  tmOperation->help();
      else if(input == "i" || input == "I")  tmOperation->insert();
      else if(input == "l" || input == "L")  tmOperation->list();
      else if(input == "q" || input == "Q")  tmOperation->quit();
      else if(input == "r" || input == "R")  tmOperation->run();
      else if(input == "e" || input == "E")  tmOperation->set();
      else if(input == "w" || input == "W")  tmOperation->show();
      else if(input == "t" || input == "T")  tmOperation->truncate();
      else if(input == "v" || input == "V")  tmOperation->view();
      else                                   std::cout << "'" << input << "' is not a valid input" << std::endl;
    }
  }
}

  void TM::initiate()
  {
    commandLogic();
  }
