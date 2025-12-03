/*
✂️ erase() — Remove Characters from the String
✅ Purpose:
Removes characters from the string, either a single character, a range, or from a specific position to end.

🔧 Overloads & Syntax:
// 1. Erase from position `pos`, count `len` characters
string& erase(size_t pos = 0, size_t len = npos);

// 2. Erase using iterator
iterator erase(const_iterator p);

// 3. Erase using iterator range
iterator erase(const_iterator first, const_iterator last);
npos means “until the end” of the string.

💻 Example 1: Erase a portion by position and length
    string s = "Cristiano";
    s.erase(5, 4); // Removes 4 characters starting from index 5 ("iano")
    cout << s << endl;

🧾 Output:
Crist

**********************************
❓ Can you erase using index-based range like erase(2, 6) to mean "from index 2 to 6"?
❌ No, not directly.
C++ std::string::erase(pos, len) does not accept a "start index to end index" like:
    s.erase(2, 6);  // ❌ This does NOT erase from index 2 to 6

✅ What it does mean:
s.erase(pos, len); // pos = starting index, len = number of characters to erase
So:
    s.erase(2, 6); // ✅ Erases 6 characters starting from index 2

This is equivalent to:
    s.erase(s.begin() + 2, s.begin() + 8);

✅ Example:
    string s = "Cristiano";
    s.erase(2, 6); // From index 2, erase 6 characters → "istian"
    cout << s << endl;

🧾 Output:
Cro

🔁 So how to erase using index range?
If you want to erase from index start to index end (exclusive):
    int start = 2;
    int end = 6;
    s.erase(start, end - start); // ✅

✅ Example:
    string s = "Benzema";
    int start = 2;
    int end = 6;
    s.erase(start, end - start);  // Equivalent to erase(2, 4)
    cout << s << endl;

🧾 Output:
Bea
*********************************

💻 Example 2: Erase using iterators
    string s = "Messi";
    s.erase(s.begin() + 2);  // Erase character at index 2 ('s')
    cout << s << endl;

🧾 Output:
Mesi

💻 Example 3: Erase a range using iterators
    string s = "Benzema";
    s.erase(s.begin() + 2, s.begin() + 6);  // Erase from index 2 to 5
    cout << s << endl;

*This erases all characters in the range [2, 6), i.e., starting at index 2, up to but not including index 6.

🧾 Output:
Bea

⚠️ Edge Cases
Case	                                Behavior
s.erase(0)	                            Clears entire string
s.erase(100)	                        ❌ Throws out_of_range
s.erase(s.begin(), s.end())	            Same as s.clear()
s.erase(pos, 0)	                        Nothing happens
s.erase(s.begin() + n) if n > size	    ❌ Undefined behavior

📌 Use Cases
Removing unwanted substrings
Deleting from start/end/middle
Trimming strings manually
*/
