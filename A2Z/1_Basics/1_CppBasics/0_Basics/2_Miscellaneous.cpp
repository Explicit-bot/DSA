/*
Computers fundamentally understand only 0s and 1s (binary) so characters like:
A
B
7
@
न
你
😀
must somehow be converted into numbers.
This conversion system is called Character Encoding.

• Initially computers mainly used ASCII.

ASCII stands for: American Standard Code for Information Interchange
ASCII maps characters to numbers.

Examples:
Character	ASCII Value
A	        65
B	        66
Z           90
a	        97
z           122
0           48
9           57

ASCII originally used:
7 bits

Later commonly stored in:
8 bits = 1 byte  //128-255 have different values for different standards 

ASCII only supports:
* English letters
* digits
* basic symbols

It CANNOT properly represent:
* Hindi
* Chinese
* Japanese
* Arabic
* Emojis

Examples:
न
你
あ
😀
ם

This led to Unicode.

-----------------------------------------------------------------------------------------

3. UNICODE - Unicode is a universal character system.
Goal:
Represent EVERY character from EVERY language.
Unicode gives every character a unique number called Code Point
Examples:
| Character | Unicode Code Point |
| --------- | ------------------ |
| A         | U+0041             |
| ₹         | U+20B9             |
| 😀        | U+1F600            |
| ण         | U+0923             |

IMPORTANT-
• Unicode itself does NOT define the memory storage format.
• It only defines character identities
• Storage is handled by UTF encodings

-----------------------------------------------------------------------------------------

4. UTF - Unicode Transformation Format
UTF defines HOW Unicode characters are stored in memory.
Main UTF encodings:
| Encoding | Meaning         |
| -------- | --------------- |
| UTF-8    | 8-bit encoding  |  //No Endianness Problems (Little endian,Big endian)
| UTF-16   | 16-bit encoding |  //Byte order issue (Endianness Problems)
| UTF-32   | 32-bit encoding |  //Byte order issue

Endianess describes : How multi-byte data is arranged in memory
Specifically:
Which byte is stored first.

Big Endian : Most significant first 
E.g: 
for
    12 34 56 78
Memory layout
| Address | Value |
| ------- | ----- |
| 100     | 12    |
| 101     | 34    |
| 102     | 56    |
| 103     | 78    |

Little Endian : Least Significant Byte first
E.g: 
for
    12 34 56 78
Memory layout:
| Address | Value |
| ------- | ----- |
| 100     | 78    |
| 101     | 56    |
| 102     | 34    |
| 103     | 12    |
So bytes appear reversed : 78 56 34 12

-----------------------------------------------------------------------------------------

5. UTF-8
It is:
* internet standard
* most commonly used encoding today
* UTF-8 uses 1 to 4 bytes depending on character.
| Character Type      | Bytes   |
| ------------------- | ------- |
| English ASCII       | 1 byte  |
| Many European chars | 2 bytes |
| Asian chars         | 3 bytes |
| Emojis              | 4 bytes |

Advantages of UTF-8:
1. Memory Efficient
English text remains compact.

2. ASCII Compatible
ASCII characters remain same.

3. Internet Standard
Most websites use UTF-8.

Disadvantage:
• Characters are variable-length.
• So indexing becomes harder.

-----------------------------------------------------------------------------------------

6. UTF-16
UTF-16 stores characters mainly using: 2 bytes
Some characters need:
* 2 bytes
* others need 4 bytes (surrogate pairs)

Surrogate Pair : Some large Unicode characters (like emojis) need TWO UTF-16 units.

Advantages:
* good balance
* widely used
* common in Windows/Java

Disadvantages:
* still variable-length
* indexing not fully simple

-----------------------------------------------------------------------------------------

7. UTF-32
UTF-32 stores EVERY character using: 4 bytes always.

Advantages:
* Fixed-size
* Every character same size.
* Very easy indexing.

Disadvantages:
* Huge memory usage.
* Even simple letter 'A' uses 4 bytes.

-----------------------------------------------------------------------------------------

8. C++ CHARACTER TYPES
C++ provides multiple character types.

| Type     | Purpose           |
| -------- | ----------------- |
| char     | normal characters |
| wchar_t  | wide characters   |
| char16_t | UTF-16 characters |
| char32_t | UTF-32 characters |

-----------------------------------------------------------------------------------------

9. char
Basic character type.
Size : 1 byte

Example
    char ch = 'A';

Usually Used For
* ASCII
* UTF-8 byte storage
* basic text

Note:
Modern UTF-8 text is often stored using std::string which internally uses * char.

-----------------------------------------------------------------------------------------

10. wchar_t
wchar_t means : wide character type
Used for larger characters than normal char.

# Syntax
    wchar_t ch = L'A';
IMPORTANT PREFIX : L
means : wide character literal

Unicode Example
    Wide char : wchar_t hebrew = L'ם';
    Wide string : wchar_t str[] = L"Hello";

Size of wchar_t Depends on platform.

| Platform  | Typical Size |
| --------- | ------------ |
| Windows   | 2 bytes      |
| Linux/GCC | 4 bytes      |

So wchar_t is NOT portable/fixed-size.

This is why:
* char16_t
* char32_t
were introduced in C++11.

-----------------------------------------------------------------------------------------

11. char16_t
• Purpose : UTF-16 storage
• Size : ALWAYS 2 bytes

Prefix : u

Example:
    char16_t rupee = u'₹';
    char16_t str[] = u"Hello";

-----------------------------------------------------------------------------------------

12. char32_t
• Purpose : UTF-32 storage
• Size : ALWAYS 4 bytes

Prefix : U

Example:
    char32_t ch = U'A';
    char32_t emoji = U'😀';
    char32_t str[] = U"Hello";

-----------------------------------------------------------------------------------------

13. WIDE STREAMS
Wide versions of streams: Used with wchar_t

| Normal | Wide Version |
| ------ | ------------ |
| cin    | wcin         |
| cout   | wcout        |
| cerr   | wcerr        |
| clog   | wclog        |

Example:
    wchar_t ch = L'ם';
    wcout << ch;
    wcerr << L"Unicode Error";
    wclog << L"Unicode Log";

-----------------------------------------------------------------------------------------

14. IMPORTANT : char16_t AND char32_t OUTPUT
Direct support for:
char16_t
char32_t
is generally poor in standard streams(cout,wcout).

    char16_t ch = u'A';
    cout << ch;
Usually does NOT print properly.

Numeric Printing
    char16_t ch = u'A';
    cout << (int)ch;    //Output: 65


15. Most modern systems prefer UTF-8 because:
* memory efficient
* internet standard
* ASCII compatible
* cross-platform

14. MODERN C++ NOTES
C++20 introduced:
char8_t
for UTF-8 character handling.
*/
