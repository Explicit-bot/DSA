/*
# Complete C++ Unicode, wchar_t, UTF-8, UTF-16, UTF-32, Streams and Wide Streams Notes
# From Basic to Advanced

# =========================================================

# 1. WHY CHARACTER ENCODING EXISTS

# =========================================================

Computers fundamentally understand only:

```text
0s and 1s (binary)
```

So characters like:

```text
A
B
7
@
न
你
😀
```

must somehow be converted into numbers.

This conversion system is called:

# Character Encoding

# =========================================================

# 2. ASCII

# =========================================================

Initially computers mainly used:

# ASCII

ASCII stands for:

```text
American Standard Code for Information Interchange
```

ASCII maps characters to numbers.

Examples:

| Character | ASCII Value |
| --------- | ----------- |
| A         | 65          |
| B         | 66          |
| a         | 97          |
| 0         | 48          |

---

# ASCII Size

ASCII originally used:

```text
7 bits
```

Later commonly stored in:

```text
8 bits = 1 byte
```

---

# Problem with ASCII

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

```text
न
你
あ
😀
ם
```

This led to:

# Unicode

# =========================================================

# 3. UNICODE

# =========================================================

Unicode is a universal character system.

Goal:

```text
Represent EVERY character from EVERY language.
```

Unicode gives every character a unique number called:

# Code Point

Examples:

| Character | Unicode Code Point |
| --------- | ------------------ |
| A         | U+0041             |
| ₹         | U+20B9             |
| 😀        | U+1F600            |
| ण         | U+0923             |

---

# IMPORTANT

Unicode itself does NOT define:

* memory storage format

It only defines:

* character identities

Storage is handled by:

# UTF encodings

# =========================================================

# 4. WHAT IS UTF?

# =========================================================

UTF means:

```text
Unicode Transformation Format
```

UTF defines HOW Unicode characters are stored in memory.

Main UTF encodings:

| Encoding | Meaning         |
| -------- | --------------- |
| UTF-8    | 8-bit encoding  |
| UTF-16   | 16-bit encoding |
| UTF-32   | 32-bit encoding |

# =========================================================

# 5. UTF-8

# =========================================================

UTF-8 is the MOST IMPORTANT modern encoding.

It is:

* internet standard
* most commonly used encoding today

---

# UTF-8 Storage

UTF-8 uses:

```text
1 to 4 bytes
```

depending on character.

| Character Type      | Bytes   |
| ------------------- | ------- |
| English ASCII       | 1 byte  |
| Many European chars | 2 bytes |
| Asian chars         | 3 bytes |
| Emojis              | 4 bytes |

---

# Examples

| Character | UTF-8 Bytes |
| --------- | ----------- |
| A         | 1           |
| ₹         | 3           |
| 😀        | 4           |

---

# Advantages of UTF-8

## 1. Memory Efficient

English text remains compact.

## 2. ASCII Compatible

ASCII characters remain same.

Example:

```text
A = 65
```

still valid.

## 3. Internet Standard

Most websites use UTF-8.

---

# Disadvantage

Characters are variable-length.

So indexing becomes harder.

# =========================================================

# 6. UTF-16

# =========================================================

UTF-16 stores characters mainly using:

```text
2 bytes
```

---

# Important

Some characters need:

* 2 bytes
* others need 4 bytes (surrogate pairs)

---

# Surrogate Pair

Some large Unicode characters (like emojis) need TWO UTF-16 units.

Example:

* 😀 needs surrogate pair.

---

# Advantages

* good balance
* widely used
* common in Windows/Java

---

# Disadvantages

* still variable-length
* indexing not fully simple

# =========================================================

# 7. UTF-32

# =========================================================

UTF-32 stores EVERY character using:

```text
4 bytes
```

always.

---

# Advantages

## Fixed-size

Every character same size.

Very easy indexing.

Example:

```text
Character 0
Character 1
Character 2
```

easy to calculate.

---

# Disadvantages

Huge memory usage.

Even simple letter:

```text
A
```

uses 4 bytes.

# =========================================================

# 8. COMPARISON OF UTF ENCODINGS

# =========================================================

| Encoding | Size           | Fixed? | Memory Efficient | Easy Indexing |
| -------- | -------------- | ------ | ---------------- | ------------- |
| UTF-8    | 1-4 bytes      | No     | Excellent        | No            |
| UTF-16   | 2 or 4 bytes   | No     | Medium           | Medium        |
| UTF-32   | 4 bytes always | Yes    | Poor             | Excellent     |

# =========================================================

# 9. C++ CHARACTER TYPES

# =========================================================

C++ provides multiple character types.

| Type     | Purpose           |
| -------- | ----------------- |
| char     | normal characters |
| wchar_t  | wide characters   |
| char16_t | UTF-16 characters |
| char32_t | UTF-32 characters |

# =========================================================

# 10. char

# =========================================================

Basic character type.

---

# Size

```text
1 byte
```

---

# Example

```cpp
char ch = 'A';
```

---

# Usually Used For

* ASCII
* UTF-8 byte storage
* basic text

---

# Important

Modern UTF-8 text is often stored using:

```cpp
std::string
```

which internally uses:

* char

# =========================================================

# 11. wchar_t

# =========================================================

`wchar_t` means:

```text
wide character type
```

Used for larger characters than normal char.

---

# Syntax

```cpp
wchar_t ch = L'A';
```

---

# IMPORTANT PREFIX

```text
L
```

means:

* wide character literal

---

# Unicode Example

```cpp
wchar_t hebrew = L'ם';
```

---

# Size of wchar_t

IMPORTANT:

Depends on platform.

| Platform  | Typical Size |
| --------- | ------------ |
| Windows   | 2 bytes      |
| Linux/GCC | 4 bytes      |

So:

```text
wchar_t is NOT portable/fixed-size
```

---

# Why This Is Problematic

Same code behaves differently across systems.

This is why:

* char16_t
* char32_t

were introduced in C++11.

# =========================================================

# 12. WIDE STRINGS

# =========================================================

Normal string:

```cpp
char str[] = "Hello";
```

Wide string:

```cpp
wchar_t str[] = L"Hello";
```

Again:

* `L` prefix required

# =========================================================

# 13. char16_t

# =========================================================

Introduced in:

* C++11

Purpose:

* UTF-16 storage

---

# Size

```text
ALWAYS 2 bytes
```

---

# Prefix

```text
u
```

---

# Example

```cpp
char16_t ch = u'A';
```

---

# Unicode Example

```cpp
char16_t rupee = u'₹';
```

---

# UTF-16 String

```cpp
char16_t str[] = u"Hello";
```

# =========================================================

# 14. char32_t

# =========================================================

Introduced in:

* C++11

Purpose:

* UTF-32 storage

---

# Size

```text
ALWAYS 4 bytes
```

---

# Prefix

```text
U
```

---

# Example

```cpp
char32_t ch = U'A';
```

---

# Emoji Example

```cpp
char32_t emoji = U'😀';
```

---

# UTF-32 String

```cpp
char32_t str[] = U"Hello";
```

# =========================================================

# 15. COMPLETE TYPE COMPARISON

# =========================================================

| Type     | Size         | Fixed? | Prefix | Encoding               |
| -------- | ------------ | ------ | ------ | ---------------------- |
| char     | 1 byte       | Yes    | none   | ASCII/UTF-8            |
| wchar_t  | 2 or 4 bytes | No     | L      | implementation-defined |
| char16_t | 2 bytes      | Yes    | u      | UTF-16                 |
| char32_t | 4 bytes      | Yes    | U      | UTF-32                 |

# =========================================================

# 16. STREAMS IN C++

# =========================================================

A stream is:

```text
flow of data
```

C++ standard streams:

| Stream | Purpose        |
| ------ | -------------- |
| cin    | input          |
| cout   | normal output  |
| cerr   | error output   |
| clog   | logging output |

# =========================================================

# 17. cout

# =========================================================

`cout` means:

```text
character output stream
```

Used for:

* normal text output

---

# Example

```cpp
cout << "Hello";
```

---

# Supports

Primarily:

* char
* normal strings

# =========================================================

# 18. BUFFERING

# =========================================================

Before understanding:

* cerr
* clog

you MUST understand buffering.

---

# What is Buffering?

A buffer is:

```text
temporary memory storage
```

Output is often:

1. stored temporarily
2. printed later

This improves speed.

---

# Buffered Streams

Examples:

* cout
* clog

---

# Unbuffered Streams

Examples:

* cerr

# =========================================================

# 19. cerr

# =========================================================

`cerr` means:

```text
character error stream
```

Used for:

* urgent errors
* crash messages
* debugging critical issues

---

# Example

```cpp
cerr << "File not found";
```

---

# Important

`cerr` is:

```text
UNBUFFERED
```

Meaning:

* prints immediately

# =========================================================

# 20. WHY cerr IS UNBUFFERED

# =========================================================

Errors are urgent.

Suppose program crashes.

If errors stayed in buffer:

* they may never appear.

So:

* cerr flushes instantly.

# =========================================================

# 21. clog

# =========================================================

`clog` means:

```text
character log stream
```

Used for:

* execution records
* debugging history
* monitoring
* logs

---

# Example

```cpp
clog << "Database connected";
```

---

# Important

`clog` is:

```text
BUFFERED
```

because logs are:

* frequent
* large
* not urgent

# =========================================================

# 22. WHAT IS LOGGING?

# =========================================================

Logging means:

```text
Recording what the program is doing.
```

Examples:

```text
Program Started
User Logged In
Database Connected
Request Received
```

Logs help developers:

* debug
* monitor
* track crashes
* inspect execution flow

# =========================================================

# 23. WIDE STREAMS

# =========================================================

Wide versions of streams:

| Normal | Wide Version |
| ------ | ------------ |
| cin    | wcin         |
| cout   | wcout        |
| cerr   | wcerr        |
| clog   | wclog        |

# =========================================================

# 24. wcout

# =========================================================

Wide version of:

* cout

Used with:

* wchar_t

---

# Example

```cpp
wchar_t ch = L'ם';

wcout << ch;
```

---

# Why Not cout?

Because:

* cout understands char
* wcout understands wchar_t

# =========================================================

# 25. wcerr

# =========================================================

Wide version of:

* cerr

Used for:

* wide-character error messages

Example:

```cpp
wcerr << L"Unicode Error";
```

---

# wcerr is UNBUFFERED

# =========================================================

# 26. wclog

# =========================================================

Wide version of:

* clog

Used for:

* wide-character logging

Example:

```cpp
wclog << L"Unicode Log";
```

---

# wclog is BUFFERED

# =========================================================

# 27. IMPORTANT : char16_t AND char32_t OUTPUT

# =========================================================

This is VERY important.

---

# cout DOES NOT directly support:

* char16_t
* char32_t

---

# Example

```cpp
char16_t ch = u'A';

cout << ch;
```

Usually does NOT print properly.

---

# Why?

Because:

| Stream | Supports |
| ------ | -------- |
| cout   | char     |
| wcout  | wchar_t  |

There is no direct standard stream support for:

* char16_t
* char32_t

---

# Numeric Printing

```cpp
char16_t ch = u'A';

cout << (int)ch;
```

Output:

```text
65
```

# =========================================================

# 28. WHY MODERN SOFTWARE MOSTLY USES UTF-8

# =========================================================

Most modern systems prefer UTF-8 because:

* memory efficient
* internet standard
* ASCII compatible
* cross-platform

Most websites today use:

* UTF-8

# =========================================================

# 29. MODERN C++ NOTES

# =========================================================

C++20 introduced:

```text
char8_t
```

for UTF-8 character handling.

# =========================================================

# 30. COMPLETE QUICK REVISION

# =========================================================

# Character Types

```text
char      -> 1-byte basic characters
wchar_t   -> wide characters
char16_t  -> UTF-16
char32_t  -> UTF-32
```

---

# Prefixes

```text
'A'  -> char
L'A' -> wchar_t
u'A' -> char16_t
U'A' -> char32_t
```

---

# Streams

```text
cout  -> normal output
cerr  -> errors
clog  -> logs

wcout -> wide output
wcerr -> wide errors
wclog -> wide logs
```

---

# Buffering

```text
cout  -> buffered
clog  -> buffered

cerr  -> unbuffered
wcerr -> unbuffered
```

---

# UTF Encodings

```text
UTF-8  -> variable 1-4 bytes
UTF-16 -> mainly 2 bytes
UTF-32 -> always 4 bytes
```

---

# Most Important Modern Reality

```text
Most modern software uses UTF-8 internally.
```
*/
