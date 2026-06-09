/*
🌀 Recursive Function in C++ — Complete Guide
📌 What is Recursion?
Recursion is a programming technique where a function calls itself directly or indirectly to solve a smaller sub-problem of the original problem.
A recursive function must have:
1.Base Case – Stops the recursion.
2.Recursive Case – The function calls itself to solve a smaller part.

🧠 Syntax of a Recursive Function in C++
    return_type function_name(parameters) {
        if (base_case_condition) {
            return base_result;
        } else {
            return recursive_case;
        }
    }
✅ Example 1: Factorial Using Recursion
*/
    #include <iostream>
    using namespace std;

    int factorial(int n) {
        if (n == 0 || n == 1) // base case
            return 1;
        else
            return n * factorial(n - 1); // recursive case
    }

    int main() {
        int num = 5;
        cout << "Factorial of " << num << " = " << factorial(num);
        return 0;
    }


/*
🧾 Output:
Factorial of 5 = 120

📘 Explanation:
•factorial(5) calls factorial(4), and so on until factorial(1) which returns 1.


🧮 Memory Behavior
Each recursive call creates a new frame on the call stack with:
•its own parameters
•return address
•local variables
As recursion goes deeper, stack memory is consumed. When the base case is reached, the calls start unwinding.

🔁 Recursive vs Iterative
Feature	        Recursive	                        Iterative
Style	        Function calls itself	            Uses loops (for, while)
Memory	        More (stack frames)	                Less (single loop frame)
Performance	    Slower (due to overhead)	        Faster
Clarity	        More intuitive for divide-conquer	Simpler for linear problems

⚠️ Edge Cases to Watch
•No base case ➜ leads to stack overflow (infinite recursion).
•Very large input ➜ stack overflow.
•Be careful with return values and types.

🧠 Example 2: Fibonacci Series (Recursive)
    int fibonacci(int n) {
        if (n <= 1)
            return n;
        else
            return fibonacci(n - 1) + fibonacci(n - 2);
    }

📌 Time Complexity: O(2^n)
⚠️ Very slow for large n. Use memoization or iterative methods.

🧩 Types of Recursion
1.Direct Recursion
  A function calls itself.
  → factorial(n) calls factorial(n-1)

2.Indirect Recursion
  Function A calls B, which then calls A.
    void A() { B(); }
    void B() { A(); }
3.Tail Recursion
 The recursive call is the last operation in the function.
 Can be optimized in some languages.

💡 Best Practices
•Always define a clear base case.
•Prefer tail-recursive if stack optimization is supported.
•Avoid deep recursion for large inputs unless using dynamic programming.
•For competitive programming, prefer iterative unless recursion is more intuitive.

🚀 Real-world Uses of Recursion
•Tree traversals (preorder, inorder, postorder)
•Divide and conquer algorithms (Merge Sort, Quick Sort)
•Backtracking problems (N-Queens, Sudoku solver)
•Dynamic Programming (Memoized version)
*/
