/* 
***
Given an integer n, write a function to print all numbers from 1 to n (inclusive) using recursion.
You must not use any loops such as for, while, or do-while.
The function should print each number on a separate line, in increasing order from 1 to n.

Print in reverse order too using Recursion and backtracking
*/
#include <iostream>
using namespace std;

//Recursion(Reverse order):
void print1tonrev(int n){
    if(n==0){
        return;
    }
    cout<<n<<"\n";
    print1tonrev(n-1);
}

//Recursion
void print1ton(int n,int i=1){
    if(i>n){
        return;
    }
    cout<<i<<"\n";
    print1ton(n,i+1);
}

//Backtracking
void print1tonbt(int n){
    if(n==0){
        return;
    }
    print1tonbt(n-1);
    cout<<n<<"\n";
}

//Using Backtracking(Reverse order)
void print1tonbtrev(int n,int i=1){
    if(i>n){
        return;
    }
    print1tonbtrev(n,i+1);
    cout<<i<<"\n";
}

int main(){
    int num{};
    cout<<"Enter the number:";
    cin>>num;

    cout<<"Using Recursion:\n";
    print1ton(num);

    cout<<"Using backtracking:\n";
    print1tonbt(num);

    cout <<"Using Recursion(In reverse order):\n";
    print1tonrev(num);
    
    cout<<"Using backtracking(In reverse order):\n";
    print1tonbtrev(num);

    return 0;
}

/*
📌 QUESTION:
If we initialize a variable while passing it in a function
at the time of declaration, do we still need to pass it
as an argument?

✅ ANSWER:
NO — because this is called a DEFAULT ARGUMENT.

WHAT ARE DEFAULT ARGUMENTS?
A default argument is a value provided in a function
parameter list that is automatically used if the caller
does NOT pass that argument.

Syntax:
return_type functionName(type param = default_value);

EXAMPLE
    void printNumbers(int n, int i = 1) {
        if (i > n) return;
        cout << i << " ";
        printNumbers(n, i + 1);
    }

Function Call:
    printNumbers(5);
✔ i is NOT passed
✔ Compiler automatically assigns i = 1
✔ Code works correctly

HOW IT ACTUALLY WORKS
When you write: int i = 1
in the parameter list, you are telling the compiler:

"If the caller does not provide a value for i,
then use 1 as the default."
So:
    printNumbers(5);        // n = 5, i = 1
    printNumbers(5, 3);     // n = 5, i = 3

👉 Default arguments MUST be the LAST parameters
❌ WRONG
void f1(int i = 1, int n);   // Not allowed

✅ CORRECT
void f2(int n, int i = 1);   // Allowed

Reason:
Once a parameter has a default value,
ALL parameters after it must also have defaults.

WHAT DEFAULT ARGUMENTS ARE NOT
Default arguments are NOT:
❌ Global variables
❌ Static variables
❌ Shared memory between function calls

Each recursive call still gets its OWN copy of i.
*/
