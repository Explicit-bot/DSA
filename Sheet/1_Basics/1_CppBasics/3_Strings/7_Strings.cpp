/*
=================================================================
            C++ STRINGS MASTER NOTES (PART 7)
      STRING ALGORITHMS + TRIE + UNICODE + WIDE STRINGS
=================================================================

These are advanced topics.

Used in:
✔ Competitive Programming
✔ FAANG Interviews
✔ Pattern Matching
✔ Text Processing

=================================================================
🔹 1. BRUTE FORCE PATTERN MATCHING
=================================================================

Text Length = n
Pattern Length = m

Try matching pattern from every position.

Complexity:

Worst Case:

O(n*m)

Example:

Text    : "ababcabc"
Pattern : "abc"

Matches at index 2 and 5

=================================================================
🔹 2. KMP (Knuth Morris Pratt)
=================================================================

Improves brute force by avoiding unnecessary comparisons.

Uses:

LPS Array (Longest Prefix Suffix)

--------------------------------------------------------------

Example:

Pattern:

ababaca

LPS:

0 0 1 2 3 0 1

--------------------------------------------------------------

Complexity:

Building LPS:

O(m)

Searching:

O(n)

Total:

O(n+m)

--------------------------------------------------------------

Applications:

✔ Pattern Matching
✔ Repeated Substrings
✔ Prefix-Suffix Problems

=================================================================
🔹 3. RABIN-KARP
=================================================================

Uses Hashing.

Instead of comparing characters every time,
compare hash values.

--------------------------------------------------------------

Average Complexity:

O(n+m)

Worst Case:

O(n*m)

--------------------------------------------------------------

Applications:

✔ Multiple Pattern Search
✔ Plagiarism Detection

=================================================================
🔹 4. Z-ALGORITHM
=================================================================

Builds Z-array.

Z[i] = length of longest substring
starting from i which matches prefix.

--------------------------------------------------------------

Example:

String:

aabcaabxaaaz

Z Array:

0 1 0 0 3 1 0 0 2 2 1 0

--------------------------------------------------------------

Complexity:

O(n)

Applications:

✔ Pattern Matching
✔ Prefix Problems

=================================================================
🔹 5. TRIE (PREFIX TREE)
=================================================================

Stores strings character by character.

Example:

Words:

cat
car
care

Structure:

          root
         /
        c
       /
      a
     / \
    t   r
         \
          e

--------------------------------------------------------------

Insertion:

O(length)

Search:

O(length)

--------------------------------------------------------------

Applications:

✔ Dictionary
✔ Autocomplete
✔ Prefix Search
✔ Word Search

=================================================================
🔹 6. SUFFIX ARRAY
=================================================================

Stores sorted suffixes.

Example:

banana

Suffixes:

banana
anana
nana
ana
na
a

Sorted:

a
ana
anana
banana
na
nana

--------------------------------------------------------------

Complexity:

Construction:

O(n log n)

Applications:

✔ Pattern Matching
✔ Longest Repeated Substring

=================================================================
🔹 7. SUFFIX AUTOMATON
=================================================================

Very advanced.

Supports:

✔ Distinct substrings
✔ Longest common substring

Complexity:

O(n)

Mostly used in competitive programming.

=================================================================
🔹 8. REGEX (Regular Expressions)
=================================================================

Header:

#include<regex>

--------------------------------------------------------------

Digits only:

regex pattern("[0-9]+");

--------------------------------------------------------------

Lowercase letters:

regex pattern("[a-z]+");

--------------------------------------------------------------

Email Pattern:

regex pattern("[a-zA-Z0-9._]+@[a-zA-Z]+\\.[a-zA-Z]+");

--------------------------------------------------------------

Check:

if(regex_match(s,pattern))

--------------------------------------------------------------

Complexity:

Can be expensive.

Rare in DSA interviews.

=================================================================
🔹 9. Unicode
=================================================================

ASCII:

0-127

English characters only.

Unicode:

Supports all languages.

Examples:

English
Hindi
Chinese
Emoji

=================================================================
🔹 10. UTF-8
=================================================================

Variable length encoding.

Character size:

1 byte
2 bytes
3 bytes
4 bytes

--------------------------------------------------------------

Examples:

'A'

1 byte

'€'

3 bytes

😀

4 bytes

--------------------------------------------------------------

std::string stores bytes.

Not necessarily characters.

=================================================================
🔹 11. Wide Strings
=================================================================

wstring

Stores wide characters.

Example:

wstring ws=L"Hello";

--------------------------------------------------------------

u16string

UTF-16

--------------------------------------------------------------

u32string

UTF-32

--------------------------------------------------------------

Mostly used for internationalization.

=================================================================
🔹 12. Common String Patterns
=================================================================

Pattern              Examples

------------------------------------------------

Two Pointers

Palindrome
Reverse String

------------------------------------------------

Sliding Window

Longest Substring Without Repeating Characters
Minimum Window Substring

------------------------------------------------

Hashing

Group Anagrams
Rabin Karp

------------------------------------------------

Frequency Array

Valid Anagram
Count Characters

------------------------------------------------

Trie

Word Dictionary
Autocomplete

------------------------------------------------

KMP

Pattern Search

------------------------------------------------

Dynamic Programming

Edit Distance
LCS

------------------------------------------------

Backtracking

Generate Parentheses

=================================================================
🔹 13. IMPORTANT INTERVIEW QUESTIONS
=================================================================

Easy:

✔ Reverse String
✔ Palindrome
✔ Longest Common Prefix
✔ Roman to Integer
✔ Valid Anagram

Medium:

✔ Longest Substring Without Repeating Characters
✔ Group Anagrams
✔ String Compression
✔ Decode String
✔ Partition Labels
✔ Zigzag Conversion

Hard:

✔ Minimum Window Substring
✔ Wildcard Matching
✔ Regex Matching
✔ Edit Distance
✔ Palindrome Partitioning

=================================================================
🔹 14. CHARACTER FUNCTIONS
=================================================================

isalpha()

isdigit()

isalnum()

islower()

isupper()

tolower()

toupper()

isspace()

ispunct()

All Complexity:

O(1)

=================================================================
🔹 15. MOST IMPORTANT STRING FUNCTIONS
=================================================================

size()

length()

empty()

clear()

push_back()

pop_back()

append()

insert()

erase()

replace()

substr()

find()

rfind()

compare()

swap()

resize()

reserve()

shrink_to_fit()

front()

back()

=================================================================
🔹 GOLDEN RULES
=================================================================

✔ Prefer std::string over char arrays.

✔ Pass strings by const reference.

void fun(const string& s)

✔ Use getline() for full lines.

✔ Use string::npos with find().

✔ Use frequency arrays for lowercase letters.

✔ Use unordered_map for large alphabets.

✔ Use push_back() instead of repeated +.

✔ Learn Sliding Window thoroughly.

✔ Learn KMP and Trie after mastering basics.

=================================================================
                END OF STRING MASTER NOTES
=================================================================
*/
