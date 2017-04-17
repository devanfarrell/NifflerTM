//
//  TM.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

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
    rawDefinitionFile.open(fileName);
    
    if(!hasLoaded)
    {
        if(rawDefinitionFile.is_open())
        {
            
            
            if (rawDefinitionFile.good())
            {
                Parser parser;
                Validator * validator;
                validator = parser.definitionParse(&rawDefinitionFile);
                
                
                if (validator->isValidDefinition())
                {
                    TM_Definition * tmDefinition;
                    Input_Strings * inputStrings;
                    
                    
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

void TM::initiate()
{
    
}
