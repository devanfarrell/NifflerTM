#ifndef Input_Strings_hpp
#define Input_Strings_hpp

#include <vector>
#include <string>

class Input_Strings
{
private: //attributes
    std::vector<std::string> inputStrings;
    bool manipulated;
  
public: //methods
  
    Input_Strings();
    void appendString(std::string validatedString);
    bool deleteString(int index);
    void listStrings();
    bool isDuplicate(std::string validatedString);
    bool isString(int index);
    std::string getString(int index);
    void manipulate();
    void save(std::string fileName);
};

#endif /* Input_Strings_hpp */
