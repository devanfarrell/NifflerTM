#ifndef Transition_hpp
#define Transition_hpp

#include "Direction.hpp"

#include <string>


class Transition
{
private:
    
    std::string currentState;
    char readCharacter;
    char writeCharacter;
    std::string destinationState;
    direction move;
    
    
public:
  //copy constructor
  Transition(const std::string& currentState_in, char& readCharacter_in, char& writeCharacter_in, std::string& destinationState_in, direction& move_in):
  currentState(currentState_in),
  readCharacter(readCharacter_in),
  writeCharacter(writeCharacter_in),
  destinationState(destinationState_in),
  move(move_in)
  {}
  
    std::string getCurrentState() const;
    char getReadCharacter() const;
    char getWriteCharacter() const;
    std::string getDestinationState() const;
    direction getDirection() const;
    
};


#endif /* Transition_hpp */
