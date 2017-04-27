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
    TM()
    {
      tmOperation = NULL;
        hasLoaded = false;
    }
    
    ~TM()
    {
        if(hasLoaded)
        {
            delete tmOperation;
        }
    }
    
    bool load(std::string fileName);
    void initiate();
};

#endif /* TM_hpp */
