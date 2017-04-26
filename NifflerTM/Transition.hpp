//
//  Transition.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

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
    
    
    std::string getCurrentState() const;
    char getReadCharacter() const;
    char getWriteCharacter() const;
    std::string getDestinationState() const;
    direction getDirection() const;
    
};


#endif /* Transition_hpp */
