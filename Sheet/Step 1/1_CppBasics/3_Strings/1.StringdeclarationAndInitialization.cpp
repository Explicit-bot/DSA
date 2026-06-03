/*
✅ What is a String in C++?
A string is a sequence of characters used to represent text.
In C++, strings can be created and handled in two main ways:
🔹 1. C-style strings (char[])
🔹 2. C++ std::string class

✅ What is a C-Style String?
A C-style string is an array of characters ending with a null character '\0', which marks the end of the string.

🔹 Ways to Declare and Initialize Character Arrays
1. Implicit size (auto null terminator) ✅
    
    char str[] = "Hello";  
Size is automatically set to 6 ('H', 'e', 'l', 'l', 'o', '\0').
Null character is added automatically.

2. Explicit size with string literal

    char str[10] = "Hello";  
Extra space is unused.
It's size is 6 as H,e,l,l,o,\0.
Useful when you expect to modify or expand the string later.

3. Character-by-character initialization

    char alp[] = {65,66,67,68,"\0"};  //Output: ABCD
    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};  
You must manually add the null terminator '\0'.
❌ If '\0' is missing, it won't be treated as a valid string.

4. Uninitialized character array
    char str[100];  
    
    cin.getline(str, 100);  // Reads input with spaces
    Used when taking input at runtime.

5. Pointer to string literal
        char* str = "Hello";  
    //✅ Works, but string is stored in read-only memory
        str[0] = 'h';          
    //❌ Undefined behavior (modifying read-only memory)
Use only for reading, not modifying.

Actually, modern compilers will warn you about this:
    char* str = "Hello"; // ⚠️ warning: ISO C++ forbids conversion from string literal to 'char*'
Because string literals are constant, the proper way to declare this should be:
    const char* str = "Hello";


🛠️ Useful Functions from <cstring>
Function	            Description
strlen(str)	            Returns length (excluding '\0')
strcpy(dest, src)	    Copies a string
strcmp(a, b)	        Compares two strings
strcat(a, b)	        Concatenates strings
strchr(str, 'c')	    Finds first occurrence of char

✅ Example Code
        #include <iostream>
        #include <cstring>
        using namespace std;

        int main() {
            char name[20] = "Naman";
    
            cout << "Name: " << name << endl;
            cout << "Length: " << strlen(name) << endl;

            strcat(name, " Mishra");
            cout << "Full name: " << name << endl;

            return 0;
        }
        

✅ What is std::string?
std::string is a class in the C++ Standard Library.
It represents a sequence of characters (i.e., text).
Safer, more flexible, and easier than using char[] (C-style strings).

Requires #include <string>

#include <string>
using namespace std;  // optional, otherwise use std::string

📦 1. Declaration and Initialization
✅ Empty string:
    string s;

✅ Initialization with a literal:
    string s = "Hello";

✅ Constructor-style initialization:
    string s("Hello");  //*Should prefer this 

✅ Copy another string:
    string s1 = "Hi";
    string s2 = s1;

✅ Repeat a character:
    string s(5, '*');  // s = "*****"

✅ Substring from another string:
    string s1 = "Welcome";
    string s2(s1, 3, 4);  // s2 = "come"

🧠 Internal Behavior
Internally, std::string stores characters in heap memory.
Automatically resizes as needed (unlike arrays).
Null-terminated internally, but you don’t need to handle it.

❓ “When I do std::string s = "Hello";, why don’t I need to specify the size of the string like I do with char[]?”

✅ Short Answer:
No — you don’t need to specify the size when using std::string.
It automatically calculates the size of the string literal using the null terminator (\0) at the end of "Hello".

🔎 Behind the Scenes
When you write:
    std::string s = "Hello";

    Here’s what actually happens:

"Hello" is a string literal: const char[6] (includes the null terminator '\0')

The compiler sees this and calls:
    std::string::string(const char* s);

The constructor internally calls strlen(s) to calculate how long the string is before \0
Then it allocates memory and copies the characters into a managed buffer
So no size needs to be mentioned by the programmer — std::string handles it automatically.

🔁 Compare With C-Style Strings
C-style (you must declare size or initialize directly):
    char arr1[6] = "Hello";    // manual size
    char arr2[]  = "Hello";    // auto size, still fixed
If you forget the \0 or miscount the size:
❌ Risk of buffer overflows
❌ No built-in size tracking

C++ std::string:
    std::string s = "Hello";   // size is 5, managed internally

✅ Dynamic size
✅ Safe memory management
✅ Automatic null handling (you don’t even need to worry about it)

"Why did you say the size is 5 when "Hello" is 6 characters including '\0'?"

🧠 Clarifying the Difference:
When you write:
    const char* s = "Hello";  // "Hello" is stored as: ['H', 'e', 'l', 'l', 'o', '\0']

✅ The array size of the string literal is 6 (char[6])
It includes the null terminator ('\0')
✅ The length of the string content is 5 (just the visible characters)

🔷 So why does std::string store size as 5?
std::string str = "Hello";
Internally:
It takes the pointer to "Hello" (const char*)
Calculates the length using strlen() — which stops at '\0'
So:
    std::strlen("Hello") → 5
It does not store the '\0' as part of the logical string — though it may keep it internally to support .c_str().

🔎 Extra Detail:
    std::string s = "Hello";
    std::cout << s.length();    // prints 5
    std::cout << s.size();      // also prints 5

If you do:
    std::cout << strlen("Hello");  // prints 5
But:
    sizeof("Hello") → 6   // array size, includes '\0'


✏️ 2. Input and Output
🔸 Word input (single word):
    string name;
    cin >> name;  // reads until space

🔸 Full line input (with spaces):
    getline(cin, name);
⚠️ Note: After cin >>, use cin.ignore() before getline().

🔍 3. Accessing Characters
    string s = "World";

        char ch = s[0];    // W
        s[1] = 'A';        // s = "WArld"
        s.at(2);           // Safe access (throws exception if out of bounds)

🧮 4. Properties and Checks
Property	        Example
Size / Length	    s.size(), s.length()
Check empty	        s.empty()
Last character	    s.back()
First character	    s.front()

🛠️ 5. Modifying Strings
Operation	    Code Example
Append	        s.append("!!!"); or s += "!!!";
Insert	        s.insert(2, "abc");
Erase	        s.erase(3, 2);
Replace	        s.replace(0, 3, "New");
Clear	        s.clear();

🔍 6. Substrings and Search

string s = "HelloWorld";

s.substr(5);         // "World"
s.substr(0, 5);      // "Hello"
s.find("lo");        // returns 3
s.rfind("l");        // returns last occurrence
🔄 7. Comparing Strings
    if (s1 == s2)     // true if equal
    s1 != s2;         // not equal
    s1.compare(s2);   // 0 if equal, <0 if s1 < s2, >0 otherwise
    
🔁 8. Iterating Through Strings
🔸 Using index:
    for (int i = 0; i < s.size(); ++i)
        cout << s[i];
🔸 Range-based for:
    for (char c : s)
        cout << c;
🔸 With reference (to modify):

    for (char &c : s)
        c = toupper(c);
🔁 9. Conversions
String → int, float:
    int x = stoi("123");
    float y = stof("3.14");

int, float → String:
    string s = to_string(456);

🔗 10. Common Use-Cases in Competitive Programming
Task	                Function
Check Palindrome	    Reverse and compare
Count characters	    Use map<char, int>
Extract substrings	    substr(start, len)
Concatenate	            + or .append()
Fast input (line)	    getline()

🧪 Example Program
    #include <iostream>
    #include <string>
    using namespace std;

    int main() {
        string name;

        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Hi " << name << "! Your name has " << name.size() << " characters.\n";

        name += "123";
        cout << "Modified: " << name << "\n";

        return 0;
    }
*/
