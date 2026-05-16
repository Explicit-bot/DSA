/*
🔹 substr() – Extract Substring

✅ Purpose:
Returns a substring from the original string starting at a specific index, optionally for a specific length.

🔧 Syntax:
    string substr(size_t pos = 0, size_t len = npos) const;

🔹 Parameters:
pos: Starting index (0-based)

len: (Optional) Number of characters to extract
→ Default is npos (which means “till end”)

✅ Example 1 – Basic use:
    string s = "Vinicius Jr";
    string part = s.substr(0, 8);  // From index 0, extract 8 characters
    cout << part;

🧾 Output:
Vinicius

✅ Example 2 – Till end:
    string s = "Real Madrid";
    string club = s.substr(5);  // From index 5 to end
    cout << club;

🧾 Output:
Madrid

🧠 Internal Behavior:
A new string object is created and returned.
It does not modify the original string.
Internally copies the requested characters.

📘 Edge Cases:
Case	                            Behavior
substr(0, 0)	                    Returns empty string
substr(pos > s.length())	        ❌ Throws std::out_of_range
substr(pos, len > size)	            Extracts till end only
substr(pos)	                        Extracts till end from pos

🧪 Example 3 – Edge Case: out of range
    string s = "Bellingham";
    try {
        string bad = s.substr(20);  // ❌ Invalid
    } catch (out_of_range& e) {
        cout << "Caught: " << e.what();
    }

🧾 Output:
Caught: basic_string::substr: __pos (which is 20) > this->size() (which is 10)

📦 Memory Diagram:
    string s = "Ancelotti";
    string t = s.substr(3, 4);  // Extracts "celo"

s: [A][n][c][e][l][o][t][t][i]
          ↑       ↑
        start    len=4

t:           [c][e][l][o]

✅ Use Cases:
Extracting usernames, extensions, IDs
Parsing paths, logs, formats
String slicing for substrings

🧪 Bonus:
You can chain or combine:
    string name = "Luka Modric";
    string firstName = name.substr(0, name.find(' ')); // till space
    cout<<firstName;
    
🧾 Output:
Luka
*/
