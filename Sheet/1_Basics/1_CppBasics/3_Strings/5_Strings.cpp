/*
=================================================================
                C++ STRINGS MASTER NOTES (PART 5)
          INTERVIEW PATTERNS + PITFALLS + ADVANCED TOPICS
=================================================================

This section covers:

✔ Two Pointers
✔ Sliding Window
✔ Frequency Arrays
✔ Hashing
✔ Prefix Sum on Strings
✔ Common Pitfalls
✔ Unicode and UTF-8
✔ String Matching Algorithms
✔ Regex
✔ Complete Complexity Table
✔ Most Important Interview Questions

=================================================================
🔹 1. TWO POINTER TECHNIQUE
=================================================================

Used when working from both ends.

Common Problems:
• Palindrome
• Reverse string
• Valid palindrome
• Remove duplicates

-------------------------------------------------------------
Palindrome
-------------------------------------------------------------

string s="madam";

int i=0;
int j=s.size()-1;

while(i<j)
{
    if(s[i]!=s[j])
    {
        cout<<"Not palindrome";
        break;
    }

    i++;
    j--;
}

Time Complexity:

O(n)

=================================================================
🔹 Reverse String
=================================================================

int i=0;
int j=s.size()-1;

while(i<j)
{
    swap(s[i],s[j]);
    i++;
    j--;
}

Time Complexity:

O(n)

=================================================================
🔹 2. SLIDING WINDOW
=================================================================

Very important interview pattern.

Used for:

• Longest substring without repeating characters
• Minimum window substring
• Anagrams
• Frequency problems

-------------------------------------------------------------
Fixed Window Example
-------------------------------------------------------------

Find maximum vowels in substring of length k.

Window:

[-----k-----]

Move:

Remove left character
Add right character

Time Complexity:

O(n)

-------------------------------------------------------------
Variable Window
-------------------------------------------------------------

Expand right pointer

while(condition violated)
    shrink left pointer

Time Complexity:

O(n)

=================================================================
🔹 3. FREQUENCY ARRAY
=================================================================

Most common trick.

Lowercase letters:

int freq[26]={};

for(char ch:s)
{
    freq[ch-'a']++;
}

-------------------------------------------------------------

ASCII:

int freq[256]={};

-------------------------------------------------------------

Digits:

int freq[10]={};

Complexity:

O(n)

Used in:

• Anagrams
• Character counting
• Duplicate detection

=================================================================
🔹 4. HASHING USING unordered_map
=================================================================

unordered_map<char,int> mp;

for(char ch:s)
{
    mp[ch]++;
}

Useful when:

Characters are not limited to a-z.

Complexity:

Average O(n)

=================================================================
🔹 5. PREFIX SUM ON STRINGS
=================================================================

Useful in many problems.

Example:

Count vowels quickly.

string s="programming";

prefix[i]=number of vowels upto i.

Then:

Vowels in range [L,R]

=

prefix[R]-prefix[L-1]

Complexity:

Preprocessing O(n)

Query O(1)

=================================================================
🔹 6. COMMON PITFALLS
=================================================================

-------------------------------------------------------------
Mistake 1
-------------------------------------------------------------

if(s.find("abc"))

❌ WRONG

Because:

find() returns index.

Index 0 becomes false.

Correct:

if(s.find("abc")!=string::npos)

-------------------------------------------------------------
Mistake 2
-------------------------------------------------------------

char ch='7';

int x=ch;

Output:

55

ASCII value.

Correct:

int x=ch-'0';

Output:

7

-------------------------------------------------------------
Mistake 3
-------------------------------------------------------------

getline after cin

int n;

cin>>n;

string s;

getline(cin,s);

Output:

empty string

Need:

cin.ignore();

getline(cin,s);

-------------------------------------------------------------
Mistake 4
-------------------------------------------------------------

Comparing C strings using ==

char a[]="abc";
char b[]="abc";

if(a==b)

❌ compares addresses

Use:

strcmp(a,b)==0

-------------------------------------------------------------
Mistake 5
-------------------------------------------------------------

Accessing:

s[s.size()]

❌ Undefined Behavior

Last index:

s[s.size()-1]

=================================================================
🔹 7. STRING ITERATOR INVALIDATION
=================================================================

After:

push_back()
insert()
erase()

Iterators may become invalid.

Example:

auto it=s.begin();

s.push_back('x');

*it

❌ May be invalid

=================================================================
🔹 8. Unicode and UTF-8 Basics
=================================================================

ASCII:

0-127

English characters only.

-------------------------------------------------------------

Unicode:

Supports all languages.

UTF-8 stores Unicode characters using:

1 to 4 bytes

Examples:

'A'

1 byte

'€'

3 bytes

Emoji 😀
4 bytes

-------------------------------------------------------------

std::string stores bytes.

It does NOT understand characters automatically.

Unicode handling is complicated.

Competitive programming usually assumes ASCII.

=================================================================
🔹 9. REGEX
=================================================================

Header:

#include<regex>

Example:

regex pattern("[0-9]+");

string s="12345";

regex_match(s,pattern)

Output:

true

-------------------------------------------------------------

Email validation etc.

Time Complexity:

Can be expensive.

Rare in interviews.

=================================================================
🔹 10. STRING MATCHING ALGORITHMS
=================================================================

=========================================================
Brute Force
=========================================================

Pattern length = m
Text length = n

Complexity:

O(n*m)

=========================================================
KMP Algorithm
=========================================================

Uses LPS array.

Complexity:

O(n+m)

Most important pattern matching algorithm.

=========================================================
Rabin-Karp
=========================================================

Uses rolling hash.

Average:

O(n+m)

Worst:

O(n*m)

=========================================================
Z Algorithm
=========================================================

Computes Z array.

Complexity:

O(n)

=========================================================
Trie
=========================================================

Useful for:

Dictionary
Autocomplete
Prefix search

Insertion:

O(length)

Search:

O(length)

=================================================================
🔹 11. Important STL Algorithms on Strings
=================================================================

sort()

reverse()

count()

find()

min_element()

max_element()

accumulate()

all_of()

any_of()

none_of()

transform()

unique()

remove()

rotate()

=================================================================
🔹 transform()
=================================================================

Convert entire string to uppercase.

transform(
s.begin(),
s.end(),
s.begin(),
::toupper
);

Time Complexity:

O(n)

=================================================================
🔹 unique()
=================================================================

string s="aaabbcc";

auto it=unique(s.begin(),s.end());

s.erase(it,s.end());

Output:

abc

Complexity:

O(n)

=================================================================
🔹 remove()
=================================================================

Remove all occurrences.

string s="banana";

s.erase(remove(s.begin(),s.end(),'a'),s.end());

Output:

bnn

Complexity:

O(n)

=================================================================
🔹 rotate()
=================================================================

string s="abcdef";

rotate(
s.begin(),
s.begin()+2,
s.end()
);

Output:

cdefab

Complexity:

O(n)

=================================================================
🔹 COMPLETE COMPLEXITY TABLE
=================================================================

size()                  O(1)
length()                O(1)
empty()                 O(1)

front()                 O(1)
back()                  O(1)

push_back()             O(1) amortized
pop_back()              O(1)

append()                O(m)
operator+=              O(m)

insert()                O(n)

erase()                 O(n)

replace()               O(n)

substr()                O(k)

find()                  O(n*m)

rfind()                 O(n)

compare()               O(min(n,m))

swap()                  O(1)

clear()                 O(n)

reserve()               O(n)

resize()                O(n)

sort()                  O(nlogn)

reverse()               O(n)

count()                 O(n)

transform()             O(n)

unique()                O(n)

remove()                O(n)

rotate()                O(n)

=================================================================
🔹 MOST IMPORTANT INTERVIEW QUESTIONS
=================================================================

Easy:

✔ Reverse String
✔ Palindrome
✔ Valid Anagram
✔ Length of Last Word
✔ Reverse Words in String
✔ Roman to Integer
✔ Longest Common Prefix

Medium:

✔ Longest Substring Without Repeating Characters
✔ Group Anagrams
✔ Decode String
✔ String Compression
✔ Generate Parentheses
✔ Partition Labels
✔ Count and Say
✔ Zigzag Conversion

Hard:

✔ Minimum Window Substring
✔ Regular Expression Matching
✔ Wildcard Matching
✔ Text Justification
✔ Palindrome Partitioning II
✔ Edit Distance

=================================================================
🔹 INTERVIEW PATTERNS SUMMARY
=================================================================

Pattern                     Examples
------------------------------------------------

Two Pointers                Palindrome, Reverse

Sliding Window              Longest Substring

Frequency Array             Anagrams

Hashing                     Character Frequency

Sorting                     Group Anagrams

Stack                       Decode String

Greedy                      Partition Labels

Prefix Sum                  Range Queries

Trie                        Prefix Search

KMP                         Pattern Matching

Rabin-Karp                  Rolling Hash

Dynamic Programming         Edit Distance

Backtracking                Generate Parentheses

=================================================================
🔥 GOLDEN RULES
=================================================================

✔ Use std::string instead of char arrays.

✔ Pass large strings using:

const string&

✔ Use getline() when spaces matter.

✔ Use string::npos for find().

✔ Use frequency arrays for lowercase letters.

✔ Use unordered_map when character range is large.

✔ Sliding window solves many interview problems.

✔ Learn KMP, Rabin-Karp and Trie after mastering basics.

=================================================================
                    END OF STRING NOTES
=================================================================
*/
