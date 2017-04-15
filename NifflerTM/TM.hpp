//
//  TM.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef TM_hpp
#define TM_hpp

#include "TM_Operation.hpp"

#include <string>


class TM
{
private: //associations
    TM_Operation * tmOperation;
    
    
private: //attributes
    
    bool hasLoaded;
    
    
public: //methods
    bool load(std::string fileName);
    void initiate();
};

#endif /* TM_hpp */
