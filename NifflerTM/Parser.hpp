//
//  Parser.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include "Transition.hpp"
#include "Validator.hpp"

#include <string>
#include <vector>
#include <fstream>

class Parser
{

private: // attributes
    
    std::vector<std::string> description;
    std::vector<std::string> states;
    std::vector<std::string> inputAlphabet;
    std::vector<std::string> tapeAlphabet;
    std::vector< std::string> transitionFunction;
    std::vector<std::string> initialState;
    std::vector<std::string> blankCharacter;
    std::vector<std::string> finalStates;
    std::vector<int> keywordOrder;

    
private: // methods
    
    void descriptionParse(std::__1::ifstream * definitionFile);
    void statesParse(std::__1::ifstream * definitionFile);
    void inputAlphabetParse(std::__1::ifstream * definitionFile);
    void tapeAlphabetParse(std::__1::ifstream * definitionFile);
    void transitionFunctionParse(std::__1::ifstream * definitionFile);
    void initialStateParse(std::__1::ifstream * definitionFile);
    void blankCharacterParse(std::__1::ifstream * definitionFile);
    void finalStatesParse(std::__1::ifstream * definitionFile);
    void keywordOrderParse(std::__1::ifstream * definitionFile);

    
public: // methods
    
    Validator * definitionParse(std::__1::ifstream * definitionFile);

};
#endif /* Parser_hpp */
