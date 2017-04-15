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
#include "Tape.hpp"

#include <string>



class Transition_Processor
{
private: // associations
    Input_Strings * inputStrings;
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
    
private:
    void viewInstantaneousDescription();
    
    
public:
    
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
