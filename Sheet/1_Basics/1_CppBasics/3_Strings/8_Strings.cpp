/*
=================================================================
            C++ STRINGS MASTER NOTES (PART 8)
        MISCELLANEOUS + OBSCURE + USEFUL TOPICS
=================================================================

=================================================================
🔹 1. raw string literals
=================================================================

Normal string:

string s="Hello\nWorld";

Output:

Hello
World

------------------------------------------------------------

Raw string:

string s=R"(Hello\nWorld)";

Output:

Hello\nWorld

Useful for:

✔ Regex
✔ File paths
✔ Multi-line strings

Example:

string path=R"(C:\Users\Naman\Desktop\file.txt)";

=================================================================
🔹 2. Escape Sequences
=================================================================

\n      New line
\t      Tab
\\      Backslash
\"      Double quote
\'      Single quote
\0      Null character

Example:

cout<<"Hello\nWorld";

Output:

Hello
World

=================================================================
🔹 3. Multi-line String Literal
=================================================================

string s=R"(Line 1
Line 2
Line 3)";

Output:

Line 1
Line 2
Line 3

=================================================================
🔹 4. getline() with Delimiter
=================================================================

string s;

getline(cin,s,',');

Input:

apple,banana,mango

Output:

apple

Stops when ',' is found.

=================================================================
🔹 5. stoi with position parameter
=================================================================

string s="123abc";

size_t pos;

int x=stoi(s,&pos);

x = 123

pos = 3

Meaning:

Digits ended at index 3.

=================================================================
🔹 6. Numeric Base Conversion
=================================================================

string s="1010";

int x=stoi(s,nullptr,2);

Output:

10

------------------------------------------------------------

Hexadecimal:

string s="1A";

int x=stoi(s,nullptr,16);

Output:

26

=================================================================
🔹 7. Lexicographical Sorting
=================================================================

vector<string> v={"cat","apple","bat"};

sort(v.begin(),v.end());

Output:

apple
bat
cat

Complexity:

O(n log n)

=================================================================
🔹 8. Custom Sorting by Length
=================================================================

bool cmp(string a,string b)
{
    return a.size()<b.size();
}

sort(v.begin(),v.end(),cmp);

Complexity:

O(n log n)

=================================================================
🔹 9. Lambda Comparator
=================================================================

sort(v.begin(),v.end(),
[](string a,string b)
{
    return a.size()<b.size();
});

=================================================================
🔹 10. String Hashing Concept
=================================================================

Idea:

Convert string into number.

Used in:

✔ Rabin-Karp
✔ Duplicate substring problems
✔ String matching

Common Formula:

hash=(hash*p+value)%MOD

Usually:

p=31

MOD=1e9+7

=================================================================
🔹 11. Prefix Function Concept
=================================================================

Used in KMP.

Stores:

Longest proper prefix
which is also suffix.

Complexity:

O(n)

=================================================================
🔹 12. String Compression
=================================================================

Example:

aaabbcccc

Compressed:

a3b2c4

Used in:

Leetcode 443

=================================================================
🔹 13. Remove Consecutive Duplicates
=================================================================

string s="aaabbbcc";

s.erase(unique(s.begin(),s.end()),s.end());

Output:

abc

Complexity:

O(n)

=================================================================
🔹 14. Counting Words
=================================================================

string s="I love C++";

stringstream ss(s);

string word;

int cnt=0;

while(ss>>word)
{
    cnt++;
}

Output:

3

Complexity:

O(n)

=================================================================
🔹 15. Most Important Headers
=================================================================

<string>
<cstring>
<cctype>
<sstream>
<algorithm>
<numeric>
<regex>
<string_view>

=================================================================
🔹 16. Common String Containers
=================================================================

vector<string>

set<string>

unordered_set<string>

map<string,int>

unordered_map<string,int>

priority_queue<string>

=================================================================
🔹 17. Frequently Used Interview Tricks
=================================================================

Reverse words:

stringstream

------------------------------------------------------------

Character frequency:

int freq[26];

------------------------------------------------------------

Anagram:

sort(s.begin(),s.end());

------------------------------------------------------------

Palindrome:

Two pointers

------------------------------------------------------------

Longest substring:

Sliding window

------------------------------------------------------------

Pattern matching:

KMP

------------------------------------------------------------

Prefix search:

Trie

=================================================================
🔹 18. Summary
=================================================================

Beginner:

Declaration
Input
size()
length()
substr()
find()

Intermediate:

append()
erase()
replace()
stringstream()
iterators

Advanced:

Sliding Window
Hashing
Trie
KMP
Rabin-Karp
Regex
Unicode

=================================================================
*/
