/*
=================================================================
                C++ STRINGS MASTER NOTES (PART 2)
        STRING MEMBER FUNCTIONS + MEMORY + CAPACITY
=================================================================

std::string is a dynamic container of characters.

Internally it maintains:

1. size()     -> number of characters currently stored
2. capacity() -> total memory currently allocated

Example:

string s="Hello";

size = 5
capacity >= 5

=================================================================
🔹 1. size() and length()
=================================================================

Both are identical.

string s="Programming";

cout<<s.size();      //11
cout<<s.length();    //11

Time Complexity:
O(1)

--------------------------------------------------------------

Empty string:

string s="";

size=0

=================================================================
🔹 2. capacity()
=================================================================

Returns total allocated space.

string s="Hello";

cout<<s.capacity();

Output may be:

15

NOT 5

Because string allocates extra memory to avoid
reallocating every time.

capacity >= size

Time Complexity:
O(1)

=================================================================
🔹 3. max_size()
=================================================================

Maximum possible size of string.

string s;

cout<<s.max_size();

Very large number (~10^18)

Depends on compiler/system.

Time Complexity:
O(1)

=================================================================
🔹 4. empty()
=================================================================

Checks whether string is empty.

string s;

if(s.empty())
{
    cout<<"Empty";
}

Returns:
true or false

Time Complexity:
O(1)

=================================================================
🔹 5. clear()
=================================================================

Deletes all characters.

string s="Hello";

s.clear();

cout<<s;

Output:

(empty)

size() = 0

Capacity remains unchanged.

Time Complexity:
O(n)

-------------------------------------------------------------

Example:

string s="Programming";

capacity=15

s.clear();

size=0

capacity still may remain 15

=================================================================
🔹 6. push_back()
=================================================================

Adds one character at end.

string s="Hell";

s.push_back('o');

Output:

Hello

Time Complexity:
Amortized O(1)

-------------------------------------------------------------

Multiple pushes:

string s;

s.push_back('A');
s.push_back('B');

Output:

AB

=================================================================
🔹 7. pop_back()
=================================================================

Removes last character.

string s="Hello";

s.pop_back();

Output:

Hell

Time Complexity:
O(1)

-------------------------------------------------------------

Cannot use on empty string.

string s="";

s.pop_back();

❌ Undefined Behavior

=================================================================
🔹 8. append()
=================================================================

Adds string at end.

string s="Hello";

s.append(" World");

Output:

Hello World

-------------------------------------------------------------

Can append another string.

string a="Hello";
string b=" C++";

a.append(b);

Output:

Hello C++

Time Complexity:
O(m)

where m = appended string length

=================================================================
🔹 9. operator +
=================================================================

Concatenation

string a="Hello";
string b="World";

string c=a+b;

Output:

HelloWorld

-------------------------------------------------------------

With spaces:

string c=a+" "+b;

Output:

Hello World

Time Complexity:
O(n+m)

=================================================================
🔹 10. operator +=
=================================================================

string s="Hello";

s+=" World";

Output:

Hello World

Equivalent to append()

Time Complexity:
O(m)

=================================================================
🔹 11. assign()
=================================================================

Replaces entire string.

string s="Hello";

s.assign("Programming");

Output:

Programming

-------------------------------------------------------------

Can assign another string.

string a="ABC";

string b;

b.assign(a);

Output:

ABC

Time Complexity:
O(n)

=================================================================
🔹 12. insert()
=================================================================

Insert at specific index.

Syntax:

insert(position,string)

Example:

string s="Helo";

s.insert(2,"l");

Output:

Hello

-------------------------------------------------------------

Another example:

string s="I Python";

s.insert(2,"love ");

Output:

I love Python

Time Complexity:
O(n)

Because shifting is required.

=================================================================
🔹 13. erase()
=================================================================

Deletes characters.

Syntax:

erase(index,length)

Example:

string s="HelloWorld";

s.erase(5,5);

Output:

Hello

-------------------------------------------------------------

Erase entire string

s.erase();

Equivalent to:

s.clear();

Time Complexity:
O(n)

=================================================================
🔹 14. replace()
=================================================================

Replace part of string.

Syntax:

replace(index,length,new_string)

Example:

string s="I hate Java";

s.replace(7,4,"C++");

Output:

I hate C++

-------------------------------------------------------------

Another example:

string s="abcdef";

s.replace(2,3,"XYZ");

Output:

abXYZf

Time Complexity:
O(n)

=================================================================
🔹 15. substr()
=================================================================

Extract substring.

Syntax:

substr(start,length)

Example:

string s="Programming";

cout<<s.substr(3,4);

Output:

gram

-------------------------------------------------------------

If length omitted:

s.substr(3);

Output:

gramming

Time Complexity:
O(length)

-------------------------------------------------------------

Example:

string s="abcdef";

s.substr(2);

Output:

cdef

=================================================================
🔹 16. copy()
=================================================================

Copies characters into char array.

string s="Hello";

char arr[10];

s.copy(arr,5);

arr[5]='\0';

cout<<arr;

Output:

Hello

Time Complexity:
O(n)

=================================================================
🔹 17. swap()
=================================================================

Swaps contents.

string a="ABC";
string b="XYZ";

a.swap(b);

Output:

a = XYZ
b = ABC

Time Complexity:
O(1)

Very efficient.

=================================================================
🔹 18. resize()
=================================================================

Changes size of string.

-------------------------------------------------------------
Increase size
-------------------------------------------------------------

string s="ABC";

s.resize(5);

Output:

ABC\0\0

Printed:

ABC

New characters are '\0'

-------------------------------------------------------------
Custom character

s.resize(7,'x');

Output:

ABCxxxx

-------------------------------------------------------------
Decrease size

string s="Programming";

s.resize(4);

Output:

Prog

Time Complexity:
O(n)

=================================================================
🔹 19. reserve()
=================================================================

Increases capacity.

string s;

s.reserve(100);

Now capacity >=100

Size remains 0

Useful to avoid repeated reallocations.

Time Complexity:
O(n)

=================================================================
🔹 20. shrink_to_fit()
=================================================================

Reduces unused capacity.

string s="Programming";

s.shrink_to_fit();

Capacity becomes close to size.

Not guaranteed.

Time Complexity:
O(n)

=================================================================
🔹 21. front()
=================================================================

Returns first character.

string s="Hello";

cout<<s.front();

Output:

H

Time Complexity:
O(1)

=================================================================
🔹 22. back()
=================================================================

Returns last character.

string s="Hello";

cout<<s.back();

Output:

o

Time Complexity:
O(1)

=================================================================
🔹 23. Memory Growth (IMPORTANT)
=================================================================

Suppose:

string s;

Initially:

size=0
capacity=15

push_back('A')

size=1
capacity=15

...

After size reaches 15:

capacity doubles approximately.

15 → 30 → 60 → 120 ...

This avoids O(n²) behavior.

Therefore:

push_back()

has amortized O(1) complexity.

=================================================================
🔹 24. Difference Between size() and capacity()
=================================================================

string s="Hello";

size() = 5

capacity() = 15

size:
Actual characters

capacity:
Allocated memory

Always:

capacity >= size

=================================================================
🔹 25. Commonly Used Functions Summary
=================================================================

size()            O(1)
length()          O(1)
empty()           O(1)
front()           O(1)
back()            O(1)
push_back()       O(1) amortized
pop_back()        O(1)

append()          O(m)
operator+=        O(m)

insert()          O(n)
erase()           O(n)
replace()         O(n)

substr()          O(k)

clear()           O(n)

swap()            O(1)

resize()          O(n)

reserve()         O(n)

shrink_to_fit()   O(n)

=================================================================
*/
