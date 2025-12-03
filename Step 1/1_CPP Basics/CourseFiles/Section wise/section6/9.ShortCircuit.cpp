/*
SHORT-CIRCUIT
In C++, short-circuit evaluation refers to the way logical operators (&& and ||) evaluate expressions. It allows the program to stop evaluating further conditions as soon as the result is already determined.

✅ How Short-Circuiting Works:
1. && (Logical AND) Operator:
	•	Short-circuits (stops evaluating) when the left-hand operand is false.
	•	Since false && anything is always false, the second operand doesn’t need to be checked.
Example:
    if (false && (5 / 0 == 0)) {
        cout << "This won't print!";
    }
    •	Why? The expression false && (5 / 0 == 0) is already false, so the program won’t attempt to evaluate (5 / 0 == 0), avoiding a division by zero error.

2. || (Logical OR) Operator:
	•	Short-circuits (stops evaluating) when the left-hand operand is true.
	•	Since true || anything is always true, the second operand doesn’t need to be checked.
Example:
    if (true || (5 / 0 == 0)) {
        cout << "This will print!";
    }
    •	Why? The expression true || (5 / 0 == 0) is already true, so the program doesn’t evaluate (5 / 0 == 0) and avoids the error.

✅ Why is Short-Circuiting Useful?
	1.	Performance:
	•If the result can be determined early, the program doesn’t waste time evaluating  
     further conditions.
	2.Avoiding Errors:
	•Short-circuiting helps you avoid undefined behavior, like dividing by zero or  
     accessing invalid memory.
*/
//Program to Demonstrate Short Circuit
#include <iostream>

int main(){

    int a=10,b=5,i=5;
    
    if(a>b && ++i<=b){
    }
    std::cout<<i<<std::endl;      // 6 will be printed as i was increased after check
    //as first condition was true so the second statement was checked in the above
    if(a>b || ++i<=b){
    }
    std::cout<<i<<std::endl;     //6 will be printed as 2nd condition was not checked
    //as first condition was true so the second statement was not checked in the above
}

/*
🧨 Expression: if (a / 0 == 2)
🔥 Problem:
a / 0 is a division by zero, which is undefined behavior in C++.

🔍 What will the compiler or runtime do?
🖥️ If a is an int:
The program will compile.
But at runtime, when it executes a / 0, it will crash.
You might get an error like:
    Floating point exception (core dumped)
🚨 Division by zero in integer arithmetic is not allowed and causes a runtime error.

❗ Important Note:
Even if it's inside an if condition, the expression:
    if (a / 0 == 2)
still requires evaluating a / 0, which must be done before checking the condition.
So this will crash your program, even before the comparison happens.

✅ What About Floating-Point Division?
If you do:

    double a = 10;
    if (a / 0.0 == INFINITY)
This does not crash.

In floating-point math:
10 / 0.0 results in +∞ (infinity).
-10 / 0.0 results in -∞.
0 / 0.0 results in NaN (Not a Number).
These are part of the IEEE 754 standard for floating-point numbers.

⚠️ Why is this dangerous?
Even if it doesn't crash:
 -You can't trust the output.
 -The behavior can change between compiles, or when optimization is turned on.
 -On one system it might "work", on another it might silently destroy your logic.
*/
