/*
🔁 INTRODUCTION TO RECURSION

📌 1. WHAT IS RECURSION?
----------------------
Recursion is a programming technique in which a function calls itself,
directly or indirectly, to solve a problem.

The main idea of recursion is to break a big problem into smaller
subproblems of the same type until a stopping condition is reached.

📌 2. HOW RECURSION WORKS
-----------------------
A recursive solution always follows two fundamental rules:
1) The function must solve a smaller version of the same problem  
2) The function must stop calling itself when a base condition is met  

If the base condition is missing, recursion will run infinitely.

🧩 3. BASIC STRUCTURE OF A RECURSIVE FUNCTION
--------------------------------------------
    void func(int n) {
        if (n == 0) return;   // Base Condition
        // Work
        func(n - 1);          // Recursive Call
    }

Every recursive function contains:
• A base condition (termination step)
• A recursive call (problem reduction step)

TEXT FLOW DIAGRAM (RECURSION LOGIC)
+----------------------+
| Recursive Function   |
|                      |
|  Is Base Case True ? |
|          |           |
|          | YES       |
|          +---------> return
|          |
|          NO
|          |
|          v
|   Recursive Call
+----------------------+

❌ 4. RECURSION WITHOUT BASE CONDITION
    void func() {
        func();   // infinite recursion
    }

Since there is no base condition:
• The function keeps calling itself
• Calls never stop
• Memory keeps filling

CALL STACK GROWTH
func()
└── func()
    └── func()
        └── func()
            └── func()
                └── func()
                    ...

STACK (TOP → BOTTOM)
| func() |
| func() |
| func() |
| func() |
| func() |
| func() |
|  main  |

Result:
Stack keeps growing → Stack Overflow → Program Crash

💥 5. WHAT IS STACK OVERFLOW?
Whenever a function is called, it is stored in stack memory.
Recursive calls are also stored in the stack.

Stack memory is LIMITED.

| func(1) |
| func(2) |
| func(3) |
| func(4) |
| func(5) |
|  main   |
----------
STACK FULL ❌

When stack memory limit is exceeded:
→ Stack Overflow
→ Segmentation Fault
→ Program terminates

✅ 6. BASE CONDITION (MOST IMPORTANT PART)
A base condition is the stopping condition of recursion.
It prevents infinite recursive calls and allows the program to return.

void printN(int n) {
    if (n == 0) return;   // base condition
    cout << "Hello\n";
    printN(n - 1);
}

ROLE OF BASE CONDITION
Base Condition
      ↓
Stops recursive calls
      ↓
Allows functions to return
      ↓
Stack starts unwinding

🔄 7. EXECUTION FLOW (CALLS VS RETURNS)
void printN(int n) {
    if (n == 0) return;   // base condition
    cout << "Hello\n";
    printN(n - 1);
}

Example: printN(3)

FUNCTION CALLS (GOING DOWN)
printN(3)
  ↓
printN(2)
  ↓
printN(1)
  ↓
printN(0)   <-- Base Condition Hit

FUNCTION RETURNS (COMING UP)
printN(0) returns
  ↑
printN(1) returns
  ↑
printN(2) returns
  ↑
printN(3) returns

🗂 8. CALL STACK VISUALIZATION

CALL STACK DURING EXECUTION
| printN(1) |  <-- TOP
| printN(2) |
| printN(3) |
|   main    |


AFTER BASE CONDITION
| printN(2) |
| printN(3) |
|   main    |


FINAL STATE
|   main    |

🌳 9. RECURSIVE TREE REPRESENTATION
A recursive tree visually represents how recursive calls are made.
Example: printN(3)

printN(3)
  |
  └── printN(2)
        |
        └── printN(1)
              |
              └── printN(0)

✅ 10. ADVANTAGES OF RECURSION
✔ Cleaner and shorter code
✔ Natural for trees and graphs
✔ Best for divide-and-conquer algorithms
✔ Reduces complex looping logic

❌ 11. DISADVANTAGES OF RECURSION
✘ Extra memory usage due to stack
✘ Risk of stack overflow
✘ Slower than iterative solutions
✘ Harder to debug for deep recursion
*/
