/*
🔹 Overview of strcmp
strcmp is a function in the C++ <cstring> header (also in C <string.h>) used to compare two C-style strings (char* or const char*).

🔹 Syntax
    #include <cstring>

    int strcmp(const char* str1, const char* str2);
Returns:
0 → if both strings are equal.
< 0 → if str1 is less than str2 (lexicographically).
> 0 → if str1 is greater than str2 (lexicographically).

🔹 How It Works Internally
Compares characters one by one.
Stops when:
A mismatch is found.
A null terminator '\0' is reached.

// Pseudo-implementation
    int strcmp(const char* s1, const char* s2) {
        while (*s1 && (*s1 == *s2)) {
            s1++;
            s2++;
        }
        return *(unsigned char*)s1 - *(unsigned char*)s2;
    }

🔹 Example Usage
    #include <iostream>
    #include <cstring>
    using namespace std;

    int main() {
        const char* a = "apple";
        const char* b = "banana";

        int result = strcmp(a, b);
    
        if (result == 0)
            cout << "Equal\n";
        else if (result < 0)
            cout << "a < b\n";
        else
            cout << "a > b\n";

        return 0;
    }

🔹 Important Properties
Property	            Value
Header	                <cstring>
Time Complexity     	O(min(len1, len2))
Space Complexity	    O(1) – in-place comparison
Null-Safe?	            ❌ Undefined behavior if any pointer is nullptr
Case-Sensitive?	        ✅ Yes
Modifies Data?	        ❌ No (pure function)

🔹 Edge Cases
Case	                            Behavior
Both strings empty	                Returns 0
One empty, one non-empty	        Returns <0 or >0 depending on order
One nullptr, one valid string	    ❌ Undefined behavior (don’t use)
Strings with different lengths	    Compared until mismatch or '\0'
Non-ASCII characters (UTF-8 etc.)	Byte-by-byte comparison; might break


🔹 Real Use Case in Competitive Programming
    char str1[100], str2[100];
    cin >> str1 >> str2;

    if (strcmp(str1, str2) == 0) {
        cout << "Equal\n";
    } 
    else {
        cout << "Not Equal\n";
    }

⚠️ Pitfall: When input exceeds buffer size, it causes overflow or segmentation fault. Use std::string for safety in contests unless memory/time is critical.

🔹 Common Variants
Function	        Description
strncmp()	        Compare first n characters
strcasecmp()	    Case-insensitive comparison (non-standard)
strcoll()	        Locale-aware comparison

🔹 Comparison Table
Code Snippet	        Output	            Reason
strcmp("abc", "abc")	0	                Strings are equal
strcmp("abc", "abd")	< 0	                'c' < 'd'
strcmp("abd", "abc")	> 0	                'd' > 'c'
strcmp("abc", "ab")	    > 0	                Extra 'c' in first string
strcmp("ab", "abc")	    < 0	                Missing 'c' in first string
*/
