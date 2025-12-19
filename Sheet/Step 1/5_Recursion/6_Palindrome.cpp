/******************************************************************************************
 * 🪞 VALID PALINDROME — COMPLETE GUIDE (RECURSION + BACKTRACKING)
 * VS CODE READY • INTERVIEW + CP NOTES INCLUDED
 *
 * PROBLEM:
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase
 * letters and removing all non-alphanumeric characters, it reads the same forward
 * and backward.
 *
 * CONSTRAINTS:
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 * KEY POINTS:
 * ✔ Case-insensitive
 * ✔ Ignore non-alphanumeric characters
 * ✔ Empty string is a palindrome
 ******************************************************************************************/
#include <iostream>
using namespace std;

/******************************************************************************************
 * 1️⃣ PURE RECURSION (NO LOOPS, NO HELPERS, CONCEPTUAL VERSION)
 * ----------------------------------------------------------------------------
 * • Uses substr()
 * • Best for understanding recursion + backtracking
 * • NOT optimal for large inputs
 *
 * TIME:  O(n^2)
 * SPACE: O(n^2)
 ******************************************************************************************/

class SolutionPureRecursion {
public:
    bool isPalindrome(string s) {
        // Base case
        if (s.length() <= 1) return true;

        // Skip non-alphanumeric from front
        if (!isalnum(s.front()))
            return isPalindrome(s.substr(1));

        // Skip non-alphanumeric from back
        if (!isalnum(s.back()))
            return isPalindrome(s.substr(0, s.length() - 1));

        // Mismatch → backtracking
        if (tolower(s.front()) != tolower(s.back()))
            return false;

        // Recursive shrink
        return isPalindrome(s.substr(1, s.length() - 2));
    }
};

/******************************************************************************************
 * 2️⃣ OPTIMIZED RECURSION (TWO POINTERS — INTERVIEW SAFE)
 * ----------------------------------------------------------------------------
 * • No string copying
 * • Tail recursive
 * • Still recursion + backtracking
 *
 * TIME:  O(n)
 * SPACE: O(n)  (recursion stack)
 ******************************************************************************************/
class SolutionRecursive {
public:
    bool isPalindrome(string &s, int l, int r) {
        // Base case
        if (l >= r) return true;

        // Skip non-alphanumeric from left
        if (!isalnum(s[l]))
            return isPalindrome(s, l + 1, r);

        // Skip non-alphanumeric from right
        if (!isalnum(s[r]))
            return isPalindrome(s, l, r - 1);

        // Mismatch → backtracking
        if (tolower(s[l]) != tolower(s[r]))
            return false;

        // Tail recursion
        return isPalindrome(s, l + 1, r - 1);
    }

    bool isPalindrome(string s) {
        return isPalindrome(s, 0, s.length() - 1);
    }
};

/******************************************************************************************
 * 3️⃣ ITERATIVE (BEST FOR CP + PRODUCTION)
 * ----------------------------------------------------------------------------
 * • No recursion
 * • No stack overflow risk
 * • Fastest & safest
 *
 * TIME:  O(n)
 * SPACE: O(1)
 ******************************************************************************************/
class SolutionIterative {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            if (!isalnum(s[l])) { l++; continue; }
            if (!isalnum(s[r])) { r--; continue; }

            if (tolower(s[l]) != tolower(s[r]))
                return false;

            l++;
            r--;
        }
        return true;
    }
};

/******************************************************************************************
 * 4️⃣ TAIL RECURSION EXPLANATION
 * ----------------------------------------------------------------------------
 * A function is tail recursive if:
 * • The recursive call is the LAST operation
 *
 * Example:
 * return isPalindrome(s, l + 1, r - 1);
 *
 * ✔ Tail recursive
 * ❌ C++ does NOT guarantee tail call optimization
 ******************************************************************************************/

/******************************************************************************************
 * 5️⃣ WHY substr() VERSION IS BAD FOR LEETCODE
 * ----------------------------------------------------------------------------
 * substr() → O(n)
 * Recursion depth → O(n)
 * TOTAL → O(n^2)
 *
 * Causes:
 * ❌ TLE
 * ❌ MLE
 ******************************************************************************************/

/******************************************************************************************
 * 6️⃣ FINAL COMPARISON TABLE
 * ----------------------------------------------------------------------------
 * | Approach            | Time   | Space | Safe for LC | Use Case            |
 * |---------------------|--------|-------|-------------|---------------------|
 * | substr recursion    | O(n^2) | O(n^2)| ❌          | Learning recursion  |
 * | pointer recursion   | O(n)   | O(n)  | ⚠️          | Interviews          |
 * | iterative           | O(n)   | O(1)  | ✅          | CP / Production     |
 ******************************************************************************************/

/******************************************************************************************
 * 7️⃣ DRY RUN (Example)
 * ----------------------------------------------------------------------------
 * Input: "A man, a plan, a canal: Panama"
 *
 * A ↔ a ✔
 * m ↔ m ✔
 * a ↔ a ✔
 * ...
 * Base case reached → true
 ******************************************************************************************/

/******************************************************************************************
 * 8️⃣ GEN-Z FINAL TAKE 😎
 * ----------------------------------------------------------------------------
 * Recursion = elegance
 * Iteration = survival
 *
 * Explain recursion.
 * Write iteration.
 ******************************************************************************************/

int main() {
    string s = "A man, a plan, a canal: Panama";

    SolutionPureRecursion s1;
    SolutionRecursive s2;
    SolutionIterative s3;

    cout << s1.isPalindrome(s) << endl;
    cout << s2.isPalindrome(s) << endl;
    cout << s3.isPalindrome(s) << endl;

    return 0;
}
