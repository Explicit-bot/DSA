/*      ******
You are given an integer n. Return the value of n! or n factorial.

Factorial of a number is the product of all positive integers less than or equal to that number.
*/

#include <iostream>
using namespace std;

//Recursion:
int factorial(int n,int fact=1) {
    if(n==0){
        return fact;
    }

    return factorial(n-1,fact*n);
}

//Backtracking
int Factorial(int n) {
    if(n==0){
        return 1;
    }

    return n*Factorial(n-1);
}


int main(){
    int num{};
    cout<<"Enter the number:";
    cin>>num;

    cout<<"Using Recursion:\n";
    cout<<factorial(num)<<"\n";

    cout<<"Using backtracking:\n";
    cout<<Factorial(num)<<"\n";

    return 0;
}
