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
    
}
void Parser::statesParse(std::__1::ifstream * definitionFile)
{
    
}
void Parser::inputAlphabetParse(std::__1::ifstream * definitionFile)
{
    
}
void Parser::tapeAlphabetParse(std::__1::ifstream * definitionFile)
{
    
}
void Parser::transitionFunctionParse(std::__1::ifstream * definitionFile)
{
    
}
void Parser::initialStateParse(std::__1::ifstream * definitionFile)
{
    
}
void Parser::blankCharacterParse(std::__1::ifstream * definitionFile)
{
    
}
void Parser::finalStatesParse(std::__1::ifstream * definitionFile)
{
    
}
void Parser::keywordOrderParse(std::__1::ifstream * definitionFile)
{
    
}


Validator * Parser::definitionParse(std::__1::ifstream * definitionFile)
{
   
    descriptionParse(definitionFile);
    statesParse(definitionFile);
    inputAlphabetParse(definitionFile);
    tapeAlphabetParse(definitionFile);
    transitionFunctionParse(definitionFile);
    initialStateParse(definitionFile);
    blankCharacterParse(definitionFile);
    finalStatesParse(definitionFile);
    keywordOrderParse(definitionFile);
    
    
    return NULL;
}
