/*
    1   2   3   4
    5   6   7   8
    9   10  11  12
    13  14  15  16
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size of square grid: ";
    cin >> n;
    int count{1};

    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            cout<<count<<"\t";
            ++count;
        }
        cout<<endl;
    }
}
