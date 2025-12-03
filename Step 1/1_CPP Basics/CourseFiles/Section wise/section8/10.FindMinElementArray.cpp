/*
What is INT_MAX?
It is a maximum integer value. It is a predefined constant available
in some compilers.
For finding minimum number we initialise
min=INT_MAX.
If it is not available in your compiler then initialise min with first
elements.
min=A[0];
*/
#include <iostream>
using namespace std;

int main(){
    int i{};
    int A[7]{};
    
    for(int &x:A){
        cout<<"Enter element for index "<<i<<":";
        cin>>x;
        ++i;
    }
    
    int min{A[0]}; //Same as explained in the last question or ucan use INT_MAX
    for(int x:A){
        if(min>x){
            min=x;
        }
    }

    cout<<"Min element of the given Array [";
    for(int y{};y<7;++y){
        cout<<A[y]<<" ";
    }
    cout<<"]"<<" is "<< min<<".\n";
}



















