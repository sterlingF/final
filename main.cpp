#include <iostream>
#include <string> 
#include "board.hpp"
#include "guess.hpp" 
#include "emptyboard.hpp"
#include "man.hpp"  
#include "fullboard.hpp"
int main(){
//	char userguess; 

	std::cout << "This is a HANGMAN game. Guess the word before the man is fully drawn." <<std::endl; 
	//determine word. sample for now 
	std::string word = "helloworld"; 
	emptyboard* newboard = new emptyboard(word); 
	newboard->draw_board(); 
	std::string userguess; 
	std::cout << "Guess: " <<std::endl; 
	std::cin >> userguess;
	std::vector<std::string> holding = newboard->returnvec();  
	fullboard* newboard2 = new fullboard(word, userguess, holding); 
	Man* newman = new Man(); 
	int count = 0; 
	Guess* newguess = new Guess(word, userguess); 
	if(newguess->guess_correct() == true){
		newboard2->draw_board(); 
	}
	else{
		newman->draw(); 
	}
	holding = newboard2->returnvec();
	bool done = false;  
	while(done == false && count < 7){
		std::cout << "  Guess: " << std::endl; 
		std::cin >>userguess; 

		Guess* newguess2 = new Guess(word, userguess);
		fullboard* newboard3 = new fullboard(word, userguess, holding); 
        if(newguess2->guess_correct() == true){
                newboard3->draw_board();
        }
        else{
		count++;
                newman->draw();
        }
		holding = newboard3->returnvec();
		done = true;  
	for(int j = 0; j <holding.size(); j++){
		 
		if(holding.at(j) == " _ "){
			done = false; 
		}
	}
	
	if(done == true){
		std::cout << std::endl << "You won!" << std::endl; 	
	}
}
}
