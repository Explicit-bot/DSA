/*
1. 🧵 max_size()
✅ What it does:
Returns the maximum number of characters a std::string object can theoretically hold, which depends on system limits and the implementation of the STL.

📌 Syntax:
    size_type max_size() const noexcept;

🧪 Example:
    #include <iostream>
    #include <string>
    using namespace std;

    int main() {
        string s = "Naman";
        cout << "Max size of string: " << s.max_size() << endl;
    }

📤 Output (typical 64-bit system):
Max size of string: 4611686018427387899

⚠️ You can’t actually reach this size—it’s an upper bound for safety checks. Real allocations will run out of memory way earlier.


❓ What's the point of max_size() if it can't actually allocate that much?
🔹 max_size() is not meant to be used for allocation.
It serves as a theoretical upper bound — to prevent bugs, crashes, and overflows.

✅ Why it exists — Real Purposes of max_size()
1. Safety checks before heavy operations
Say you're writing a function that appends user input:
    std::string s = "Real";
    std::string user_input = getVeryLongInput();

    if (s.size() + user_input.size() > s.max_size()) {
        throw std::length_error("Result would exceed string max size!");
    } else {
        s += user_input;
    }

✅ max_size() helps prevent logic bugs, buffer overflows, and memory corruption.

2. Debugging + Portability
Different systems or STL implementations have different max_size() limits:
On 64-bit systems: might be ~2^60 characters
On 32-bit systems: ~2^30 or less

You can use max_size() to write code that:
adapts to the platform
behaves predictably
avoids undefined behavior

3. Validating APIs or constraints
When designing a library or API:
    void setUserInput(std::string input) {
        if (input.size() > input.max_size()) {
            throw std::invalid_argument("Input too large");
        }
        // safe to store input
    }

This avoids users crashing your code by passing gigabytes of junk.

🧠 Analogy:
Think of max_size() like the maximum speed on your car’s speedometer (e.g., 320 km/h).
You’ll never hit it, but it helps:
Know the engine’s upper safe limit
Avoid overdriving it
Design safer systems (e.g., speed limiters)

2. ✂️ resize(n)
✅ What it does:
Resizes the string to size n.
If n < size() → truncates the string.
If n > size() → appends '\0' characters (null chars).

📌 Syntax:
    void resize(size_t n);

🧪 Example:
    string s = "RealMadrid";
    s.resize(4);    // Truncates to "Real"
    cout << s << endl;

    s.resize(10);   // Adds 6 '\0' null chars (invisible)
    cout << "Size: " << s.size() << endl;

🧤 Output:
Size: 10

💡 Memory Diagram:
Before:
s: ['R','e','a','l','M','a','d','r','i','d']

After resize(4):
s: ['R','e','a','l']      //internally there is always a \0 at the end for c_str
                          //Size will be 4 but not capacity
After resize(10):
s: ['R','e','a','l','\0','\0','\0','\0','\0','\0']
'\0' chars will break many string operations (e.g., cout << s may stop at the first '\0').

3. ✏️ resize(n, c)
✅ What it does:
Same as resize(n), but fills with custom character c instead of '\0'.

🧪 Example:
    string s = "Madrid";
    s.resize(10, '*');
    cout << s << endl;

📤 Output:
Madrid****

🧤 Memory Layout:
s: ['M','a','d','r','i','d','*','*','*','*']

4. 🚀 reserve(n)
✅ What it does:
Requests that the capacity of the string be at least n. It doesn't affect size, only reserved memory.

📌 Syntax:
    void reserve(size_t n);

🧪 Example:
    string s = "RM";
    cout << "Before reserve: " << s.capacity() << endl;
    s.reserve(100);
    cout << "After reserve: " << s.capacity() << endl;

🧤 Output:
Before reserve: 15
After reserve: 100
💡 Memory Note:
    s = "RM";           // size = 2, capacity = 15 (maybe)
    s.reserve(100);     // now capacity = 100

⚠️ Edge Cases:
If n < current capacity → does nothing.
If n > max_size() → throws length_error.

5. 🧽 shrink_to_fit()
✅ What it does:
Requests the string to reduce its capacity to match the current size.

📌 Syntax:
    void shrink_to_fit();

🧪 Example:
    string s = "Madridista";
    s.reserve(100);
    cout << "Before shrink: " << s.capacity() << endl;

    s.shrink_to_fit();
    cout << "After shrink: " << s.capacity() << endl;

📤 Output:
Before shrink: 100
After shrink: 10
It’s a non-binding request. Some compilers may not shrink exactly.

🧪 Example Demonstrating All:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Real";
    string s1 = "RealMadrid";

    s1.resize(4);    // Truncates to "Real"
    cout << s1 << ", capacity: " << s1.capacity()<< endl;

    s.resize(6, '_');
    cout << s << " | size: " << s.size() << ", capacity: " << s.capacity() << endl;

    s.reserve(100);
    cout << "After reserve: capacity = " << s.capacity() << endl;

    s.shrink_to_fit();
    cout << "After shrink: capacity = " << s.capacity() << endl;
}

/*
🧾 Output:
Real__ | size: 6, capacity: 22
After reserve: capacity = 103
After shrink: capacity = 22
*/
