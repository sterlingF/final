#ifndef __GUESS_HPP__
#define __GUESS_HPP__
#include <string>
#include <iostream>
#include <cstring>

class Guess{
public:
    std::string place;
    std::string ourguess;
    Guess(std::string word, std::string guess): place(word), ourguess(guess) {};
    
    
    
    bool guess_correct(){
        for(int i = 0; i < place.size(); i++){
            char* b = new char(ourguess.length()+1);
            std::strcpy(b, ourguess.c_str());
            if(*b == place.at(i)){
                return true;
            }
        }
        
        return false;
    }
    
};
#endif
