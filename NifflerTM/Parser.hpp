#ifndef Parser_hpp
#define Parser_hpp

#include "Transition.hpp"
#include "Validator.hpp"

#include <string>
#include <vector>
#include <fstream>

class Parser
{

private: // attributes
    
    std::vector<std::string> description;
    std::vector<std::string> states;
    std::vector<std::string> inputAlphabet;
    std::vector<std::string> tapeAlphabet;
    std::vector< std::string> transitionFunction;
    std::vector<std::string> initialState;
    std::vector<std::string> blankCharacter;
    std::vector<std::string> finalStates;
    std::vector<int> keywordOrder;

    
private: // methods
    
  void descriptionParse(std::ifstream  &definitionFile);
  void statesParse(std::ifstream  &definitionFile);
  void inputAlphabetParse(std::ifstream &definitionFile);
  void tapeAlphabetParse(std::ifstream &definitionFile);
  void transitionFunctionParse(std::ifstream &definitionFile);
  void initialStateParse(std::ifstream &definitionFile);
  void blankCharacterParse(std::ifstream &definitionFile);
  void finalStatesParse(std::ifstream &definitionFile);
  void keywordOrderParse(std::ifstream &definitionFile);

  
public: // methods
    
    Validator * definitionParse(std::__1::ifstream &definitionFile);

};
#endif /* Parser_hpp */
