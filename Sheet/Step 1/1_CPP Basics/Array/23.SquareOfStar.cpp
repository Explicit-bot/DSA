/*
Draw a Square of *
Draw a pattern of * for given dimensions given below

* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size of square grid: ";
    cin >> n;

    //Draw Pattern given in description for n x n dimensions
    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            cout<<"* ";
        }
        cout<<endl;
    }
}
