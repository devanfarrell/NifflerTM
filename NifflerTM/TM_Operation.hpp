//
//  TM_Operation.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef TM_Operation_hpp
#define TM_Operation_hpp


#include "Validator.hpp"
#include "Transition_Processor.hpp"
#include "Input_Strings.hpp"
#include "TM_Definition.hpp"


class TM_Operation
{

private:
    
    Validator * validator;
    Transition_Processor * transitionProcessor;
    Input_Strings * inputStrings;
    TM_Definition * tmDefinition;
    
    
public:
    
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
