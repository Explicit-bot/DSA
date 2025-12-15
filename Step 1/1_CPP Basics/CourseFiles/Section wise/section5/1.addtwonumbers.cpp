// WAP to take input and add two numbers
#include <iostream>
using namespace std;

int main(){
    int x{};
    int y{};
    int z{};

    cout<<"Enter two no.s:";   //So CP = No flush
    cin>>x>>y;

    z=x+y;

    cout<<"Sum of "<<x<<" and "<<y<<" is "<<z<<"."<<"\n";

    return 0;
}
/*
CP = No flush
So,No std::flush & std:endl  
Use \n wherever needed for new line.
*/
