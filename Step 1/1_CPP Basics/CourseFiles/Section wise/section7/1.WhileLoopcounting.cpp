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

Example:
int i = 1;
while (i <= 5) {
    cout << i << " ";
    i++;
}

🔹 Output: 1 2 3 4 5

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

Example:
int i = 1;
do {
    cout << i << " ";
    i++;
} while (i <= 5);

🔹 Output: 1 2 3 4 5

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

Example:
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}

🔹 Output: 1 2 3 4 5

Key Points:
•Best for fixed number of iterations.
•Initialization, condition, and update all in one place → neat & clean.
•Used for counters, mathematical series, arrays.

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
•No need for counters or indexing.
•Cleaner and safer (avoids index-out-of-bounds errors).
•Used when you just need to access elements, not modify by index.

========================
   Loop Comparison
========================

1. while()  [Pre-tested loop]
   - Condition is checked before execution.
   - Body may not execute if condition is false initially.
   - Best for unknown number of iterations.
   - Example: Reading input until user enters 0.

2. do..while()  [Post-tested loop]
   - Body executes first, condition is checked later.
   - Executes at least once no matter what.
   - Best for cases where execution must happen once.
   - Example: Menu-driven program, input validation.

3. for()  [Counter-controlled loop]
   - Initialization, condition, and update in one place.
   - Condition checked before each iteration.
   - Suitable for fixed number of iterations.
   - Example: Printing numbers from 1 to 10, summing series.

4. for-each (range-based for)  [Collection loop]
   - Iterates directly over elements of arrays/collections.
   - No explicit index or counter required.
   - Cleaner and avoids index errors.
   - Example: Traversing an array or vector elements.

-------------------------
   Quick Summary
-------------------------
- while()     → Condition checked before, may skip entirely.
- do..while() → Condition checked after, runs at least once.
- for()       → Best for known/fixed iterations.
- for-each    → Best for collections/arrays traversal.
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
/*
while and for difference
•while is used when you don't know how many time you have to repeat, so
repeat WHILE condition is true.
•for is used when you know FOR how many time you have to repeat.

When to use which loop ?
1. While and doWhile are similar, they are used when we don’t know
number of times of repetitions
2. For is used when we know the number of iterations.
3. For each is used with array or STL.

What should be used in for loop i++ or ++i ?
Anyone can be used.
++i; is known to be faster than i++;.
Reason:
i++; is same as i=i+1; here i+1 is evaluated and the result is
stored in a temporary variable and then assigned to i.
++i; here i+1 is not stored in a temporary variable, directly i is
increased by 1 
*/
