#ifndef __MAN_HPP__
#define __MAN_HPP__
#include <iostream>
#include <string> 
using namespace std; 

	class Man{
		private:
		bool complete; 
		char last = ' ';
		public:
			Man(): complete(false){};
//			bool check_complete(); 
//			void draw(); 

bool check_complete(){
//false when NOT COMPLETE
	if(last != 'o'){	
		return false;
 	}	
	else if(last == 'o'){
		return true;
	}
}
void draw(){
	if(last == ' '){
		cout << 'o' << endl; 
		last = 'o';
	}
	else if(last == 'o'){
		cout << endl << 'o' << endl << '-' << endl; 
		last = '/'; 
	}
	else if(last == '/'){
		cout << endl << 'o' << endl << '-' << '|' << endl; 
		last == '|';
	}
	else if(last == '|'){
		cout << endl << 'o' << endl << '-' << '|' << "-" << endl;
		last == 'l'; 
	}
	else if(last == 'l'){
		cout << endl << 'o' << endl << '-' << '|' << "-" << endl; 
			last = 'r';
	}
	else if(last == 'r'){
		cout << endl << 'o' << endl << 'l' << '|' << "l" << endl << '/' << endl; 
			last = 'g';
	}
	else if(last == 'g'){
		cout << endl << 'o' << endl << '-' << '|' << "-" << endl << 'l' << ' ' << 'l' << endl; 
		last = 'o'; 
	}
}
}; 
#endif // __MAN_HPP__
