#ifndef __MAN_HPP__
#define __MAN_HPP__
#include <iostream>
#include <string>
using namespace std;

class Man{
private:
    bool complete = false;
    string last = " ";
public:
    Man(){};
    //            bool check_complete();
    //            void draw();
    
    bool check_complete(){
        //false when NOT COMPLETE
        if(last != " o"){
            complete = false;;
        }
        else if(last == " o"){
            complete =  true;
        }
        return complete;
    }
    
    
    void draw(){
        if(last == " "){
            cout << " o" << endl;
            last = " o";
        }
        else if(last == " o"){
            cout << endl << " o" << endl << "-" << endl;
            last = "|";
        }
        else if(last == "|"){
            cout << endl << " o" << endl << "-"  << "|" << endl;
            last = "-";
        }
        else if(last == "-"){
            cout << endl << " o" << endl << "-"  << "|" << "-" << endl;
            last = "/";
        }
        else if(last == "/"){
            cout << endl << " o" << endl << "-"  << "|" << "-" << endl << "/" << endl;
            last = " \\";
        }
        else if(last == " \\"){
            cout << endl << " o" << endl << "-"  << "|" << "-" << endl << "/" << " \\" << endl;
            last = " o";
        }
        /*   else if(last == 'g'){
         cout << endl << 'o' << endl << '-' << '|' << "-" << endl << 'l' << ' ' << 'l' << endl;
         last = 'o';
         }*/
    }


    //for testing purposes
    string pic() {
	return last;	
    }   
	
};
#endif // __MAN_HPP__
