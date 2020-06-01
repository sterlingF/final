//#include "main.cpp"
#include "man.hpp"
#include "emptyboard.hpp" 
#include "fullboard.hpp" 
#include "board.hpp" 
#include <iostream>
#include "gtest/gtest.h"
#include "guess.hpp" 



TEST(emptyboard, HelloWorld) {
	std::string word = "helloworld"; 
        emptyboard* newboard = new emptyboard(word); 
	newboard->draw_board(); 
	std::vector<std::string> test; 
	for(int i = 0; i < 10; i++){
		test.push_back(" _ "); 
	}
	EXPECT_EQ(newboard->returnvec(), test);
}

TEST(fullboard, HelloWorld) {
        std::string word = "helloworld";
        emptyboard* newboard = new emptyboard(word);
        newboard->draw_board();

	std::vector<std::string> holding = newboard->returnvec(); 
	std::string guess = "h"; 

	fullboard* newboard2 = new fullboard(word, guess, holding); 
	newboard2->draw_board(); 	

        std::vector<std::string> test;
	test.push_back("h"); 
        for(int i = 0; i < 9; i++){
                test.push_back(" _ ");
        }
        EXPECT_EQ(newboard2->returnvec(), test);
}


TEST(fullboard, HelloWorldL) {
        std::string word = "helloworld";
        emptyboard* newboard = new emptyboard(word);
        newboard->draw_board();

        std::vector<std::string> holding = newboard->returnvec();
        std::string guess = "l";

        fullboard* newboard2 = new fullboard(word, guess, holding);
        newboard2->draw_board();

        std::vector<std::string> test;
        test.push_back(" _ ");
	test.push_back(" _ ");
	test.push_back("l");
	test.push_back("l"); 
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back("l");
        test.push_back(" _ ");

        EXPECT_EQ(newboard2->returnvec(), test);
}


TEST(fullboard, randword) {
        std::string word = "randword";
        emptyboard* newboard = new emptyboard(word);
        newboard->draw_board();

        std::vector<std::string> holding = newboard->returnvec();
        std::string guess = "d";

        fullboard* newboard2 = new fullboard(word, guess, holding);
        newboard2->draw_board();

        std::vector<std::string> test;
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back("d");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back("d");

        EXPECT_EQ(newboard2->returnvec(), test);
}


TEST(fullboard, cellphone) {
        std::string word = "cellphone";
        emptyboard* newboard = new emptyboard(word);
        newboard->draw_board();

        std::vector<std::string> holding = newboard->returnvec();
        std::string guess = "d";

        fullboard* newboard2 = new fullboard(word, guess, holding);
        newboard2->draw_board();

        std::vector<std::string> test;
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
        test.push_back(" _ ");
	test.push_back(" _ "); 
        EXPECT_EQ(newboard2->returnvec(), test);
}

TEST(Guess, g){
	std::string word = "gross"; 
	std::string userguess = "g"; 
	Guess* newguess = new Guess(word, userguess); 
	EXPECT_EQ(newguess->guess_correct(), true); 
}


TEST(Guess, notwithin){
        std::string word = "nope";
        std::string userguess = "g";
        Guess* newguess = new Guess(word, userguess);
        EXPECT_EQ(newguess->guess_correct(), false);
}


TEST(Guess, CAPS){
        std::string word = "Nope";
        std::string userguess = "N";
        Guess* newguess = new Guess(word, userguess);
        EXPECT_EQ(newguess->guess_correct(), true);
}


TEST(Guess, notwithin2){
        std::string word = "nope";
        std::string userguess = "N";
        Guess* newguess = new Guess(word, userguess);
        EXPECT_EQ(newguess->guess_correct(), false);
}


TEST(Guess, doublewithin){
        std::string word = "book";
        std::string userguess = "o";
        Guess* newguess = new Guess(word, userguess);
        EXPECT_EQ(newguess->guess_correct(), true);
}

TEST(Man, onewrong) {
	std::string word = "cat";
	std::string userguess = "p";
	Man* newman = new  Man();
	newman->draw();
	EXPECT_EQ(newman->pic(), " o");
} 

TEST(Man, threewrong) {
	std::string word = "wrong";
	std::string userguess = "p";
	Guess* newguess = new Guess(word, userguess);
	Man* newman = new  Man();
	if(newguess->guess_correct() == false) {
		newman->draw();	
	}
	userguess = "r";
	newguess = new Guess(word, userguess);
	if(newguess->guess_correct() == false) {
                newman->draw();
        }
	userguess = "f";
	newguess = new Guess(word, userguess);
	if(newguess->guess_correct() == false) {
                newman->draw();
        }
	userguess = "b";
        newguess = new Guess(word, userguess);
        if(newguess->guess_correct() == false) {
                newman->draw();
        }
        EXPECT_EQ(newman->pic(), "-");
}

TEST(Man, notcomplete) {
	Man* man = new Man();
	man->draw();
	man->draw();
	man->draw();
	EXPECT_EQ(man->check_complete(), false);
}

TEST(Man, complete) {
	Man* man = new Man();
        for(int i = 0; i < 6; i++) {
		man->draw();
	}
        EXPECT_EQ(man->check_complete(), true);
}

TEST(main, program) {
	
	std::string test = "";
	std::string word = "cat";
	emptyboard* newboard = new emptyboard(word);
        newboard->draw_board();

        std::vector<std::string> holding = newboard->returnvec();
        std::string guess = "h";
	
	fullboard* newboard2 = new fullboard(word, guess, holding);
        Guess* newguess = new Guess(word, guess);	
	Man* newman = new  Man();
        if(newguess->guess_correct() == false) {
                newman->draw();
        }
	else {
		newboard2->draw_board();
		test = test + guess;	
	}	

	holding = newboard2->returnvec();
	guess = "c";
	newboard2 = new fullboard(word, guess, holding);
        newguess = new Guess(word, guess); 
        if(newguess->guess_correct() == false) {
                newman->draw();
        }
        else {
                newboard2->draw_board();
		test = test + guess;
        }
	
        guess = "a";
        newboard2 = new fullboard(word, guess, holding);
        newguess = new Guess(word, guess);
        if(newguess->guess_correct() == false) {
                newman->draw();
        }
        else {
                newboard2->draw_board();
		test = test + guess;
        }

	guess = "t";
        newboard2 = new fullboard(word, guess, holding);
        newguess = new Guess(word, guess);
        if(newguess->guess_correct() == false) {
                newman->draw();
        }
        else {
		newboard2->draw_board();
		test = test + guess;
        }
            	                                                                                 	
	
	EXPECT_EQ(test, word);  
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
