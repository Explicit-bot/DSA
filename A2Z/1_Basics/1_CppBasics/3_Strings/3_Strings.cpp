/*
=================================================================
                C++ STRINGS MASTER NOTES (PART 3)
        SEARCHING + COMPARISON + CHARACTER FUNCTIONS
=================================================================

Most interview problems involve:
✔ Searching
✔ Comparing
✔ Character checking
✔ Case conversion
✔ Lexicographical ordering

=================================================================
🔹 1. find()
=================================================================

Used to find the first occurrence of a substring or character.

Syntax:

string.find(value)

Returns:
Index of first occurrence

If not found:
Returns string::npos

-------------------------------------------------------------

Example:

string s="Programming";

cout<<s.find("gram");

Output:

3

-------------------------------------------------------------

Example:

string s="banana";

cout<<s.find('a');

Output:

1

-------------------------------------------------------------

Element not found:

cout<<s.find("xyz");

Output:

18446744073709551615

Actually returns:

string::npos

Always write:

if(s.find("xyz")==string::npos)
{
    cout<<"Not found";
}

Time Complexity:

Worst Case O(n×m)

n = string size
m = pattern size

===============================================================
🔹 find() with starting position
===============================================================

string s="banana";

cout<<s.find('a',2);

Search starts from index 2

Output:

3

=================================================================
🔹 2. rfind()
=================================================================

Searches from right side.

Returns last occurrence.

Example:

string s="banana";

cout<<s.rfind('a');

Output:

5

Time Complexity:

O(n)

=================================================================
🔹 3. find_first_of()
=================================================================

Find first occurrence of ANY character from a set.

Example:

string s="programming";

cout<<s.find_first_of("aeiou");

Output:

2

Because 'o' is first vowel.

-------------------------------------------------------------

Example:

string s="xyzabc";

cout<<s.find_first_of("bc");

Output:

4

Time Complexity:

O(n×m)

=================================================================
🔹 4. find_last_of()
=================================================================

Finds last occurrence of any character.

Example:

string s="programming";

cout<<s.find_last_of("aeiou");

Output:

6

'a' occurs at index 5
'i' occurs at index 8

Answer:

8

(last vowel)

=================================================================
🔹 5. find_first_not_of()
=================================================================

Finds first character NOT belonging to set.

Example:

string s="000001234";

cout<<s.find_first_not_of('0');

Output:

5

Useful for removing leading zeros.

=================================================================
🔹 6. find_last_not_of()
=================================================================

Example:

string s="abc000";

cout<<s.find_last_not_of('0');

Output:

2

Useful for trimming trailing characters.

=================================================================
🔹 7. compare()
=================================================================

Lexicographical comparison.

Returns:

0   → equal
<0  → smaller
>0  → greater

Example:

string a="apple";
string b="banana";

cout<<a.compare(b);

Output:

Negative value

Because:

apple < banana

-------------------------------------------------------------

Equal strings:

string a="cat";
string b="cat";

a.compare(b)

Output:

0

Time Complexity:

O(min(n,m))

=================================================================
🔹 8. Relational Operators
=================================================================

Can compare strings directly.

string a="apple";
string b="banana";

cout<<(a<b);

Output:

1

-------------------------------------------------------------

Operators:

==
!=
<
>
<=
>=

Example:

"abc"<"abd"

True

-------------------------------------------------------------

Comparison is lexicographical.

Dictionary order.

=================================================================
🔹 9. Lexicographical Comparison
=================================================================

Character by character comparison.

Example:

"abc" < "abd"

Compare:

a=a
b=b
c<d

Therefore:

abc < abd

-------------------------------------------------------------

Example:

"abc" < "abcd"

All first 3 chars equal

Shorter string is smaller.

Therefore:

True

-------------------------------------------------------------

ASCII based comparison.

'A' = 65
'a' = 97

Thus:

"A" < "a"

True

=================================================================
🔹 10. Character Functions
=================================================================

Header:

#include<cctype>

=================================================================
🔹 isalpha()
=================================================================

Checks alphabet.

isalpha('A') → true
isalpha('z') → true
isalpha('5') → false

Time Complexity:

O(1)

=================================================================
🔹 isdigit()
=================================================================

Checks digit.

isdigit('7') → true
isdigit('a') → false

=================================================================
🔹 isalnum()
=================================================================

Alphabet OR digit.

isalnum('A') → true
isalnum('5') → true
isalnum('@') → false

=================================================================
🔹 islower()
=================================================================

islower('a')

Output:

true

=================================================================
🔹 isupper()
=================================================================

isupper('A')

Output:

true

=================================================================
🔹 toupper()
=================================================================

Converts to uppercase.

char ch='a';

cout<<toupper(ch);

Output:

A

-------------------------------------------------------------

Convert whole string:

string s="hello";

for(char &ch:s)
{
    ch=toupper(ch);
}

Output:

HELLO

=================================================================
🔹 tolower()
=================================================================

char ch='A';

cout<<tolower(ch);

Output:

a

-------------------------------------------------------------

Convert string:

for(char &ch:s)
{
    ch=tolower(ch);
}

=================================================================
🔹 isspace()
=================================================================

Checks whitespace.

isspace(' ') → true

isspace('\n') → true

isspace('\t') → true

Useful while parsing.

=================================================================
🔹 ispunct()
=================================================================

Checks punctuation.

ispunct('.')

true

ispunct('?')

true

ispunct('a')

false

=================================================================
🔹 ASCII Tricks
=================================================================

'A' = 65
'Z' = 90

'a' = 97
'z' = 122

Difference:

'a'-'A'

=32

-------------------------------------------------------------

Lowercase → Uppercase

ch-32

Example:

'a'

becomes

'A'

-------------------------------------------------------------

Uppercase → Lowercase

ch+32

Example:

'A'

becomes

'a'

⚠ Prefer:

toupper()
tolower()

=================================================================
🔹 Character to Integer
=================================================================

char ch='7';

int x=ch-'0';

x=7

-------------------------------------------------------------

Example:

char ch='9';

cout<<ch-'0';

Output:

9

=================================================================
🔹 Integer to Character
=================================================================

int x=5;

char ch=x+'0';

Output:

'5'

=================================================================
🔹 Count Frequency of Characters
=================================================================

string s="banana";

int freq[26]={};

for(char ch:s)
{
    freq[ch-'a']++;
}

Frequency:

a = 3
b = 1
n = 2

Time Complexity:

O(n)

=================================================================
🔹 Toggle Case
=================================================================

string s="AbCd";

for(char &ch:s)
{
    if(islower(ch))
        ch=toupper(ch);
    else
        ch=tolower(ch);
}

Output:

aBcD

=================================================================
🔹 Count Vowels
=================================================================

string s="Programming";

int cnt=0;

for(char ch:s)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        cnt++;
}

Output:

3

=================================================================
🔹 Reverse String
=================================================================

string s="hello";

reverse(s.begin(),s.end());

Output:

olleh

Time Complexity:

O(n)

=================================================================
🔹 Sort String
=================================================================

string s="dcab";

sort(s.begin(),s.end());

Output:

abcd

Time Complexity:

O(nlogn)

=================================================================
🔹 Palindrome Check
=================================================================

string s="madam";

string temp=s;

reverse(temp.begin(),temp.end());

if(s==temp)
    cout<<"Palindrome";

Time Complexity:

O(n)

=================================================================
🔹 Most Important Interview Functions
=================================================================
find()
rfind()
compare()
==
<
>
toupper()
tolower()
isdigit()
isalpha()
isalnum()
reverse()
sort()

These are used in a huge number of interview problems.

=================================================================
*/
