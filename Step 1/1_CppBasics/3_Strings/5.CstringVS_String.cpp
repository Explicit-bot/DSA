/*
📘 Difference Between <cstring> and <string>
Feature	                             <cstring>	          <string>
From	                             C (via <string.h>)   C++
Type	                             char[], char*	      std::string
Null-terminated?	                 ✅ Yes	             ❌ Internally
                                                          managed
Memory safe?	                     ❌ No	             ✅ Yes
Supports operators (+, ==)	         ❌ No	             ✅ Yes
Can grow automatically?	             ❌ No	             ✅ Yes
Part of STL?	                     ❌ No	             ✅ Yes
Requires manual memory management?	✅ Yes	             ❌ No

🧠 1. Data Type
<cstring>: C-style String
    char name[] = "Naman";  // Array of characters

It’s just a char array ending with '\0'
No built-in length, resize, or safety

<string>: C++ std::string
    #include <string>
    std::string name = "Naman";  // High-level object

Provides rich methods like .length(), .substr(), .find(), .replace()
Automatically resizes

🛠️ 2. Syntax and Operations
✅ String Concatenation
With <cstring>:
    char a[20] = "Hello ";
    char b[] = "World";
    strcat(a, b);  // a = "Hello World"

With <string>:
    string a = "Hello ";
    string b = "World";
    string c = a + b;  // much simpler!

✅ String Comparison
<cstring>:
    strcmp("abc", "abc"); // 0 → equal

<string>:
    string a = "abc", b = "abc";
    if (a == b) cout << "Equal";  // intuitive!

✅ Length
<cstring>:
    char s[] = "abc";
    cout << strlen(s);  // Output: 3

<string>:
    string s = "abc";
    cout << s.length();  // Output: 3

💾 3. Memory Safety and Management
<cstring> is unsafe:
    char s[5];
    strcpy(s, "VeryLongString");  // ❌ Buffer overflow

<string> is safe:
    string s = "VeryLongString";  // ✅ Grows dynamically

🔍 4. Null-Termination
Type	            Ends with '\0?	                Needed for functions
C-style string	    ✅ Always	                   Yes (e.g. strlen())
std::string	        ❌ Not needed	               Internally managed

🔧 5. Convert Between the Two
std::string → C-string:
    string s = "hello";
    const char* cs = s.c_str();  // Read-only

C-string → std::string:
    char cs[] = "hello";
    string s = cs;

⚙️ 6. Performance Considerations
Case	                    <cstring>	    std::string
Small, fixed-size data	    ✅ Faster	    Slightly more overhead
Dynamic manipulation	    ❌ Painful	    ✅ Very easy
Competitive programming	    ✅ Often used	✅ Increasingly preferred
Low-level systems code	    ✅ Required	    ❌ Often not available
High-level applications	    ❌ Unsafe	    ✅ Ideal

⚠️ 7. Common Pitfalls
With <cstring>:
 - Buffer overflows
 - Forgetting null-terminator
 - Manual memory management
 - Can't use +, ==, etc.

With <string>:
 - Slightly more memory overhead
 - Needs #include <string>
 - Must use .c_str() with legacy APIs

✅ When to Use What?
Use Case	                            Recommended Type
Legacy C libraries	                    char* with <cstring>
Safe and modern string manipulation	    std::string
Performance-critical, small input	    char[]
C++ programs with dynamic string ops	std::string

🔹 getline() vs cin.getline() in C++
Feature	            std::getline()	                        cin.getline()
Header	            <string>	                            <iostream>
Works with	        std::string	                            C-style char[]
Null-terminator	    Handled internally (in std::string)	    Adds '\0' to the 
                                                            character array
Buffer size	        Grows dynamically	                    Must specify buffer size
Syntax	            std::getline(std::cin, str)	            std::cin.getline
                                                                    (buffer, size)
Use case	        Modern C++ strings	                    C-style char arrays

🔹 What happens when you call std::getline() twice on the same std::string variable?
Answer:
The second call to std::getline() completely overwrites the previous contents of the string.
It does not replace character-by-character — it replaces the entire value.

🔸 What's Actually Happening:
Each time you do:
    std::getline(std::cin, str);

It reads from input until a newline (\n) is encountered.
The contents of str are cleared.
Then, the new characters are inserted into str.
So, even if str had something like "Lionel Messi" earlier, the second input will fully replace it.

🔹 Example Program:
#include <iostream>
#include <string>

int main() {
    std::string player;

    std::cout << "Enter first player name: ";
    std::getline(std::cin, player);
    std::cout << "You entered: " << player << "\n";

    std::cout << "Enter second player name: ";
    std::getline(std::cin, player);
    std::cout << "Now player is: " << player << "\n";

    return 0;
}

🔹 Sample Input:
Enter first player name: Lionel Messi
Enter second player name: Cristiano Ronaldo

🔹 Output:
You entered: Lionel Messi
Now player is: Cristiano Ronaldo
✅ See? The second getline completely replaces the contents of player.

🔸 Memory Behind the Scenes
If you're wondering how the memory behaves, here's a simplified view:

Before 2nd getline:
player -> |L|i|o|n|e|l| |M|e|s|s|i|\0|

After 2nd getline (new input: "Cristiano Ronaldo"):
player -> |C|r|i|s|t|i|a|n|o| |R|o|n|a|l|d|o|\0|

std::string automatically manages memory and grows/shrinks as needed.
No leftover characters from the previous string.

*/
