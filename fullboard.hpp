#ifndef __FULLBOARD_HPP
#define __FULLBOARD_HPP
#include <iostream>
#include <string>
#include "board.hpp"
#include <vector>
#include <cstring>
	class fullboard: public Board{
		public: 
		std::string size; 
		std::string usguess; 
		std::vector<std::string> val; 
		fullboard(std::string word, std::string guess, std::vector<std::string> v): Board(), size(word), usguess(guess), val(v){}
		//std::vector<std::string> hold; 



std::vector<std::string> returnvec(){
        return val;
}

void draw_board(){
	for(int i = 0; i < size.size(); i++){
		char* b = new char(usguess.length()+1); 
		std::strcpy(b, usguess.c_str()); 
		if(size.at(i) == *b){
			val.at(i) = *b; 
		}
	}
	for(int i = 0; i < val.size(); i++){
		std::cout << val.at(i); 

	}
	returnvec(); 
}

};



#endif 
