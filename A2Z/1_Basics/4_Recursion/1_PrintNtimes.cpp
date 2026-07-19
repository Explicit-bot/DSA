/*   
Given an integer N, write a program to print any name N times.
*/


#include <iostream>
using namespace std;

void print(int n,string name){
    if(n==0){
        return;
    }
    cout<<name<<"\n";
    print(n-1,name);
}

int main(){
    int num{};
    string name{};
    cout<<"Enter the number:";
    cin>>num;

    cout<<"Enter name to print:";
    cin.ignore();
    getline(cin,name);

    print(num,name);

    return 0;
}


/*
What i wrote first time
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
