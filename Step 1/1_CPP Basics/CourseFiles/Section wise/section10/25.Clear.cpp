/*
🔹 clear() – Erase the Entire String
✅ Purpose:
Removes all characters from the string. After calling clear(), the string becomes empty.

When you call s.clear();, the string becomes empty, meaning:
The size becomes 0
Internally, it's like the string starts and ends at a null terminator ('\0')
But it's not like only '\0' is "stored" — it's just how C++ treats an empty string

🔧 Syntax:
    void clear();

🧪 Example:
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hala Madrid";
    cout << "Before clear: " << s << " | Size: " << s.size() << endl;

    s.clear(); // Clears all content

    cout << "After clear: '" << s << "' | Size: " << s.size() << endl;

    return 0;
}

/*
🧾 Output:
Before clear: Hala Madrid | Size: 11
After clear: '' | Size: 0

🧠 Internals:
clear() does NOT deallocate capacity — it just sets size to 0.
Internally, string data is kept (to reuse it later).

📘 Edge Cases:
Case	                            Behavior
Clear an already empty string	    No error; remains empty
Use s[0] after clear	            ❌ Undefined behavior (don’t!)
Memory reused after clearing	    ✅ Yes — new data uses same space

📦 Memory Visualization:
Before clear():
s = "Hala Madrid"
          ↑
[H][a][l][a][ ][M][a][d][r][i][d]

After clear():
    s = ""

(capacity is still allocated internally)

✅ When to Use:
Resetting string between inputs.
Reusing string in loops.
Clearing sensitive info like passwords.

🧪 Bonus:
You can also check if the string is empty after clearing:
    if (s.empty()) {
        cout << "String is empty\n";
    }
*/
