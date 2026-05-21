/*     
***             
Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.
*/

#include <iostream>
using namespace std;

//Recursion:
int sumofN(int n,int sum=0){
    if(n==0){
        return sum;
    }

    return sumofN(n-1,sum+n);
}  
/*
Calls (going down)
→ Nnumbersum(3, 0)
→ Nnumbersum(2, 3)
→ Nnumbersum(1, 5)
→ Nnumbersum(0, 6)
Base case hits
return 6;

Now coming back up…
Does anything happen?
❌ NO
Each call immediately returns the value from the next call.
There is no work done after recursion returns and that is why it is recursion and not backtracking.
*/

//Backtracking
int sumofNbt(int n){
    if(n==0){
        return; //Must return any int just return won't work as it is non-void function
    }

    return n + sumofNbt(n-1);
}

/*
📉 Call stack visualization (n = 3)
Going down
NnumberSum(3)
→ NnumberSum(2)
→ NnumberSum(1)
→ NnumberSum(0)

Coming back (🔥 WORK HAPPENS HERE)
return 0
return 1 + 0 = 1
return 2 + 1 = 3
return 3 + 3 = 6
Work is done after recursion returns ⇒ ✅ backtracking.
*/

int main(){
    int num{};
    cout<<"Enter the number:";
    cin>>num;

    cout<<"Using Recursion:\n";
    cout<<sumofN(num)<<"\n";

    cout<<"Using backtracking:\n";
    cout<<sumofNbt(num)<<"\n";

    return 0;
}

