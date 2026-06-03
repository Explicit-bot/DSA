/*
🔹 append()

append() is a member function of std::string used to add (append) characters or another string to the end of an existing string.
It's more efficient than using the + operator when modifying an existing string because it avoids creating temporary objects.

📚 Syntax & Overloads
Here are all the commonly used overloads of append():
string& append(const string& str);          // Append full string
string& append(const string& str, size_t subpos, size_t n); // Append
                                                             substring
string& append(const char* s);               // Append C-string
string& append(const char* s, size_t n);    // Append n characters
                                               from C-string
string& append(size_t n, char c);           // Append n copies of a char
template<class InputIterator>
string& append(InputIterator first, InputIterator last);   // Append using iterators

✅ 1. append(const string& str)
🧠 Meaning:
Appends the entire string str to the end.

🔧 Syntax:
    string s1 = "Hello ";
    string s2 = "World";
    s1.append(s2);

📥 Input:
"Hello " and "World"

📤 Output:
"Hello World"

🧪 Edge Case:
    string s = "A";
    string empty = "";
    s.append(empty); // s = "A" (no change)

✅ 2. append(const string& str, size_t subpos, size_t n)
🧠 Meaning:
Appends a substring starting from subpos for n characters.

🔧 Syntax:
    string s = "ABC";
    string t = "HelloWorld";
    s.append(t, 0, 5); // Appends "Hello"

📤 Output:
"ABCHello"

⚠️ Edge Case:
If subpos > str.size() → std::out_of_range exception.

✅ 3. append(const char* s)
🧠 Meaning:
Appends a C-style null-terminated string.

🔧 Syntax:
    string s = "Name: ";
    s.append("Naman");

📤 Output:
"Name: Naman"

⚠️ Edge Case:
If s == nullptr → undefined behavior. Always check!

✅ 4. append(const char* s, size_t n)
🧠 Meaning:
Appends the first n characters from s, even if s has more.

🔧 Syntax:
    string s = "Start: ";
    s.append("ABCDEFG", 3);  // Appends "ABC"

📤 Output:
"Start: ABC"

📌 Note:
This version ignores the null terminator — only uses n.

✅ 5. append(size_t n, char c)
🧠 Meaning:
Appends n copies of character c.

🔧 Syntax:
    string s = "Wait";
    s.append(3, '.'); // Appends "..."

📤 Output:
"Wait..."

✅ Use-case:
Great for progress bars, padding, or visual formatting.

✅ 6. append(InputIterator first, InputIterator last)
🧠 Meaning:
Appends all characters from the range [first, last).

🔧 Syntax:
    vector<char> v = {'O', 'P', 'E', 'N'};
    string s = "AI = ";
    s.append(v.begin(), v.end());

📤 Output:
"AI = OPEN"

💾 Memory Behavior
Strings in C++ use dynamic memory. append() will:
Reallocate memory if capacity is insufficient.
Use existing buffer if there's space.
Always keep null terminator (\0) for safety.

You can check memory changes using .capacity():
    string s = "Test";
    cout << s.capacity() << endl;
    s.append("1234567890");
    cout << s.capacity() << endl;

🔁 Chaining
You can chain multiple appends:
    string s;
    s.append("Hello ").append("World").append("!");

Output:
"Hello World!"

⚖️ Comparison: append() vs +
Feature	        append()	+ operator
In-place	    ✅ Yes	   ❌ No (creates copy)
Faster (loop)	✅	       ❌
Readable	    Moderate    ✅ Very
Chainable	    ✅ Yes	   ✅ Yes

❗ Edge Cases Summary
Appending from a null C-string causes crash.
Appending beyond substring range throws exception.
Appending to self is okay but should be used carefully:
    string s = "Hi";
    s.append(s);  // "HiHi" → valid

✅ Full Example Program
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s = "Hello";
    string t = "World";

    s.append(" ");                     // Add space
    s.append(t);                       // Append string
    s.append(t, 0, 3);                 // Append substring ("Wor")
    s.append(3, '!');                  // Append 3 exclamation marks

    const char* msg = " Welcome";
    s.append(msg, 4);                  // Append first 4 chars (" Wel")

    vector<char> v = {'_', 'U', 's', 'e', 'r'};
    s.append(v.begin(), v.end());     // Append using iterator

    cout << s << endl;
    return 0;
}
/*
🧾 Output:
Hello WorldWor!!! Wel_User
*/
