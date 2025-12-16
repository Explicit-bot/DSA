// WAP to get the name from user and print it
#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "May I know your name?";
    
    getline(cin ,name);
    cout<< "Welcome,"<<name<<"\n";

}
/*
    // std::cin >> name;
    can't use this coz 
    cin >> reads only until the first whitespace
    That includes:
	•	Space ' '
	•	Tab \t
	•	Newline \n
    •   '\r' (carriage return)
    for example if you take hello world as input 
    reads hello and leaves the rest (like "world") in the input buffer
    Use getline() to read the whole line
*/
