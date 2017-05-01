#include "Tape.hpp"

#include <string>
#include <iostream>

Tape::Tape()
{
  cells = "";
  currentCell = 0;
}

void Tape::initialize(std::string inputString)
{
  cells = inputString;
  currentCell = 0;
}
void Tape::update(char writeCharacter, const char moveDirection)
{
  cells[currentCell] = writeCharacter;
  if (moveDirection == 'r' || moveDirection == 'R')
  {
    currentCell++;
  }
  else
    currentCell--;
}
char Tape::readCharacter()
{
  char ret_char = cells[currentCell];
  return ret_char;
}
bool Tape::isFirstCell()
{
  bool isFirstCell = false;
  if (currentCell == 0)
    isFirstCell = true;
  return isFirstCell;
}
bool Tape::isLastCell()
{
  bool isLastCell = false;
  if (currentCell == cells.length() - 1)
    isLastCell = true;
  return isLastCell;
}
void Tape::appendBlank(char blankCharacter)
{
  std::string temp(" ");
  temp = blankCharacter;
  cells += temp;
}
std::string Tape::left(int maxCellsNumber)
{
  long beginningCell = 0;
  if (0 < currentCell - maxCellsNumber)
  {
    beginningCell = currentCell - maxCellsNumber;
  }
  
  
  std::string leftString = cells.substr(beginningCell, currentCell - beginningCell);
  
  if (leftString.length() < currentCell)
  {
    leftString.insert(0, "<");
  }
  return leftString;
}
std::string Tape::right(int maxCellsNumber, char blankCharacter)
{
  long endCell = cells.length();
  endCell--;
  while ((endCell >= currentCell) && (cells[endCell] == blankCharacter))
  {
    --endCell;
  }
  long lastCell = 0;
  if (endCell < currentCell + maxCellsNumber)
  {
    lastCell = endCell;
  }
  else
    lastCell = currentCell + maxCellsNumber;
  
  std::string rightString = cells.substr(currentCell, lastCell - currentCell + 1);
  if (rightString.length() < endCell - currentCell + 1)
  {
    rightString.append(">");
  }
  
  return rightString;
}
