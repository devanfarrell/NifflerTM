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
    std::string initialState;
    char blankCharacter;
    std::vector<std::string> finalStates;
    
    
public: //methods
    
    
    ///// begin contructor /////
    TM_Definition(
                  std::vector<std::string> description_in,
                  std::vector<std::string> states_in,
                  std::vector<std::string> inputAlphabet_in,
                  std::vector<std::string> tapeAlphabet_in,
                  std::vector<Transition> transitionFunction_in,
                  std::vector<std::string> initialState_in,
                  std::vector<std::string> blankCharacter_in,
                  std::vector<std::string> finalStates_in);
    ///// end constructor /////
    
    
    
    void view_definition();
    bool isInputLetter(char testCharacter);
    bool isFinalState(std::string currentState);
    std::string getInitialState( ) const;
    char getBlankCharacter() const;
    bool searchTransition( std::string sourceState, char readCharacter, std::string &destinationState, char &writeCharacter, char &moveDirection) const;
  
};


#endif /* TM_Definition_hpp */
