#ifndef Transition_hpp
#define Transition_hpp

#include <string>


class Transition
{
private:
  std::string currentState;
  char readCharacter;
  char writeCharacter;
  std::string destinationState;
  const char move;
  
  
public:
  // copy constructor
  Transition(const std::string& currentState_in, char& readCharacter_in, char& writeCharacter_in,
             std::string& destinationState_in, char& move_in);
  
  std::string getCurrentState() const;
  char getReadCharacter() const;
  char getWriteCharacter() const;
  std::string getDestinationState() const;
  const char getDirection() const;
  void printFunction();
};


#endif /* Transition_hpp */
