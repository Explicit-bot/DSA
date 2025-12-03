/*
🔹 swap(std::string& other)
✅ Purpose:
Swaps the contents of two strings in constant time.

🧠 Syntax:
    str1.swap(str2);

💡 Edge Cases:
Works even if one string is empty.
Can be used with temporary strings: str.swap(std::string("temp"));

🧠 Memory Note:
It just swaps pointers (internally), so it’s fast (O(1) complexity).
Capacity is also swapped.

📌 Example:
*/

#include <iostream>
#include <string>
int main() {
    std::string a = "Real";
    std::string b = "Madrid";

    a.swap(b);

    std::cout << "a: " << a << std::endl;  // Output: a: Madrid
    std::cout << "b: " << b << std::endl;  // Output: b: Real
}
