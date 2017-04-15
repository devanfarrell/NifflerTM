//
//  TM_Definition.cpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#include "TM_Definition.hpp"

void TM_Definition::view_definition()
{
    
}

bool TM_Definition::isInputLetter(char testCharacter)
{
    return true;
}

bool TM_Definition::isFinalState(std::string currentState)
{
    return true;
}

std::string TM_Definition::getInitialState( ) const
{
    return "initialState";
}

char TM_Definition::getBlankCharacter() const
{
    return '-';
}

bool TM_Definition::search_transition( std::string sourceState, char readCharacter, std::string &destinationState, char &writeCharacter, char moveDirection) const
{
    return true;
}
