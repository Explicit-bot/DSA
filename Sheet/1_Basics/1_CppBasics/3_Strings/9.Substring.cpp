/*
🔹 Function Summary
Function	Purpose
strstr()	Find first occurrence of a substring in a string
strchr()	Find first occurrence of a character
strrchr()	Find last occurrence of a character(first occurence from 
                                                right)

All return a pointer to the first matching character in the original string, or nullptr if not found.

🔸 1. char* strstr(const char* haystack, const char* needle);
✅ Purpose:
Searches for the first occurrence of substring needle inside haystack.
Returns a pointer to where it starts inside haystack, or nullptr if not found.

✅ Syntax:
    const char* found = strstr("Hello IIIT", "IIIT");

🧠 Internal Working:
For each position i in haystack, compare:
Does haystack[i...i+len(needle)] == needle?
If yes → return pointer to haystack + i
If no match → return nullptr

💻 Example:
    #include <iostream>
    #include <cstring>

    int main() {
        const char* text = "Welcome to IIIT Sonepat";
        const char* keyword = "IIIT";

        const char* found = strstr(text, keyword);

        std::cout << "=== strstr ===\n";
        if (found) {
            std::cout << "Substring \"" << keyword << "\" found at: " <<   found << "\n";
            std::cout << "Offset index: " << (found - text) << "\n";
        } 
        else {
            std::cout << "Substring not found!\n";
        }

        return 0;
    }

📤 Output:
=== strstr ===
Substring "IIIT" found at: IIIT Sonepat
Offset index: 11

🔸 2. char* strchr(const char* str, int ch);
✅ Purpose:
Finds the first occurrence of character ch in str.
Returns pointer to character if found, nullptr if not.

✅ Syntax:
    const char* found = strchr("Hello, World", 'o');

🧠 Internal Working:
Loop through the string, from left to right.
At each position, compare with ch.
If matched → return pointer
Else → continue

💻 Example:
    #include <iostream>
    #include <cstring>

    int main() {
        const char* text = "Hello, World!";
        char ch = 'o';

        const char* found = strchr(text, ch);

        std::cout << "=== strchr ===\n";
        if (found) {
            std::cout << "First occurrence of '" << ch << "' is at: " <<    found << "\n";
            std::cout << "Offset: " << (found - text) << "\n";
        } 
        else {
            std::cout << "Character not found!\n";
        }

        return 0;
    }

📤 Output:
=== strchr ===
First occurrence of 'o' is at: o, World!
Offset: 4

🔸 3. char* strrchr(const char* str, int ch);
✅ Purpose:
Finds the last occurrence of character ch in str.

✅ Syntax:
    const char* found = strrchr("Hello, World!", 'o');

🧠 Internal Working:
Loop from beginning, keep updating pointer when a match is found.
At end, return the last stored pointer.

💻 Example:
    #include <iostream>
    #include <cstring>

    int main() {
        const char* text = "Hello, World!";
        char ch = 'o';

        const char* found = strrchr(text, ch);

        std::cout << "=== strrchr ===\n";
        if (found) {
            std::cout << "Last occurrence of '" << ch << "' is at: " <<    found << "\n";
            std::cout << "Offset: " << (found - text) << "\n";
        } 
        else {
            std::cout << "Character not found!\n";
        }

        return 0;
    }

📤 Output:
=== strrchr ===
Last occurrence of 'o' is at: orld!
Offset: 8
🔬 Visual Pointer Behavior
For string: "Hello, World!"

Index	Char
0	H
1	e
2	l
3	l
4	o
5	,
6	
7	W
8	o
9	r
...	

⚠️ Common Mistakes
Not checking for nullptr return	
 - Dereferencing crash

Using strchr for substring search	
 - Only works for characters

Confusing strchr vs strrchr	
 - Wrong position result

Passing int outside 0–255 for char	
 - Undefined behavior
*/
