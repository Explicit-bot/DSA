/*
🔹 Operator Overloads in std::string
C++ std::string supports several overloaded operators that make string operations intuitive. Here's a breakdown:

✅ 1. + (Concatenation)
Usage: Combines two strings or a string and character(s).

Syntax:
    std::string result = str1 + str2;
    
Example:
    std::string a = "Real";
    std::string b = "Madrid";
    std::string c = a + " " + b;
    std::cout << c;  // Output: Real Madrid

Edge Cases:
Concatenating with empty strings: "Real" + "" → "Real"
"a" + 1 → ❌ Invalid (must use string or character)

✅ 2. += (Append)
Usage: Appends to an existing string in place.

Example:
    std::string name = "Real";
    name += " Madrid";
    std::cout << name;  // Output: Real Madrid

Also works with chars:
    name += '!';  // Real Madrid!

✅ 3. ==, != (Equality and Inequality)
Usage: Compare if strings are exactly the same (character-wise).

Example:
    std::string a = "Goal";
    std::string b = "Goal";
    std::string c = "Miss";

    std::cout << (a == b) << "\n";  // true (1)
    std::cout << (a != c) << "\n";  // true (1)

Edge Cases:
Case-sensitive: "Goal" ≠ "goal"

✅ 4. <, >, <=, >= (Lexical Comparison)
Usage: Compares strings lexicographically (dictionary order, based on ASCII).

ASCII Order Note:
'A' < 'Z' < 'a' < 'z'

'A' (65), 'a' (97)

Example:
    std::string a = "Apple";
    std::string b = "Banana";

    std::cout << (a < b) << "\n";   // true (Apple < Banana)
    std::cout << ("Zebra" > "apple") << "\n";  // false (Z < a)

✅ 5. [] (Character Access)
Usage: Access or modify individual characters.

Syntax:
    char ch = str[i];
    str[i] = 'X';

Example:
    std::string s = "World";
    std::cout << s[0];  // Output: W
    s[1] = 'A';
    std::cout << s;     // Output: WArld

Edge Cases:
No bounds checking: str[100] is undefined behavior
Use .at(i) for bounds-checked access (throws exception)

✅ 6. <<, >> (Stream Insertion/Extraction)
Usage: Input/Output with std::cin and std::cout.

Output Example:
    std::string msg = "Hala Madrid!";
    std::cout << msg << "\n";  // Output: Hala Madrid!

Input Example:
    std::string word;
    std::cin >> word;  // reads one word (stops at space)

Edge Cases:
std::cin >> str → only reads up to the first whitespace
Use getline(std::cin, str) to read full lines
*/
