/*
🔄 Loops in Programming
A loop is a control structure that allows us to execute a block of code repeatedly, either until a condition is false or until a counter finishes.

There are 4 common types of loops:

1️⃣ Pre-tested loop → while()
👉 The condition is tested before the loop body executes. If the condition is false at the beginning, the body may never execute.
Syntax:
    while(condition) {
        // loop body
    }

Key Points:
•Condition checked first.
•Body may not execute even once if condition is false initially.
•Used when number of iterations is not fixed (like reading input until user enters 0).

2️⃣ Post-tested loop → do..while()
👉 The body executes first, then the condition is tested. So the body executes at least once, no matter what.
Syntax:
    do {
        // loop body
    } while(condition);

Key Points:
•Body executes at least once.
•Condition checked after execution.
•Useful when you must run the loop body first, e.g., asking user for input and checking validity afterward.

3️⃣ Counter-controlled loop → for()
👉 A loop with a counter (initializer → condition → increment/decrement), mostly used when the number of iterations is known.
Syntax:
    for(initialization; condition; update) {
        // loop body
    }

4️⃣ For-each loop → for ( : )
👉 Special form of loop used for collections, arrays, or containers. It automatically iterates through each element without needing an index.
Syntax (C++ range-based for loop):
    for (datatype var : collection) {
        // use var
    }

Example:
int arr[] = {10, 20, 30, 40, 50};

for (int x : arr) {
    cout << x << " ";
}

🔹 Output: 10 20 30 40 50

Key Points:
•Cleaner and safer (avoids index-out-of-bounds errors).
•Used when you just need to access elements, not modify by index.

- while()     → Condition checked before, may skip entirely.
- do..while() → Condition checked after, runs at least once.
- for()       → Best for known/fixed iterations.
- for-each    → Best for collections/arrays traversal.

•while and do while is used when you don't know how many time you have to repeat, so
repeat WHILE condition is true.
•for is used when you know FOR how many time you have to repeat.
•for each is used with array or STL.
*/

#include <iostream>

int main(){
    int n{};
    int i{1};
    std::cout<<"Enter value of n: ";
    std::cin>>n;
    while(i<=n)
    {
        std::cout<<i<<std::endl;
        ++i; //++i is faster than i++
    }
    return 0;
}
