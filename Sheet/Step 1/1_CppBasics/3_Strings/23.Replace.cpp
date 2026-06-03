/*
🔁 replace(): Replace Part of a String
✅ Purpose:
Replaces a portion of the string with new characters or another string.

🔧 Function Overloads:
There are many overloads, but the most important ones are:
// 1. Replace [pos, pos+len) with another string
string& replace(size_t pos, size_t len, const string& str);

// 2. Replace with substring of another string
string& replace(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen);

// 3. Replace with C-string
string& replace(size_t pos, size_t len, const char* s);

// 4. Replace with repeated characters
string& replace(size_t pos, size_t len, size_t n, char c);

💻 Example 1: Replace portion with another string
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "RealMadrid";
    s.replace(4, 6, "Sociedad");  // Replace "Madrid" with "Sociedad"
    cout << s << endl;
    return 0;
}

/*
🧾 Output:
RealSociedad

💻 Example 2: Replace using substring from another string
    string s = "Barcelona";
    string src = "AtleticoMadrid";
    s.replace(0, 4, src, 0, 8); // Replace "Barc" with "Atletico"
    cout << s << endl;

🧾 Output:
Atleticolona

💻 Example 3: Replace with repeated characters
    string s = "GOAT";
    s.replace(1, 2, 5, '*'); // Replace "OA" with "*****"
    cout << s << endl;

🧾 Output:
G*****T

⚠️ Edge Cases
Case	                Behavior
pos > size()	        Throws out_of_range exception
len > size() - pos	    Replaces until end of string
replace(0, 0, "abc")	Just inserts at beginning
replace(...) with ""	Effectively erases that segment

📌 Use Cases
Editing parts of strings.
Implementing text editors.
Parsing and modifying structured strings (like paths, URLs, etc.).


*/
