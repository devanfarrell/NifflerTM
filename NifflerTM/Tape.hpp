#ifndef Tape_hpp
#define Tape_hpp

#include <string>

class Tape
{
private: //attributes
    std::string cells;
    long currentCell;
    
public: //methods
    Tape();
    void initialize(std::string inputString);
    void update(char writeCharacter, char moveDirection);
    char readCharacter();
    bool isFirstCell();
    bool isLastCell();
    void appendBlank(char blankCharacter);
    std::string left( int maxCellsNumber);
    std::string right( int maxCellsNumber, char blankCharacter);
};

#endif /* Tape_hpp */
