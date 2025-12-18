/*
  0 1 2 3
0       *
1     * *         //here i+j>=3   
2   * * *
3 * * * *
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter size of square grid: ";
    cin >> n;


    for(int i{};i<n;++i){
        for(int j{};j<n;++j){
            if(i+j>=n-1){
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}
