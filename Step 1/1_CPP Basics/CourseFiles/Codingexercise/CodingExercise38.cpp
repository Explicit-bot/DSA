/*
Draw a Lower Triangle of *
Draw a pattern of * for given dimensions given below

*
* *
* * *
* * * *
* * * * *
*/
#include<iostream>
using namespace std;

void Draw(int n)
{
    
    //Draw Pattern given in description for n x n dimensions
    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            if(i>=j){
                cout<<"*"<<" ";
            }
        }
        cout<<endl;
    }
}
