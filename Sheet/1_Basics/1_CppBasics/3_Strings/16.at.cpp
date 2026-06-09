/*
🔹 at(index)

✅ Description:
Returns a reference to the character at the specified index.
Performs bounds checking: throws std::out_of_range if the index is invalid.

🔧 Syntax:
    char& at(size_t pos);
    const char& at(size_t pos) const;

✅ Use Case:
Use at() when you want to safely access a character with protection against accessing out-of-bounds memory (unlike operator[]).

✅ Example:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "OpenAI";
    cout << "Character at index 2: " << s.at(2) << endl;

    s.at(3) = 'X';  // modify character
    cout << "Modified string: " << s << endl;

    return 0;
}
/*

⚠️ Exception Case (Edge Case):
    #include <iostream>
    #include <string>
    using namespace std;

    int main() {
        string s = "AI";

        try {
            cout << s.at(10); // Out of bounds!
        } catch (const out_of_range& e) {
            cout << "Exception: " << e.what() << endl;
        }

        return 0;
    }

🔸 Output:
    Exception: basic_string::at: __n (which is 10) >= this->size() (which is 2)

🔍 What is catch (const out_of_range& e)?
This is part of C++ exception handling. Specifically:
std::string::at() throws a std::out_of_range exception if the index is invalid.
This catch block is used to handle that exception safely.

✅ What is e.what()?
It's a member function of the base class std::exception
Returns a C-style string (const char*) that describes the error

🧠 Internal Behavior:
Let’s say:
    string s = "World";

Then:
    s.at(0) → 'W'  
    s.at(4) → 'd'  
    s.at(5) → ❌ throws out_of_range exception
Internally, at(pos) checks:
    if (pos >= this->size())
        throw std::out_of_range("string::at");
    else
        return *(this->_M_data + pos);

✅ Comparison with [] Operator:
Feature	                at()	            operator[]
Bounds checked	        ✅ Yes	            ❌ No
Throws exception	    ✅ If out-of-range	❌ Undefined behavior
Safe for risky inputs	✅ Recommended	    ⚠️ Use carefully
Performance	            Slightly slower	    Faster

🧪 Edge Case Tests:
1. Empty string
    string s = "";
    s.at(0); // throws std::out_of_range

2. Valid boundary
    string s = "abc";
    cout << s.at(2); // 'c'

3. Modify character
    string s = "abc";
    s.at(1) = 'z';
    cout << s; // "azc"
*/
