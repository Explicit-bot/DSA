/*
🔹 What is capacity() in std::string?
✅ Definition:
capacity() returns the size of the allocated storage space (in characters) for the string.
This value is always ≥ current size, and it tells how many characters you can store before a reallocation happens.

📌 Syntax:
    size_t capacity() const noexcept;
    
Returns the number of characters (not including the null terminator) that the string currently has allocated memory for.

✅ Example: Basic usage
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hola";
    cout << "Size: " << s.size() << endl;
    cout << "Capacity: " << s.capacity() << endl;
}

🧾 Output (example on GCC):
Size: 4
Capacity: 15
⚠️ Capacity is implementation-defined. Don’t expect same numbers across compilers or systems.

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    for (int i = 0; i < 100; ++i) {
        s += 'a';
        cout << "Length: " << s.length() << ", Capacity: " << s.capacity() << endl;
    }

}
/*
🧾 Output (example on GCC):
Length: 21, Capacity: 22
Length: 22, Capacity: 22
Length: 23, Capacity: 47

Length: 46, Capacity: 47
Length: 47, Capacity: 47
Length: 48, Capacity: 95

Length: 94, Capacity: 95
Length: 95, Capacity: 95
Length: 96, Capacity: 191

🧠 Why is capacity > size?
Because strings are dynamically allocated, they grow in chunks (often double the size) to avoid reallocating memory frequently.
    string s;
    for (int i = 0; i < 100; ++i) {
        s += 'a';
        cout << "Length: " << s.length() << ", Capacity: " << s.capacity() << endl;
    }

📈 You’ll observe capacity growing like:
Length: 15, Capacity: 15
Length: 16, Capacity: 31
Length: 32, Capacity: 47
...
This is amortized allocation — it grows in blocks.

✅ Edge Case: Reserve & Shrink
    string s = "Naman";
    s.reserve(100);
    cout << s.capacity(); // At least 100

    s.shrink_to_fit();
    cout << s.capacity(); // Likely reduced back closer to size (e.g., 5 or 15)

🧪 Memory Diagram:
Let’s say:
    string s = "Real";

Internally (simplified):
Allocated block: [R][e][a][l][\0][ ][ ][ ][ ]...[ ]  ← total 15 chars (capacity)
                   ↑            ↑
               size=4     capacity=15
✅ Real Use Cases:
Scenario	                Use of capacity()
Large append loop	        Pre-reserve memory using reserve()
Memory optimization	        Use shrink_to_fit() to trim unused space
Performance tuning	        Prevent frequent reallocations

⚠️ Don't do this:
    string s = "Hello";
    s[10] = 'X'; // ❌ Even if capacity ≥ 11, this is undefined behavior
→ capacity() tells how much can be stored, not what is valid to access.

*/
