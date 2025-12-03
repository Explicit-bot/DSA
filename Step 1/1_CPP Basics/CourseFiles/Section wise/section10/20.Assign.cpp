/*
🔰 assign()?

assign() replaces the entire contents of a std::string with new data. It’s similar to using the = operator but gives more flexibility with different overloads.

🔁 Unlike append(), which adds to the existing string, assign() replaces the string content.

📚 Syntax & Overloads
string& assign(const string& str);       // Replace with another string
string& assign(const string& str, size_t subpos, size_t n); // Replace
                                                         with substring
string& assign(const char* s);              // Replace with C-string
string& assign(const char* s, size_t n);   // Replace with first n chars
string& assign(size_t n, char c);      // Replace with n copies of char
template <class InputIterator>
string& assign(InputIterator first, InputIterator last);  
// Replace using iterator range

✅ 1. assign(const string& str)
🧠 Meaning:
Replaces the current string with another.

🔧 Code:
    string s = "Old";
    string t = "New";
    s.assign(t);
    cout << s;  // Output: New

📌 Output:
New

✅ 2. assign(const string& str, size_t subpos, size_t n)
🧠 Meaning:
Replaces the string with a substring from another string.

🔧 Code:
    string s = "Old";
    string t = "HelloWorld";
    s.assign(t, 0, 5); // Take 5 characters from index 0
    cout << s;

📌 Output:
Hello

⚠️ Edge Case:
If subpos > t.size(), it throws std::out_of_range.

✅ 3. assign(const char* s)
🧠 Meaning:
Assigns content from a C-style null-terminated string.

🔧 Code:
    string s;
    s.assign("Hello");
    cout << s;

📌 Output:
Hello

✅ 4. assign(const char* s, size_t n)
🧠 Meaning:
Assigns the first n characters from a C-string, even if there's a null terminator early.

🔧 Code:
    string s;
    s.assign("OpenAI GPT", 6); // Only first 6 characters
    cout << s;

📌 Output:
OpenAI

✅ 5. assign(size_t n, char c)
🧠 Meaning:
Replaces the string with n copies of character c.

🔧 Code:
    string s;
    s.assign(5, '*');
    cout << s;

📌 Output:
*****

✅ 6. assign(InputIterator first, InputIterator last)
🧠 Meaning:
Assigns characters from a range of iterators.

🔧 Code:
    vector<char> v = {'C', '+', '+'};
    string s;
    s.assign(v.begin(), v.end());
    cout << s;

📌 Output:
C++

🧪 Special Case: Assigning to Itself
    string s = "Naman";
    s.assign(s); // Safe
    cout << s;

✅ Output: 
Naman

ℹ️ Self-assignment is safe in C++ STL strings.

📊 assign() vs = Operator
Feature	                assign()	        = operator
Replace full string	    ✅ Yes	            ✅ Yes
Substring assignment	✅ Yes	            ❌ No
Char repetition	        ✅ Yes	            ❌ No
Iterator range	        ✅ Yes	            ❌ No
Performance	            ✅ High (no temp)	❌ Slightly slower
*/
