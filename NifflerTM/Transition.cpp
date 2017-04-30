#include "Transition.hpp"

#include <string>
#include <iostream>


Transition::Transition(const std::string& currentState_in, char& readCharacter_in, char& writeCharacter_in, std::string& destinationState_in, char& move_in):
currentState(currentState_in),
readCharacter(readCharacter_in),
writeCharacter(writeCharacter_in),
destinationState(destinationState_in),
move(move_in)
{}


std::string Transition::getCurrentState() const
{
    return currentState;
}

char Transition::getReadCharacter() const
{
    return readCharacter;
}

char Transition::getWriteCharacter() const
{
    return writeCharacter;
}

std::string Transition::getDestinationState() const
{
    return destinationState;
}

const char Transition::getDirection() const
{
    return move;
}

void Transition::printFunction()
{
  std::cout << "\u03B4( " << currentState << ", " << readCharacter << " ) = { " << writeCharacter << ", " << destinationState << ", " << move << " }" << std::endl;
}
