#include "Transition_Processor.hpp"

#include <iostream>

Transition_Processor::Transition_Processor(Input_Strings* inputStrings, TM_Definition* tmDefinition)
{
  this->inputStrings = inputStrings;
  this->tmDefinition = tmDefinition;
  tape = new Tape;
  
  used = false;
  operating = false;
  accepted = false;
  rejected = false;
  maxCells = 32;
  maxTransitions = 1;
  totalTransitions = 0;
  currentState = "";
  originalInputString = "";
}
Transition_Processor::~Transition_Processor()
{
  delete tape;
  tape = NULL;
}


void Transition_Processor::transitionUpdate(
                                            std::string desitinationState, char writeCharacter, char moveDirection)
{
  currentState = desitinationState;
  tape->update(writeCharacter, moveDirection);
  totalTransitions++;
  if (tmDefinition->isFinalState(currentState))
    accept();
}

void Transition_Processor::viewInstantaneousDescription()
{
  std::cout << totalTransitions << ". ";
  std::cout << tape->left(maxCells) << "[";
  std::cout << currentState << "]";
  std::cout << tape->right(maxCells, tmDefinition->getBlankCharacter()) << std::endl;
}

void Transition_Processor::reject()
{
  operating = false;
  rejected = true;
  viewInstantaneousDescription();
  std::cout << "'" << originalInputString << "' was rejected in " << totalTransitions;
  if (totalTransitions > 1)
    std::cout << " transitions" << std::endl;
  else
    std::cout << " transition" << std::endl;
}

void Transition_Processor::accept()
{
  operating = false;
  accepted = true;
  viewInstantaneousDescription();
  std::cout << "'" << originalInputString << "' was accepted in " << totalTransitions;
  if (totalTransitions > 1)
    std::cout << " transitions" << std::endl;
  else
    std::cout << " transition" << std::endl;
}

bool Transition_Processor::isOperating() const
{
  return operating;
}
void Transition_Processor::performTransitions()
{
  for (int i = 0; i < maxTransitions && operating; i++)
  {
    std::string destinationState = "";
    char writeCharacter;
    char moveDirection;
    char readCharacter = tape->readCharacter();
    bool foundTransition = tmDefinition->searchTransition(
                                                          currentState, readCharacter, destinationState, writeCharacter, moveDirection);
    
    
    if (foundTransition && (moveDirection == 'l' || moveDirection == 'L'))
    {
      if (tape->isFirstCell())
        reject();
      else
        transitionUpdate(destinationState, writeCharacter, moveDirection);
    }
    else if (foundTransition && (moveDirection == 'r' || moveDirection == 'R'))
    {
      if (tape->isLastCell())
      {
        tape->appendBlank(tmDefinition->getBlankCharacter());
        transitionUpdate(destinationState, writeCharacter, moveDirection);
      }
      else
        transitionUpdate(destinationState, writeCharacter, moveDirection);
    }
    else
      reject();
  }
  if (operating)
  {
    viewInstantaneousDescription();
  }
}
void Transition_Processor::showConfigurationSettings()
{
  std::cout << "CONFIGURATION SETTINGS:" << std::endl;
  std::cout << "\tMax number of transitions: " << maxTransitions << std::endl;
  std::cout << "\tMax number of cells to the left and right of the tape head: " << maxCells
  << std::endl;
}
void Transition_Processor::showTMStatus()
{
  if (!used)
    std::cout << "TM has not operated on an input string" << std::endl;
  else
  {
    if (!operating)
    {
      std::cout << "TM has completed operation on an input string" << std::endl;
      std::cout << "Input string '" << originalInputString;
      if (!accepted && !rejected)
        std::cout << "' was not accepted or rejected in ";
      if (accepted && !rejected)
        std::cout << "' was accepted in ";
      if (!accepted && rejected)
        std::cout << "' was rejected in ";
      std::cout << totalTransitions;
      if (totalTransitions > 1)
        std::cout << " transitions" << std::endl;
      else
        std::cout << " transition" << std::endl;
    }
    else
    {
      std::cout << "Input string '" << originalInputString << "' has undergone "
      << totalTransitions;
      if (totalTransitions > 1)
        std::cout << " transitions" << std::endl;
      else
        std::cout << " transition" << std::endl;
    }
  }
}
void Transition_Processor::initialize(int index)
{
  std::string inputString = inputStrings->getString(index);
  originalInputString = inputString;
  if (inputString == "\\")
    inputString = tmDefinition->getBlankCharacter();
  tape->initialize(inputString);
  operating = true;
  accepted = false;
  rejected = false;
  used = true;
  currentState = tmDefinition->getInitialState();
  totalTransitions = 0;
  viewInstantaneousDescription();
}

void Transition_Processor::quitOperation()
{
  if (operating)
  {
    operating = false;
    std::cout << "'" << originalInputString << "' not accepted or rejected in "
    << totalTransitions;
    if (totalTransitions > 1)
      std::cout << " transitions" << std::endl;
    else
      std::cout << " transition" << std::endl;
  }
  else
  {
    std::cout << "ERROR: nothing to quit" << std::endl;
  }
}

int Transition_Processor::getMaxCells() const
{
  return maxCells;
}

void Transition_Processor::setMaxCells(unsigned int posInt)
{
  maxCells = posInt;
}

int Transition_Processor::getMaxTransitions() const
{
  return maxTransitions;
}

void Transition_Processor::setMaxTransitions(unsigned int posInt)
{
  maxTransitions = posInt;
}
