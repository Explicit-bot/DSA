/*
🔹 OVERVIEW
Function	    Purpose
rbegin()	    Returns a reverse iterator to the **last** character of the string.
rend()	        Returns a reverse iterator to **one before the first** character.

🔸 SYNTAX
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;

    reverse_iterator rend();
    const_reverse_iterator rend() const;

e.g_
std::string s = "text";
std::string::reverse_iterator it = s.rbegin();         // modifiable reverse iterator
std::string::const_reverse_iterator it2 = s.rend();    // read-only reverse iterator 

reverse_iterator: allows modification when string is non-const.
const_reverse_iterator: read-only access.

🔁 Why Do We Use ++ with rbegin() (and Not --)?
When using reverse iterators like rbegin() and rend(), the direction of traversal is reversed, but the iterator operations (++, --) remain the same syntactically.

✅ In normal iterators:
    auto it = s.begin();  // points to first character
    ++it;  // moves forward (right)

✅ In reverse iterators:
    auto it = s.rbegin();  // points to last character
    ++it;  // moves backward (left!)

So in a reverse_iterator:
++ moves leftward through the string.
-- would move rightward (toward the end).
Even though it sounds confusing, ++ always means “move to the next character in the current iterator’s logical direction”.

🧠 Reason Behind This Design
Internally, a reverse_iterator wraps a normal iterator and redefines its ++ and -- behavior. That’s why:
rbegin() points to the last character (s.end() - 1)
rend() points before the first character
The iterator still uses ++ to move "next" (which, for reverse, is backward).

🔹 BASIC EXAMPLE
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Real";

    // rbegin()
    cout << "Last character: " << *s.rbegin() << endl;

    // rend() - points just before the first character
    if (s.rend() == s.rbegin() + s.length())
        cout << "s.rend() points before the first character\n";

    return 0;
}

/*
🟢 Output:
Last character: l
s.rend() points before the first character

🔸 MEMORY DIAGRAM
For: string s = "Real";
Index:       0     1     2     3
Character:  'R'   'e'   'a'   'l'
Pointer:   ↑                   ↑
        s.rend()            s.rbegin()

rbegin() → points to 'l'
rend() → points to memory before 'R' (not dereferenceable)

🔹 USING rbegin() and rend() IN LOOPS
➤ Reverse range-based loop (C++20 only):
    for (char ch : std::views::reverse(s))
        cout << ch << " ";

➤ Iterator-based reverse loop:
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << " ";

🟢 Output:
l a e R

🔸 USE CASES
🔹 Reversal:
    string reversed(s.rbegin(), s.rend());

🔹 Palindrome check:
    bool isPalindrome = equal(s.begin(), s.end(), s.rbegin());

🔹 Manual reverse printing:
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it;

🔹 Modifying characters in reverse:
    for (auto it = s.rbegin(); it != s.rend(); ++it)
        *it = toupper(*it);

🔹 EDGE CASES

🔸 Empty String:
    string s = "";

    if (s.rbegin() == s.rend())
        cout << "Empty string has equal rbegin() and rend()";

✅ This condition is true. Never dereference rbegin() if string is empty!

🔸 const rbegin() / rend()
Used when string is const:
    const string s = "Hello";
    auto it = s.rbegin();  // const_reverse_iterator

You can read, but not modify.

❌ Dereferencing rend():
    *s.rend();  // ❌ Undefined behavior — don’t do this!

✅ KEY TAKEAWAYS
Concept	                    Explanation
s.rbegin()	                Reverse iterator to last character
s.rend()	                Reverse iterator before first character
*s.rbegin()	            Dereferences to last character
*s.rend()	                ❌ Invalid (don’t dereference)
Used for	                Reverse traversal, palindrome checks, STL algorithms
Empty string	            rbegin() == rend()

*/
