/*
=================================================================
                C++ STRINGS MASTER NOTES
=================================================================

A string is a sequence of characters used to store text.

C++ supports TWO fundamentally different kinds of strings:

1. C-style strings (Character arrays)
2. std::string (Modern C++ string class)

Modern C++ prefers std::string because it is safer, easier and
dynamically manages memory.

=================================================================
🔹 1. CHARACTER vs STRING
=================================================================

Character:
    char ch = 'A';

String:
    string s = "Hello";

Difference:
'A'     -> single character
"Hello" -> sequence of characters

-------------------------------------------------------------
Memory:
-------------------------------------------------------------

char ch='A'

Address      Value
100          'A'

string s="Hello"

s ----> "Hello"

=================================================================
🔹 2. C-STYLE STRINGS
=================================================================

A C-style string is simply a character array terminated by '\0'.

Example:

char str[] = "Hello";

Memory:

Index : 0   1   2   3   4   5
Value : H   e   l   l   o  '\0'

'\0' = null character
ASCII value = 0

It marks the end of the string.

-------------------------------------------------------------
Size
-------------------------------------------------------------

char str[] = "Hello";

sizeof(str)
= 6 bytes

5 characters + '\0'

strlen(str)
= 5

strlen() does NOT count '\0'

=================================================================
🔹 3. DIFFERENT WAYS TO DECLARE C-STYLE STRINGS
=================================================================

1)

char str[6]={'H','e','l','l','o','\0'};

2)

char str[]="Hello";

3)

char str[20]="Hello";

Unused positions contain garbage.

Memory:

H e l l o \0 ? ? ? ? ...

-------------------------------------------------------------
WARNING
-------------------------------------------------------------

char str[5]="Hello";

❌ WRONG

Need one extra space for '\0'

Correct:

char str[6]="Hello";

=================================================================
🔹 4. STRING LITERALS
=================================================================

"Hello"

This is called a string literal.

Stored in read-only memory.

Example:

const char* ptr = "Hello";

Memory:

ptr
 ↓
"H e l l o \0"

Trying to modify:

ptr[0]='M';

❌ Undefined Behavior

=================================================================
🔹 5. std::string (Modern C++)
=================================================================

#include<string>

string s="Hello";

Unlike char arrays:

✔ Dynamic size
✔ Safe
✔ Easy to modify
✔ Rich member functions
✔ Automatic memory management

Preferred in modern C++.

=================================================================
🔹 6. DECLARATION OF std::string
=================================================================

string s;

Empty string

----------------------------------

string s="Hello";

----------------------------------

string s("Hello");

----------------------------------

string s(5,'A');

Output:

AAAAA

----------------------------------

string s={'H','e','l','l','o'};

----------------------------------

string s="";

Empty string

=================================================================
🔹 7. ARRAY OF STRINGS
=================================================================

string names[3];

names[0]="Ram";
names[1]="Shyam";
names[2]="Aman";

Memory:

names[0] --> "Ram"
names[1] --> "Shyam"
names[2] --> "Aman"

=================================================================
🔹 8. STRING VS CHARACTER ARRAY
=================================================================

char str[20]="Hello";

Fixed size

string s="Hello";

Dynamic size

-------------------------------------------------------------

Feature          char[]        string
------------------------------------------
Size             Fixed         Dynamic
Length           strlen()      size()
Assignment        No            Yes
Concatenation     strcat()      +
Safe              No            Yes
Preferred         Old C         Modern C++

=================================================================
🔹 9. INPUT METHODS
=================================================================

-------------------------------------------------------------
1. cin >>
-------------------------------------------------------------

string s;

cin>>s;

Input:

Hello World

Output:

Hello

Stops at first whitespace.

-------------------------------------------------------------
2. getline()
-------------------------------------------------------------

string s;

getline(cin,s);

Input:

Hello World

Output:

Hello World

Reads entire line.

Most commonly used.

-------------------------------------------------------------
3. getline after cin problem
-------------------------------------------------------------

int n;
cin>>n;

string s;
getline(cin,s);

Problem:
getline() reads leftover '\n'

Solution:

cin.ignore();

getline(cin,s);

Example:

int age;
cin>>age;

cin.ignore();

string name;

getline(cin,name);

-------------------------------------------------------------
4. cin.get()
-------------------------------------------------------------

char ch;

cin.get(ch);

Reads one character including spaces.

Example:

Input:
A

Output:
A

-------------------------------------------------------------
5. cin.getline()
-------------------------------------------------------------

char str[100];

cin.getline(str,100);

Reads entire line into character array.

Input:

Hello World

Output:

Hello World

Stops when:
1. '\n'
2. Size-1 reached

Automatically appends '\0'

=================================================================
🔹 10. EMPTY STRING
=================================================================

string s;

or

string s="";

Length = 0

s.empty()

returns true

=================================================================
🔹 11. STRING MEMORY (IMPORTANT)
=================================================================

string s="Hello";

Object itself stored on stack.

Actual characters usually stored internally
(dynamic memory if needed).

Memory:

Stack:

s
size
capacity
pointer
etc

        |
        ↓

Heap:

H e l l o

Managed automatically.

=================================================================
🔹 12. LENGTH OF STRING
=================================================================

string s="Programming";

s.length()

Output:

11

s.size()

Output:

11

Both are same.

Time Complexity:

O(1)

=================================================================
🔹 13. CHARACTER ACCESS
=================================================================

string s="Hello";

s[0]
Output:
H

s[1]
Output:
e

-------------------------------------------------------------

Front character:

s.front()

Output:
H

-------------------------------------------------------------

Last character:

s.back()

Output:
o

-------------------------------------------------------------

Using at()

s.at(2)

Output:
l

Unlike []

at() performs bounds checking.

s.at(100)

Throws exception.

s[100]

Undefined Behavior.

=================================================================
🔹 14. ITERATING THROUGH STRING
=================================================================

string s="Hello";

1)

for(int i=0;i<s.size();i++)
{
    cout<<s[i];
}

---------------------------------

2)

for(char ch:s)
{
    cout<<ch;
}

---------------------------------

3)

for(auto ch:s)
{
    cout<<ch;
}

---------------------------------

4)

for(auto &ch:s)
{
    ch=toupper(ch);
}

Modifies original string.

=================================================================
🔹 15. ASCII VALUES
=================================================================

'A' = 65
'Z' = 90

'a' = 97
'z' = 122

Difference:

'a'-'A'

= 32

Useful conversions:

char ch='a';

toupper(ch)

Output:

A

char ch='A';

tolower(ch)

Output:

a

=================================================================
*/
