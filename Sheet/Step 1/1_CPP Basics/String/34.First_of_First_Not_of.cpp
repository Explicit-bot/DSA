/*
🔹 1. find_first_of(str, pos)
Finds the first character (from a set of characters) that occurs in the string, starting from pos.

🔸 Syntax:
    size_t find_first_of(const string& chars, size_t pos = 0);

✅ Example:
    string s = "cpp_is_fun";
    size_t pos = s.find_first_of("aeiou");  // first vowel
    cout << "First vowel at index: " << pos << endl;

First character in the string that is either a,e,i,o or u 
🟢 Output:
First vowel at index: 6  // 'u'

🧠 Use Case:
Useful when checking if any of multiple characters (like vowels or delimiters) exist in a string.

🔹 2. find_last_of(str, pos)
Finds the last occurrence of any character from the given set, searching backward from pos.

🔸 Syntax:
    size_t find_last_of(const string& chars, size_t pos = npos);

✅ Example:
    string s = "hello world!";
    size_t pos = s.find_last_of("aeiou");  // last vowel
    cout << "Last vowel at index: " << pos << endl;

🟢 Output:
Last vowel at index: 7  // 'o' in "world"

🧠 Use Case:
Reverse search — find last punctuation, last vowel, etc.

🔹 3. find_first_not_of(str, pos)
Finds the first character that is not in the given character set, starting from pos.

🔸 Syntax:
    size_t find_first_not_of(const string& chars, size_t pos = 0);

✅ Example:
    string s = "  \t\nHello";
    size_t pos = s.find_first_not_of(" \t\n");
    cout << "First non-whitespace at index: " << pos << endl;

🟢 Output:
First non-whitespace at index: 3  // 'H'
🧠 Use Case:
Trimming leading whitespace or skipping unwanted characters.

🔹 4. find_last_not_of(str, pos)
Finds the last character that is not in the given character set, starting backward from pos.

🔸 Syntax:
size_t find_last_not_of(const string& chars, size_t pos = npos);
✅ Example:
    string s = "data!!!";
    size_t pos = s.find_last_not_of("!");
    cout << "Last non-'!' character at index: " << pos << endl;

🟢 Output:
Last non-'!' character at index: 3  // 'a'

🧠 Use Case:
Trim trailing characters or whitespace from the end of a string.

🔸 Edge Cases
Case	                                    Behavior
If no matching character found	            Returns string::npos
Empty search string	                        All characters are treated as non-matching
                                             (except not_of)
Empty input string	                        Always returns npos

🔚 Summary Table
Function	            What it finds	                            Direction
find_first_of(s)	    First char in s found in target string	    Left ➡️
find_last_of(s)	        Last char in s found in target string	    Right ⬅️
find_first_not_of(s)	First char not in s	                        Left ➡️
find_last_not_of(s)	    Last char not in s	                        Right ⬅️
*/
