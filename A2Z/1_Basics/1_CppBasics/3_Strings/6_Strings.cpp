/*
=================================================================
            C++ STRINGS MASTER NOTES (PART 6)
      ADVANCED FEATURES + PERFORMANCE + MISCELLANEOUS
=================================================================

=================================================================
🔹 1. string::npos
=================================================================

string::npos represents an invalid position.

Example:

string s="hello";

if(s.find('x')==string::npos)
{
    cout<<"Not Found";
}

Value:

Very large unsigned number

Used with:

find()
rfind()
find_first_of()
find_last_of()

=================================================================
🔹 2. begin() and end()
=================================================================

string s="Programming";

begin() -> first character

end() -> one past last character

Example:

for(auto it=s.begin();it!=s.end();it++)
{
    cout<<*it;
}

Output:

Programming

=================================================================
🔹 3. Reverse Iterators
=================================================================

rbegin()
rend()

Example:

string s="Hello";

for(auto it=s.rbegin();it!=s.rend();it++)
{
    cout<<*it;
}

Output:

olleH

=================================================================
🔹 4. assign()
=================================================================

string s;

s.assign("Hello");

Output:

Hello

----------------------------------

string s;

s.assign(5,'A');

Output:

AAAAA

Complexity:

O(n)

=================================================================
🔹 5. append()
=================================================================

string a="Hello";

a.append(" World");

Output:

Hello World

Complexity:

O(m)

=================================================================
🔹 6. insert()
=================================================================

string s="Helo";

s.insert(2,"l");

Output:

Hello

Complexity:

O(n)

=================================================================
🔹 7. erase()
=================================================================

string s="Programming";

s.erase(3,4);

Output:

Proing

Complexity:

O(n)

=================================================================
🔹 8. replace()
=================================================================

string s="I love Java";

s.replace(7,4,"C++");

Output:

I love C++

Complexity:

O(n)

=================================================================
🔹 9. substr()
=================================================================

string s="Programming";

cout<<s.substr(3,4);

Output:

gram

Complexity:

O(length)

=================================================================
🔹 10. Copy Constructor
=================================================================

string a="Hello";

string b=a;

Both become independent.

Changing one doesn't affect the other.

Complexity:

O(n)

=================================================================
🔹 11. Move Semantics (C++11)
=================================================================

string a="Programming";

string b=move(a);

Ownership transferred.

a becomes valid but unspecified.

Useful for efficiency.

Complexity:

O(1)

=================================================================
🔹 12. Swap Strings
=================================================================

string a="ABC";
string b="XYZ";

swap(a,b);

Complexity:

O(1)

Very efficient.

=================================================================
🔹 13. Concatenation Performance
=================================================================

Inefficient:

string ans="";

for(char ch:s)
{
    ans=ans+ch;
}

Can become O(n²)

---------------------------------

Better:

string ans="";

for(char ch:s)
{
    ans.push_back(ch);
}

Complexity:

O(n)

=================================================================
🔹 14. reserve()
=================================================================

string s;

s.reserve(100000);

Avoids repeated reallocations.

Useful when size is known beforehand.

=================================================================
🔹 15. Capacity Growth
=================================================================

Suppose:

size=15
capacity=15

After adding one more character:

size=16

capacity becomes approximately:

30

Then:

60
120
240

Growth factor depends on implementation.

=================================================================
🔹 16. Small String Optimization (SSO)
=================================================================

Small strings are often stored inside the string object itself.

Example:

string s="Hello";

May not allocate heap memory.

Benefits:

✔ Faster
✔ Less memory
✔ Fewer allocations

=================================================================
🔹 17. C-style Conversion
=================================================================

string s="Hello";

const char* ptr=s.c_str();

Useful with:

printf()
scanf()
legacy C APIs

=================================================================
🔹 18. Mutable Characters
=================================================================

string s="Hello";

s[0]='M';

Output:

Mello

Unlike Java strings, C++ strings are mutable.

=================================================================
🔹 19. Comparison Complexity
=================================================================

s1==s2

Worst Case:

O(min(n,m))

Lexicographical comparison:

<
>
<=
>=

Also:

O(min(n,m))

=================================================================
🔹 20. Important Headers
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
🔹 21. String as Container
=================================================================

String supports:

begin()
end()

reverse()

sort()

count()

find()

min_element()

max_element()

accumulate()

Because string behaves like a container of chars.

=================================================================
🔹 22. Common Competitive Programming Tricks
=================================================================

Reverse:

reverse(s.begin(),s.end());

----------------------------------

Sort:

sort(s.begin(),s.end());

----------------------------------

Remove duplicates:

sort(s.begin(),s.end());

s.erase(unique(s.begin(),s.end()),s.end());

----------------------------------

Count character:

count(s.begin(),s.end(),'a');

----------------------------------

Remove character:

s.erase(remove(s.begin(),s.end(),'a'),s.end());

=================================================================
🔹 23. Common Character Ranges
=================================================================

Digits:

'0' to '9'

Uppercase:

'A' to 'Z'

Lowercase:

'a' to 'z'

Difference:

'a'-'A'=32

=================================================================
🔹 24. String Memory Complexity
=================================================================

Length = n

Memory:

O(n)

Extra capacity may increase actual allocated memory.

=================================================================
🔹 25. Best Practices
=================================================================

✔ Prefer std::string over char arrays

✔ Use const string& in function parameters

✔ Use getline() for full line input

✔ Use push_back() instead of repeated +

✔ Use reserve() if size is known

✔ Use frequency arrays for lowercase letters

✔ Use unordered_map for large character sets

✔ Use string::npos when checking find()

=================================================================
*/
