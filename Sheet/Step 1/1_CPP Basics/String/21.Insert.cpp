/*
insert()?
The insert() function inserts characters or strings at a specified position in a std::string.

📌 It doesn't replace content — it adds to the string at a given index.

📚 Syntax & Overloads
string& insert(size_t pos, const string& str);
string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
string& insert(size_t pos, const char* s);
string& insert(size_t pos, const char* s, size_t n);
string& insert(size_t pos, size_t n, char c);
iterator insert(const_iterator p, char c);
iterator insert(const_iterator p, size_t n, char c);
template<class InputIterator>
iterator insert(const_iterator p, InputIterator first, InputIterator last);

✅ 1. insert(pos, const string& str)
🧠 Meaning:
Insert another string at a specific position.

🔧 Code:
    string s = "Hello!";
    s.insert(5, " World");  // Insert at index 5
    cout << s;

📌 Output:
Hello World!

✅ 2. insert(pos, const string& str, subpos, sublen)
🧠 Meaning:
Insert a substring of another string.

🔧 Code:
    string s = "C++";
    string lang = "Programming";
    s.insert(0, lang, 0, 4);  // Insert "Prog" at start
    cout << s;

📌 Output:
ProgC++

✅ 3. insert(pos, const char* s)
🧠 Meaning:
Insert a null-terminated C-string at given position.

🔧 Code:
    string s = "GPT";
    s.insert(3, " 4.0");
    cout << s;

📌 Output:
GPT 4.0

✅ 4. insert(pos, const char* s, size_t n)
🧠 Meaning:
Insert first n characters from a C-string.

🔧 Code:
    string s = "Hello!";
    s.insert(5, "XXXXX", 2);  // Insert "XX" at index 5
    cout << s;

📌 Output:
HelloXX!

✅ 5. insert(pos, size_t n, char c)
🧠 Meaning:
Insert n copies of character c at position pos.

🔧 Code:
    string s = "CS";
    s.insert(1, 3, '+');  // Insert "+++" at index 1
    cout << s;

📌 Output:
C+++S

✅ 6. insert(iterator pos, char c) & related
🧠 Meaning:
Insert using an iterator instead of index.

🔧 Code:
    string s = "Real";
    auto it = s.begin() + 4;   //explained in the end
    s.insert(it, 'M');
    cout << s;

📌 Output:
RealM

⚠️ Edge Cases
Case	                                    Behavior
Inserting at pos > size()	                Throws std::out_of_range
Inserting 0 characters	                    Valid — has no effect
Inserting into empty string	                Works — becomes new string
Self-insertion (e.g. s.insert(…) with s)	Safe, but not common

📌 Visual Diagram Example
    s = "GHT"
    s.insert(1, "PU");  // Insert "PU" at index 1

Before: G H T
Insert:   ↑
After:  G P U H T

begin();
string s = "Real";
auto it = s.begin() + 4;

🔍 1. What is s.begin()?
s.begin() returns an iterator pointing to the first character in the string.
For s = "Real":
Index:  0   1   2   3
Char:   R   e   a   l
        ↑
     s.begin()

🔍 2. What does s.begin() + 4 mean?
The + operator moves the iterator forward by the number of characters you specify.
So:
s.begin() + 1 → points to 'e'
s.begin() + 2 → points to 'a'
s.begin() + 3 → points to 'l'
s.begin() + 4 → points past 'l' (off the end)
Thus,
    auto it = s.begin() + 4;  // = s.end()

So:
s.begin() + length = s.end()
This iterator doesn’t point to a valid character — it’s one-past-the-last (a common concept in C++ iterators).

✅ Diagram
String:    R    e    a    l
Index:     0    1    2    3
Iterators:↑    ↑    ↑    ↑    ↑
         b+0  b+1  b+2  b+3  b+4
                              = s.end()

So when you write:
    s.insert(s.begin() + 4, 'M');

You're inserting 'M' at the end, just like:
    s.push_back('M');

⚠️ Bonus Tip:
If you try s.begin() + 5, it’s undefined behavior because it goes beyond s.end().
*/
