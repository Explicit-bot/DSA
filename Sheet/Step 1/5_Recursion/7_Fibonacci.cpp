/*************************************************************************************************
 🧠 FIBONACCI NUMBER — ABSOLUTE COMPLETE NOTES (ONE FILE)
**************************************************************************************************

====================================
📌 PROBLEM STATEMENT
====================================
The Fibonacci numbers form a sequence such that each number is the sum
of the two preceding ones.

Mathematically:
F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1

------------------------------------
📥 INPUT
------------------------------------
An integer n (0 ≤ n ≤ 30)

------------------------------------
📤 OUTPUT
------------------------------------
Return the nth Fibonacci number F(n)

------------------------------------
🧪 EXAMPLES
------------------------------------
Input:  n = 2
Output: 1

Input:  n = 3
Output: 2

Input:  n = 4
Output: 3

**************************************************************************************************
📌 WHY THIS PROBLEM IS IMPORTANT?
--------------------------------------------------------------------------------------------------
• Classic recursion problem
• Perfect example of:
  - Overlapping subproblems
  - Optimal substructure
• Foundation of Dynamic Programming (DP)
• Frequently asked in interviews and exams
**************************************************************************************************/
#include <iostream>
using namespace std;

/*************************************************************************************************
 🔴 APPROACH 1: BRUTE FORCE (PURE RECURSION)
**************************************************************************************************
🧠 IDEA:
Directly implement the mathematical definition.

F(n) = F(n-1) + F(n-2)

------------------------------------
🌳 RECURSION TREE (n = 4)
------------------------------------
fib(4)
├── fib(3)
│   ├── fib(2)
│   │   ├── fib(1) -> 1
│   │   └── fib(0) -> 0
│   └── fib(1) -> 1
└── fib(2)
    ├── fib(1) -> 1
    └── fib(0) -> 0

Notice:
• fib(2) repeated
• fib(1) repeated multiple times

------------------------------------
🧪 DRY RUN (n = 4)
------------------------------------
fib(4)
= fib(3) + fib(2)
= (fib(2)+fib(1)) + (fib(1)+fib(0))
= ((1+0)+1) + (1+0)
= 3

------------------------------------
⏱ TIME COMPLEXITY
------------------------------------
O(2^n) ❌ (exponential)

------------------------------------
🧠 SPACE COMPLEXITY
------------------------------------
O(n) (recursion stack)

------------------------------------
⚠️ NOTE
------------------------------------
• Only for learning recursion
• NOT recommended in real applications
*************************************************************************************************/

int fib_bruteforce(int n) {
    if (n <= 1)
        return n;
    return fib_bruteforce(n - 1) + fib_bruteforce(n - 2);
}

/*************************************************************************************************
 🟡 APPROACH 2: MEMOIZATION (TOP-DOWN DYNAMIC PROGRAMMING)
**************************************************************************************************
🧠 IDEA:
• Store results of subproblems
• Avoid recomputation
• Uses recursion + array (dp)

------------------------------------
🧪 DRY RUN (n = 4)
------------------------------------
dp initially = [-1, -1, -1, -1, -1]

fib(4)
→ fib(3) + fib(2)

fib(2) computed once → dp[2] = 1
fib(3) computed once → dp[3] = 2
fib(4) = dp[3] + dp[2] = 3

------------------------------------
⏱ TIME COMPLEXITY
------------------------------------
O(n)

------------------------------------
🧠 SPACE COMPLEXITY
------------------------------------
O(n) (dp array + recursion stack)
*************************************************************************************************/

int fib_memo_helper(int n, vector<int>& dp) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib_memo_helper(n - 1, dp) + fib_memo_helper(n - 2, dp);
}

int fib_memoization(int n) {
    vector<int> dp(n + 1, -1);
    return fib_memo_helper(n, dp);
}

/*************************************************************************************************
 🟢 APPROACH 3: TABULATION (BOTTOM-UP DYNAMIC PROGRAMMING)
**************************************************************************************************
🧠 IDEA:
• Remove recursion
• Build answer iteratively from base cases

------------------------------------
🧪 DRY RUN (n = 4)
------------------------------------
dp[0] = 0
dp[1] = 1

i = 2 → dp[2] = 1
i = 3 → dp[3] = 2
i = 4 → dp[4] = 3

------------------------------------
⏱ TIME COMPLEXITY
------------------------------------
O(n)

------------------------------------
🧠 SPACE COMPLEXITY
------------------------------------
O(n)
*************************************************************************************************/

int fib_tabulation(int n) {
    if (n <= 1)
        return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

/*************************************************************************************************
 🔥 APPROACH 4: SPACE OPTIMIZED DP (BEST SOLUTION)
**************************************************************************************************
🧠 IDEA:
• Only last two Fibonacci numbers are needed
• No recursion
• No array

------------------------------------
🧪 DRY RUN (n = 4)
------------------------------------
prev2 = 0
prev1 = 1

i = 2 → curr = 1 → prev2 = 1, prev1 = 1
i = 3 → curr = 2 → prev2 = 1, prev1 = 2
i = 4 → curr = 3 → prev2 = 2, prev1 = 3

Return 3

------------------------------------
⏱ TIME COMPLEXITY
------------------------------------
O(n)

------------------------------------
🧠 SPACE COMPLEXITY
------------------------------------
O(1) ⭐
*************************************************************************************************/

int fib_optimized(int n) {
    if (n <= 1)
        return n;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

/*************************************************************************************************
 🧪 MAIN FUNCTION
**************************************************************************************************
• Takes input from user
• Runs all approaches
• Prints results
*************************************************************************************************/

int main() {
    int n;
    cout << "Enter n (0 <= n <= 30): ";
    cin >> n;

    cout << "\n--- Fibonacci Results ---\n";
    cout << "Brute Force Recursion      : " << fib_bruteforce(n) << endl;
    cout << "Memoization (Top-Down DP)  : " << fib_memoization(n) << endl;
    cout << "Tabulation (Bottom-Up DP)  : " << fib_tabulation(n) << endl;
    cout << "Space Optimized DP (BEST)  : " << fib_optimized(n) << endl;

    return 0;
}

/*************************************************************************************************
 🧾 FINAL COMPARISON SUMMARY
--------------------------------------------------------------------------------------------------
Approach                Time Complexity      Space Complexity
--------------------------------------------------------------------------------------------------
Brute Force              O(2^n)               O(n)
Memoization              O(n)                 O(n)
Tabulation               O(n)                 O(n)
Space Optimized DP       O(n)                 O(1) ⭐ BEST

--------------------------------------------------------------------------------------------------
🧠 INTERVIEW STRATEGY
--------------------------------------------------------------------------------------------------
1️⃣ Write recursive solution
2️⃣ Explain overlapping subproblems
3️⃣ Add memoization
4️⃣ Convert to tabulation
5️⃣ Optimize space

Do this → interviewer = impressed 😄🔥
*************************************************************************************************/
