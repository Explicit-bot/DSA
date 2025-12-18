/*   
Given an integer N, write a program to print your name N times.
*/


#include <iostream>
using namespace std;

//Kya bakwass likhi hai tune ye
/*
int cnt{};
void PrintN(int n){
    if(cnt==n){
        return;
    }
    cout<<"Hello,Duniya!\n";
    ++cnt;
    PrintN(n);
}
*/

//Good
void Print(int n){
    if(n==0){
        return;
    }
    cout<<"Hello,Duniya!\n";
    Print(n-1);
}

int main(){
    int num{};
    
    cout<<"Enter the number:";
    cin>>num;
  
    Print(num);
  //PrintN(num);

    return 0;
}

