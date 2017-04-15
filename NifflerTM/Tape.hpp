//
//  Tape.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef Tape_hpp
#define Tape_hpp

#include "Direction.hpp"

#include <String>

class Tape
{
private: //attributes
    std::string cells;
    unsigned int currentCell;
    
public: //methods
    void initialize(std::string inputString);
    void update(char writeCharacter, direction moveDirection);
    char readCharacter();
    bool isFirstCell();
    bool isLastCell();
    void appendBlank(char blankCharacter);
    std::string left(unsigned int maxNumberCells);
    std::string right(unsigned int maxNumberCells);
};

#endif /* Tape_hpp */
