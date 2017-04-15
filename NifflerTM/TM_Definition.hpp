//
//  TM_Definition.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef TM_Definition_hpp
#define TM_Definition_hpp

#include "Transition.hpp"

#include <string>
#include <vector>

class TM_Definition
{
private: //attributes
    
    std::vector<std::string> description;
    std::vector<std::string> states;
    std::vector<char> inputAlphabet;
    std::vector<char> tapeAlphabet;
    std::vector<Transition> transitionFunction;
    std::vector<std::string> initialState;
    char blankCharacter;
    std::vector<std::string> finalStates;
    
    
public: //methods
    
    
    ///// begin contructor /////
    TM_Definition(
              std::vector<std::string> description,
              std::vector<std::string> states,
              std::vector<std::string> inputAlphabet,
              std::vector<std::string> tapeAlphabet,
              std::vector<Transition> transitionFunction,
              std::vector<std::string> initialState,
              std::vector<std::string> blankCharacter,
              std::vector<std::string> finalStates):
    description(description),
    states(states),
    transitionFunction(transitionFunction),
    initialState(initialState),
    finalStates(finalStates)
    {
       // inputAlphabet(inputAlphabet),
       // tapeAlphabet(tapeAlphabet),
       // blankCharacter(blankCharacter),
    }
    ///// end constructor /////
    
    
    
    void view_definition();
    bool isInputLetter(char testCharacter);
    bool isFinalState(std::string currentState);
    std::string getInitialState( ) const;
    char getBlankCharacter() const;
    bool search_transition( std::string sourceState, char readCharacter, std::string &destinationState, char &writeCharacter, char moveDirection) const;
    
};


#endif /* TM_Definition_hpp */
