#ifndef __MAN_HPP__
#define __MAN_HPP__
#include <iostream>
#include <string>
using namespace std;

class Man{
private:
    bool complete;
    string last = " ";
public:
    Man(): complete(false){};
    //            bool check_complete();
    //            void draw();
    
    bool check_complete(){
        //false when NOT COMPLETE
        if(last != " o"){
            return false;
        }
        else if(last == " o"){
            return true;
        }
        return false;
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
};
#endif // __MAN_HPP__
