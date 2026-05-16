/*
🔹  push_back(char ch)
✅ Purpose:
Appends a single character at the end of the string.

🧠 Syntax:
    str.push_back('x');

📌 Example:
    std::string str = "Real";
    str.push_back('M');
    std::cout << str << std::endl;  // Output: RealM

💡 Edge Cases:
Works even on empty strings: std::string s = ""; s.push_back('A'); → A
Accepts only a single character, not a string.

🧠 Memory Note:
If the capacity is insufficient, reallocation happens internally.
std::string handles null-termination automatically.

🔹 pop_back()
✅ Purpose:
Removes the last character of the string.

🧠 Syntax:
    str.pop_back();

📌 Example:
    std::string str = "Madrid";
    str.pop_back();
    std::cout << str << std::endl;  // Output: Madri


💡 Edge Cases:
⚠️ Undefined behavior if string is empty. Always check first:
if (!str.empty()) str.pop_back();

🧠 Memory Note:
Capacity doesn’t shrink — only size changes.
Null-terminator is still maintained.
*/
#include <iostream>
#include <string>

int main() {
    std::string team = "Real";

    // Demonstrating push_back
    std::cout << "Original string: " << team << std::endl;
    team.push_back('M');
    std::cout << "After push_back('M'): " << team << std::endl;

    // Demonstrating pop_back
    team.pop_back();  // removes 'M'
    std::cout << "After pop_back(): " << team << std::endl;

    // Edge Case: pop_back on empty string
    std::string empty = "";
    std::cout << "Empty string before push_back: \"" << empty << "\"" << std::endl;

    empty.push_back('A');
    std::cout << "After push_back('A'): \"" << empty << "\"" << std::endl;

    empty.pop_back(); //here empty='A';
    std::cout << "After pop_back(): \"" << empty << "\"" << std::endl;

    // ⚠️ Uncommenting below will cause undefined behavior!
    // empty.pop_back();  // popping from empty string again – should be avoided

    return 0;
}
/*
🧾 Output:
Original string: Real
After push_back('M'): RealM
After pop_back(): Real
Empty string before push_back: ""
After push_back('A'): "A"
After pop_back(): ""

⚠️ Important Notes:
push_back(char) appends a single character to the end.
pop_back() removes the last character, but must not be called on an empty string.
You can check with if (!str.empty()) before calling pop_back() to stay safe.
*/
