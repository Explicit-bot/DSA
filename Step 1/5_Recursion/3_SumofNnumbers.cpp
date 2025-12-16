/*                  ************
Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.
*/

#include <iostream>
using namespace std;

//Recursion:
int Nnumbersum(int n,int sum) {
    if(n==0){
        return sum;
    }
    
    return Nnumbersum(n-1,sum+n);
}

//Backtracking
int NnumberSum(int n) {
    if(n==1){
        return 1;
    }
    return n + NnumberSum(n-1);
}


int main(){
    int num{};
    cout<<"Enter the number:";
    cin>>num;

    cout<<"Using Recursion:\n";
    cout<<Nnumbersum(num,0)<<"\n";

    cout<<"Using backtracking:\n";
    cout<<NnumberSum(num)<<"\n";

    return 0;
}
