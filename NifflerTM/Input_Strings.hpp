//
//  Input_Strings.hpp
//  NifflerTM
//
//  Created by Devan Farrell on 4/14/17.
//  Copyright © 2017 Devan Farrell. All rights reserved.
//

#ifndef Input_Strings_hpp
#define Input_Strings_hpp

#include <vector>
#include <string>

class Input_Strings
{
private: //attributes
    std::vector<std::string> inputStrings;
    
public: //methods
    
    void appendString(std::string string);
    bool deleteString(int index);
    void listStrings();
    bool isDuplicate(std::string string);
    bool isString(int index);
    std::string getString(int index);
};

#endif /* Input_Strings_hpp */
