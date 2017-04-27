#ifndef Tape_hpp
#define Tape_hpp

#include "Direction.hpp"

#include <string>

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
