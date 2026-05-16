/*
All Class string functions
🔹length() / size()
✅ Description:
Returns the number of characters in the string.
Both length() and size() are interchangeable.

🔧 Syntax:
    string_name.length()
    string_name.size()
    
✅ Use Case Preferences:
Use Case	       Preferred
Textual data	   length() – semantically clearer
Containers/data	   size() – consistent with other STL containers 
                   like vector, map, etc.

So, if you're working with a vector, set, or map, you'd use size(), and using size() on strings keeps it consistent. But if you're displaying or processing text, length() may better convey your intention.

✔️ In most C++ standard library implementations, yes — length() is often just a call to size() internally.
But per the C++ Standard, both must return the same result. So even if the internal mechanics differ slightly (they usually don’t), semantically and functionally they are identical.

✅ Example:
    string s = "OpenAI";
    cout << s.size() << endl;   // 6
    cout << s.length() << endl; // 6
Both output the same value.


✅ Example:
*/
#include <iostream>
#include <string>

int main(){
    std::string str1;

    std::cout<<"Enter your string:"<<std::flush;
    std::cin>>str1;

    std::cout<<"Length:"<<str1.length()<<"\n";
    std::cout<<"Size:"<<str1.size()<<"\n";
    
}

/*
⚠️ Edge Cases:
1. Empty string
    string s = "";
    cout << s.length(); // 0

2. String with whitespace
    string s = "   ";
    cout << s.length(); // 3

3. Unicode characters
C++ std::string counts bytes, not actual UTF-8 characters if multibyte characters are used.
    string s = "नमस्ते"; // Hindi (UTF-8), 6 chars but more than 6 bytes
    cout << s.length(); // Output depends on system/compiler 
                        (could be > 6)

To handle Unicode properly, use wstring or libraries like ICU.

🧠 Memory Diagram (for string s = "Hello";)
Stack:
+---------+
|   s     | ---> Heap
+---------+

Heap:
+-----------+-----------+-----------+-----------+-----------+--------+
|     'H'   |   'e'     |   'l'     |   'l'     |   'o'     | '\0'   |
+-----------+-----------+-----------+-----------+-----------+--------+

Length: 5 (excluding \0)
Internally, C++ std::string manages memory automatically (may over-allocate for performance).
*/
