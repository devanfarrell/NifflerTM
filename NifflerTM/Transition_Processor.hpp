//
//  Transition_Processor.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef Transition_Processor_hpp
#define Transition_Processor_hpp

#include "Input_Strings.hpp"
#include "TM_Definition.hpp"
#include "Tape.hpp"

#include <string>



class Transition_Processor
{
private: // associations
    Input_Strings * inputStrings;
    TM_Definition * tmDefinition;
    Tape * tape;
    
    
private:
    std::string currentState;
    unsigned int totalNumberOfTransitions;
    std::string originalInputString;
    bool used;
    bool operating;
    bool accepted;
    bool rejected;
    unsigned int maxNumberOfCells;
    unsigned int transitionsPerRun;
    
private: // methods
    void viewInstantaneousDescription();
    
    
public: // methods
    
    Transition_Processor(Input_Strings * inputStrings, TM_Definition * tmDefinition)
    {
        this->inputStrings = inputStrings;
        this->tmDefinition = tmDefinition;
        tape = new Tape;
        
        used = false;
        operating = false;
        accepted = false;
        rejected = false;
        maxNumberOfCells = 32;
        transitionsPerRun = 1;
        totalNumberOfTransitions = 0;
        currentState = "";
        originalInputString = "";
    }
    ~Transition_Processor()
    {
        delete tape;
    }
    
    
    bool isOperating();
    void performTransitions();
    void showConfigurationSettings();
    void showTMStatus();
    void initialize(int inputStringIndex);
    void quitOperation();
    void setTransitions();
    void setMaxNumberTransitions();
    
};



#endif /* Transition_Processor_hpp */
