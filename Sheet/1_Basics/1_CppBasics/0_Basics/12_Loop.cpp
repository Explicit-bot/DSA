/*
🔄 Loops in Programming
A loop is a control structure that allows us to execute a block of code repeatedly, either until a condition is false or until a counter finishes.

There are 4 common types of loops:
- while()     → Condition checked before, may skip entirely.
- do..while() → Condition checked after, runs at least once.
- for-each    → Best for collections/arrays traversal.
- for()       → Best for known/fixed iterations.

•while and do while is used when you don't know how many time you have to repeat, so
repeat WHILE condition is true.
•for each is used with array or STL.
•for is used when you know FOR how many time you have to repeat.

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

3️⃣ For-each loop → for ( : )
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

4️⃣ Counter-controlled loop → for()
👉 A loop with a counter (initializer → condition → increment/decrement), mostly used when the number of iterations is known.
🔧 General format:
    for(initialization; condition; update) {
        // body
    }

Parts of a for loop:
1. initialization → executed once at the beginning.
2. condition      → evaluated before every iteration (must be a boolean).
3. update         → executed after each iteration of the body.
*/
#include <iostream>

int main(){
    int n{};
    std::cout<<"Enter n:";
    std::cin>>n;

    for(int i{0};i<=n;++i){
    //inside initialization is optional meanining u can initialize outside the for bracket
        std::cout<<"i "<<i<<std::endl;  
        //Increment / decrement can be done inside the loop body
        //So,a for loop works as long as the condition exists; initialization and updation can be placed anywhere.
        //it means if u initialize the variable at start of main and you update inside loop it would look like
        int j{};
        for( ;j<100; ){
            ++j;
        } 
    }
}

/*
--------------------------------
✅ Multiple Initializations / Updates
--------------------------------
•You can combine multiple initializations or multiple updates using commas (,).
•Example:
    for(int i = 0, j = len - 1; i < len; i++, j--) {
        rev[i] = str[j];
    }

Explanation:
• int i = 0, j = len - 1    → multiple initializations (allowed ✅).
• i < 5 && j > 0            → If you want multiple conditions, combine them with && (AND) or || (OR).
• i++, j--                  → multiple updates (allowed ✅).

--------------------------------
❌ Condition with Comma (Invalid)
--------------------------------
- You cannot put multiple conditions separated by commas.
- Why? Because the comma operator evaluates left-to-right,
  but only the last expression is returned as the result.

⚠️ Example (wrong behavior):
    for(int i = 0, j = 10; i < 5, j > 0; i++, j--) {
        cout << i << " " << j << endl;
    }

👉 Here, only "j > 0" is considered as the condition.
   "i < 5" is ignored completely!
*/



