/*
C-Style Strings
1. char str[] = "Hello";
✅ What happens?
"Hello" is a string literal, a constant.
A new character array of size 6 (H, e, l, l, o, \0) is created on the stack.
A copy of the string literal is made into this array.

✅ Memory view:
Stack Memory (local)
str[0] = 'H'
str[1] = 'e'
str[2] = 'l'
str[3] = 'l'
str[4] = 'o'
str[5] = '\0'

You can modify this array: ✅ str[0] = 'Y';

2. char* str = "Hello";
❗ What happens?
"Hello" is stored in the read-only data segment (.rodata).
str is a pointer that lives on the stack.
It points to the memory in .rodata, which the OS marks as read-only.

Memory view:
Memory	    Content
Stack	    str → 0xBEEF
.rodata	    "Hello\0" at 0xBEEF (read-only)

If you try to do str[0] = 'Y'; → ❌ undefined behavior (crash or silent corruption)

⚠️ So:
"Hello" exists once in .rodata
Any pointer to that string literal points to this immutable memory

🧠 What about char s[100]; cin >> s;?
The array s[100] is stored on the stack.
When you read input with cin, you modify stack memory.
Still mutable, but not safe (no bounds checking).


C++ std::string
    std::string str = "Hello";
This creates an object of type std::string, which is a C++ class. It stores:
 -A pointer to the character array (on the heap)
 -The size of the string
 -The capacity (how much space is allocated)

🔍 Internal Breakdown
When you declare:
    std::string s = "Hello";

The compiler performs:
 -Construction of a std::string object (on the stack)
 -Allocation of 6 bytes (Hello\0) on the heap
 -Storage of the pointer, size, capacity in the object

🧵 Memory Layout:
Stack (local variables)	            Heap (managed by string object)
s.size = 5	                        ['H', 'e', 'l', 'l', 'o', '\0']
s.capacity = 15	
s.ptr → 0x12345678	

⚡ Small String Optimization (SSO)
For small strings (like "Hi", "Test", etc.), modern compilers (GCC, Clang, MSVC) don't use heap!
Instead, the entire string is stored inside the std::string object on the stack.

Why?
 -Saves heap allocations (which are slow)
 -Speeds up common operations

✅ So:
    std::string s = "Hi";  // No heap — stored inline in object!

⚠️ Common Misunderstanding: “ROM”
 -"ROM" in C++ context ≠ hardware ROM.
 -String literals ("Hello") are stored in read-only sections of RAM, often mistakenly called ROM.
 -Actual ROM is where firmware or BIOS lives.

Memory map:
const char* cstr = "Hello";
        Stack:
        +----------------------+
        | pointer to "Hello"   | --> (in .rodata)
        +----------------------+

        .rodata:
        [ 'H' ][ 'e' ][ 'l' ][ 'l' ][ 'o' ][ '\0' ]

char carr[] = "Hello";
        Stack:
        [ 'H' ][ 'e' ][ 'l' ][ 'l' ][ 'o' ][ '\0' ]

std::string s = "Hello";
        Stack:
        [ size ][ capacity ][ pointer to heap ]

        Heap:
        [ 'H' ][ 'e' ][ 'l' ][ 'l' ][ 'o' ][ maybe '\0' ]

*/
