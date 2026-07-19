/*
=================================================================
                C++ STRINGS MASTER NOTES (PART 4)
      CONVERSIONS + STRINGSTREAM + ITERATORS + C-STRINGS
=================================================================

This section covers:
✔ stoi(), stol(), stoll(), stof(), stod()
✔ to_string()
✔ stringstream
✔ Tokenization
✔ Iterators
✔ Passing strings to functions
✔ C-string functions
✔ String vs Character Array
✔ string_view
✔ Small String Optimization (SSO)

=================================================================
🔹 1. String to Integer Conversion : stoi()
=================================================================

Header:

#include<string>

-------------------------------------------------------------

string s="123";

int x=stoi(s);

cout<<x;

Output:

123

-------------------------------------------------------------

Negative numbers:

string s="-456";

int x=stoi(s);

Output:

-456

-------------------------------------------------------------

Leading spaces are ignored:

string s="   78";

stoi(s);

Output:

78

-------------------------------------------------------------

Stops at first invalid character:

string s="123abc";

stoi(s);

Output:

123

-------------------------------------------------------------

Invalid conversion:

string s="abc";

stoi(s);

Throws exception:
invalid_argument

-------------------------------------------------------------

Out of range:

string s="999999999999999999";

Throws:
out_of_range

Time Complexity:

O(n)

=================================================================
🔹 2. stol(), stoll()
=================================================================

long x=stol(s);

long long y=stoll(s);

Used for very large numbers.

=================================================================
🔹 3. stof(), stod()
=================================================================

string s="12.56";

float x=stof(s);

double y=stod(s);

Output:

12.56

=================================================================
🔹 4. to_string()
=================================================================

Converts numbers into strings.

int x=123;

string s=to_string(x);

Output:

"123"

-------------------------------------------------------------

double pi=3.14;

string s=to_string(pi);

Output:

"3.140000"

Time Complexity:

O(number of digits)

=================================================================
🔹 5. Stringstream
=================================================================

Header:

#include<sstream>

stringstream converts between strings and data.

=================================================================
🔹 Extract words
=================================================================

string s="I love C++";

stringstream ss(s);

string word;

while(ss>>word)
{
    cout<<word<<endl;
}

Output:

I
love
C++

Time Complexity:

O(n)

=================================================================
🔹 Convert string to integer
=================================================================

string s="456";

stringstream ss(s);

int x;

ss>>x;

Output:

456

=================================================================
🔹 Integer to string
=================================================================

stringstream ss;

int x=789;

ss<<x;

string s=ss.str();

Output:

"789"

=================================================================
🔹 Multiple values
=================================================================

string s="10 20 30";

stringstream ss(s);

int a,b,c;

ss>>a>>b>>c;

Output:

10 20 30

=================================================================
🔹 Tokenization using getline()
=================================================================

string s="apple,banana,mango";

stringstream ss(s);

string word;

while(getline(ss,word,','))
{
    cout<<word<<endl;
}

Output:

apple
banana
mango

Used heavily in parsing problems.

=================================================================
🔹 6. Iterators
=================================================================

string s="Hello";

-------------------------------------------------------------
begin()
-------------------------------------------------------------

Points to first character.

s.begin()

-------------------------------------------------------------
end()
-------------------------------------------------------------

Points AFTER last character.

s.end()

-------------------------------------------------------------
Example
-------------------------------------------------------------

for(auto it=s.begin();it!=s.end();it++)
{
    cout<<*it;
}

Output:

Hello

Time Complexity:

O(n)

=================================================================
🔹 Reverse Iterators
=================================================================

rbegin()
rend()

Example:

for(auto it=s.rbegin();it!=s.rend();it++)
{
    cout<<*it;
}

Output:

olleH

=================================================================
🔹 7. Passing Strings to Functions
=================================================================

-------------------------------------------------------------
Pass by Value
-------------------------------------------------------------

void fun(string s)

Copies whole string.

Changes do NOT affect original.

Complexity:

O(n)

-------------------------------------------------------------
Pass by Reference
-------------------------------------------------------------

void fun(string &s)

No copy.

Changes affect original.

Complexity:

O(1)

-------------------------------------------------------------
Pass by Const Reference (Best)
-------------------------------------------------------------

void fun(const string &s)

No copy.

Cannot modify.

Complexity:

O(1)

Preferred in interviews.

=================================================================
🔹 8. C-Style String Functions
=================================================================

Header:

#include<cstring>

=================================================================
strlen()
=================================================================

char str[]="Hello";

strlen(str)

Output:

5

Does NOT count '\0'

Time Complexity:

O(n)

=================================================================
strcpy()
=================================================================

char src[]="Hello";

char dest[20];

strcpy(dest,src);

Output:

Hello

Copies source into destination.

Time Complexity:

O(n)

=================================================================
strcat()
=================================================================

char a[20]="Hello";

char b[]="World";

strcat(a,b);

Output:

HelloWorld

Time Complexity:

O(n+m)

=================================================================
strcmp()
=================================================================

char a[]="abc";
char b[]="abd";

strcmp(a,b)

Returns:

<0 if a<b

0 if equal

>0 if a>b

Time Complexity:

O(min(n,m))

=================================================================
strlen vs size()
=================================================================

string s="Hello";

s.size()

O(1)

-------------------------------------------------------------

char str[]="Hello";

strlen(str)

O(n)

=================================================================
🔹 9. Character Array vs std::string
=================================================================

Feature             char[]        string
------------------------------------------------
Size                 Fixed         Dynamic
Assignment            No            Yes
Concatenation         strcat        +
Length                strlen        size()
Safety                Low           High
Memory Management     Manual        Automatic

Modern C++ prefers string.

=================================================================
🔹 10. string_view (C++17)
=================================================================

Header:

#include<string_view>

string s="Programming";

string_view sv=s;

string_view is a non-owning view.

It does NOT copy data.

Memory:

string -----> Programming

          ↑
      string_view

Useful for efficiency.

-------------------------------------------------------------

Pass large strings efficiently.

void fun(string_view s)

Complexity:

O(1)

=================================================================
🔹 11. Small String Optimization (SSO)
=================================================================

Most implementations store small strings directly inside the
string object without heap allocation.

Example:

string s="Hello";

No heap allocation may occur.

Benefits:

✔ Faster
✔ Less memory usage

Large strings use heap memory.

This optimization is implementation dependent.

=================================================================
🔹 12. c_str()
=================================================================

Returns C-style string.

string s="Hello";

const char* ptr=s.c_str();

Useful when C functions require char*.

Example:

printf("%s",s.c_str());

Time Complexity:

O(1)

=================================================================
🔹 data()
=================================================================

Returns pointer to internal characters.

s.data()

Similar to c_str()

=================================================================
🔹 copy()
=================================================================

string s="Hello";

char arr[10];

s.copy(arr,5);

arr[5]='\0';

cout<<arr;

Output:

Hello

=================================================================
🔹 Front and Back
=================================================================

string s="Programming";

s.front()

Output:

P

s.back()

Output:

g

Complexity:

O(1)

=================================================================
🔹 Empty String Check
=================================================================

string s;

if(s.empty())
{
    cout<<"Empty";
}

Preferred over:

if(s.size()==0)

=================================================================
🔹 Useful String Algorithms
=================================================================

reverse(s.begin(),s.end());

sort(s.begin(),s.end());

count(s.begin(),s.end(),'a');

find(s.begin(),s.end(),'x');

min_element(s.begin(),s.end());

max_element(s.begin(),s.end());

accumulate(s.begin(),s.end(),0);

=================================================================
🔹 Common Competitive Programming Trick
=================================================================

Convert character digit to integer:

char ch='7';

int x=ch-'0';

Output:

7

-------------------------------------------------------------

Convert integer digit to character:

int x=5;

char ch=x+'0';

Output:

'5'

=================================================================
*/
