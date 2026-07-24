# Character Encoding in C++

---

# Introduction

Computers fundamentally understand only **binary (0s and 1s)**.

Characters such as

```
A
B
7
@
₹
अ
你
😀
```

cannot be stored directly.

Instead, every character is assigned a unique **numeric value**.

This mapping between characters and numbers is called **Character Encoding**.

---

# Evolution of Character Encoding

```
ASCII
   │
   ▼
Unicode
   │
   ▼
UTF-8 / UTF-16 / UTF-32
```

---

# ASCII

ASCII stands for:

> **American Standard Code for Information Interchange**

It was one of the earliest character encoding systems.

ASCII assigns a unique number to every English character.

---

# ASCII Table

| Character | ASCII |
|-----------|------:|
| A | 65 |
| B | 66 |
| Z | 90 |
| a | 97 |
| z | 122 |
| 0 | 48 |
| 9 | 57 |
| Space | 32 |

Example:

```cpp
char ch = 'A';
```

Internally stores

```
65
```

---

# ASCII Size

Original ASCII used

```
7 bits
```

which allows

```
2⁷ = 128
```

different characters.

Later, ASCII was commonly stored using

```
8 bits (1 Byte)
```

---

# Limitations of ASCII

ASCII supports only:

- English letters
- Digits
- Basic symbols

It **cannot** properly represent:

```
अ

你

こんにちは

😀

₹
```

This led to the development of **Unicode**.

---

# Unicode

Unicode is a **universal character standard**.

Its goal is to represent characters from **every language** using a unique numeric value.

Each character is assigned a **Code Point**.

---

# Unicode Code Points

Examples:

| Character | Code Point |
|-----------|------------|
| A | U+0041 |
| ₹ | U+20B9 |
| अ | U+0905 |
| 😀 | U+1F600 |

Notice:

Unicode only assigns an identity to each character.

It **does not specify how the character is stored in memory**.

That is the job of UTF encodings.

---

# What is UTF?

UTF stands for:

> **Unicode Transformation Format**

UTF defines **how Unicode characters are stored in memory**.

Main UTF encodings:

- UTF-8
- UTF-16
- UTF-32

---

# UTF-8

UTF-8 is the **most widely used character encoding today**.

It uses **1 to 4 bytes** per character.

| Character Type | Storage |
|---------------|---------|
| ASCII | 1 Byte |
| European Languages | 2 Bytes |
| Asian Languages | 3 Bytes |
| Emojis | 4 Bytes |

---

# Advantages of UTF-8

- Memory Efficient
- Internet Standard
- ASCII Compatible
- Cross Platform
- No Endianness Issues

---

# Disadvantages

Characters occupy variable memory.

This makes random indexing slightly more complex.

---

# UTF-16

UTF-16 stores characters using:

- 2 Bytes
- Sometimes 4 Bytes (Surrogate Pairs)

---

# Advantages

- Widely used
- Better for many Asian languages
- Used internally by Windows and Java

---

# Disadvantages

- Variable-length encoding
- Endianness problems
- Less memory efficient than UTF-8 for English text

---

# UTF-32

UTF-32 stores **every character using exactly 4 bytes**.

---

# Advantages

- Fixed-size encoding
- Very simple indexing

---

# Disadvantages

- High memory usage
- Even the character

```
A
```

uses

```
4 Bytes
```

---

# UTF Comparison

| Encoding | Size |
|----------|------|
| UTF-8 | 1–4 Bytes |
| UTF-16 | 2 or 4 Bytes |
| UTF-32 | 4 Bytes |

---

# Endianness

When a value occupies more than one byte, the computer must decide:

> Which byte should be stored first?

This is called **Endianness**.

---

# Big Endian

Stores the **Most Significant Byte first**.

Example:

```
12 34 56 78
```

Memory:

```
Address    Value

100        12

101        34

102        56

103        78
```

---

# Little Endian

Stores the **Least Significant Byte first**.

Example:

```
12 34 56 78
```

Memory:

```
Address    Value

100        78

101        56

102        34

103        12
```

Most modern processors use **Little Endian**.

---

# Character Types in C++

C++ provides multiple character types.

| Type | Purpose |
|------|----------|
| char | Regular characters |
| wchar_t | Wide characters |
| char16_t | UTF-16 |
| char32_t | UTF-32 |

---

# char

Basic character type.

Example:

```cpp
char ch = 'A';
```

Typical Size:

```
1 Byte
```

Usually used for:

- ASCII
- UTF-8 byte storage

---

# wchar_t

Wide character type.

Example:

```cpp
wchar_t ch = L'अ';
```

Prefix:

```
L
```

Typical Size:

| Platform | Size |
|----------|------|
| Windows | 2 Bytes |
| Linux | 4 Bytes |

Because its size differs across platforms, `wchar_t` is **not portable**.

---

# char16_t

Used for UTF-16 characters.

Example:

```cpp
char16_t ch = u'₹';
```

Prefix:

```
u
```

Size:

```
2 Bytes
```

---

# char32_t

Used for UTF-32 characters.

Example:

```cpp
char32_t emoji = U'😀';
```

Prefix:

```
U
```

Size:

```
4 Bytes
```

---

# Wide Streams

Wide character streams are used with `wchar_t`.

| Normal Stream | Wide Stream |
|--------------|-------------|
| cin | wcin |
| cout | wcout |
| cerr | wcerr |
| clog | wclog |

Example:

```cpp
wchar_t ch = L'अ';

wcout << ch;
```

---

# char16_t and char32_t Output

Direct output support is limited.

Example:

```cpp
char16_t ch = u'A';

cout << ch;
```

may not print correctly.

Instead,

```cpp
cout << static_cast<int>(ch);
```

prints the Unicode value.

---

# Modern C++ (C++20)

C++20 introduced

```cpp
char8_t
```

specifically for UTF-8 characters.

It improves type safety when working with UTF-8 encoded data.

---

# Which Encoding Should We Use?

For most applications,

**UTF-8** is the preferred choice because it is:

- Memory Efficient
- Internet Standard
- ASCII Compatible
- Cross Platform

Unless you have platform-specific requirements, UTF-8 is generally the best option.

---
