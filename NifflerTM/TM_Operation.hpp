#ifndef TM_Operation_hpp
#define TM_Operation_hpp


#include "Validator.hpp"
#include "Transition_Processor.hpp"
#include "Input_Strings.hpp"
#include "TM_Definition.hpp"


class TM_Operation
{
private: //attributes
    std::string fileName;
    Validator * validator;
    Transition_Processor * transitionProcessor;
    Input_Strings * inputStrings;
    TM_Definition * tmDefinition;
    
    
public:
    TM_Operation(Validator * validator, TM_Definition * tmDefinition, Input_Strings * inputStrings, std::string fileName)
    {
        this->validator = validator;
        this->tmDefinition = tmDefinition;
        this->inputStrings = inputStrings;
        this->fileName = fileName;
        transitionProcessor = new Transition_Processor(inputStrings, tmDefinition);
    }
    ~TM_Operation()
    {
        delete validator;
        delete transitionProcessor;
        delete inputStrings;
        delete tmDefinition;
    }
    
    void deleteStr();
    void exit();
    void help();
    void insert();
    void list();
    void quit();
    void run();
    void set();
    void show();
    void truncate();
    void view();
};

#endif /* TM_Operation_hpp */
