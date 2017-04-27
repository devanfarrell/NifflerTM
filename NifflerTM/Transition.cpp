#include "Transition.hpp"
#include "Direction.hpp"

#include <string>


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

Direction Transition::getDirection() const
{
    return move;
}
