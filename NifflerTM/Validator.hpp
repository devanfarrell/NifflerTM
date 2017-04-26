//
//  Validator.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef Validator_hpp
#define Validator_hpp

#include "Transition.hpp"
#include "TM_Definition.hpp"
#include "Input_Strings.hpp"

#include <string>
#include <vector>

class Validator
{
    
private: // associations
    Input_Strings * inputStrings;
    
private: // attributes
    
    std::vector<std::string> description;
    std::vector<std::string> states;
    std::vector<std::string> inputAlphabet;
    std::vector<std::string> tapeAlphabet;
    std::vector<std::string> transitionFunctionStrings;
    std::vector<Transition> transitionFunction;
    std::vector<std::string> initialState;
    std::vector<std::string> blankCharacter;
    std::vector<std::string> finalStates;
    std::vector<int> keywordOrder;
    
public: // methods
    
    ////////////// begin constructor /////////////
    Validator(
              std::vector<std::string> description,
              std::vector<std::string> states,
              std::vector<std::string> inputAlphabet,
              std::vector<std::string> tapeAlphabet,
              std::vector<std::string> transitionFunctionIn,
              std::vector<std::string> initialState,
              std::vector<std::string> blankCharacter,
              std::vector<std::string> finalStates,
              std::vector<int> keywordOrder):
    description(description),
    states(states),
    inputAlphabet(inputAlphabet),
    tapeAlphabet(tapeAlphabet),
    transitionFunctionStrings(transitionFunctionIn),
    initialState(initialState),
    blankCharacter(blankCharacter),
    finalStates(finalStates),
    keywordOrder(keywordOrder)
    {
        
    }
    ////////////// end constructor /////////////
    
    
    bool isValidDefinition();
    TM_Definition * constructDefinition();
    Input_Strings * constructInputStrings();
    void validateInputFile(std::string fileName);
    void testInputString(std::string inputString);
    
};

#endif /* Validator_hpp */
