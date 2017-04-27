//
//  Transition.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

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

direction Transition::getDirection() const
{
    return move;
}
