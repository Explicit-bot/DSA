/*
🔹String Copy Functions in <cstring>
These functions are used to copy one C-string into another:

Function	Description
strcpy	    Copies a null-terminated string to a buffer.
strncpy	    Copies up to n characters, padding with \0 if needed.

🔸 1. char* strcpy(char* dest, const char* src);
✅ Purpose:
Copies all characters from src to dest, including the null terminator ('\0').
Assumes src is null-terminated.
Assumes dest has enough memory.
Returns pointer to dest.

✅ Syntax:
    char dest[100];
    const char* src = "Naman";
    strcpy(dest, src);

🧠 Internal Working:
Starts copying characters from src to dest.
Copies each byte until it encounters '\0' (including it).
Does not check the size of dest → ⚠️ dangerous!

🔍 Memory Example:
    char src[] = "Hi";
    char dest[10];

After strcpy(dest, src):
dest index	    Value
0	            'H'
1	            'i'
2	            '\0'
3–9	            garbage or old data

🔸 2. char* strncpy(char* dest, const char* src, size_t n);
✅ Purpose:
Copies up to n characters from src to dest.
Stops at n or at '\0', whichever comes first.
If src is shorter than n, pads the remaining with '\0'.

✅ Syntax:
    char dest[10];
    const char* src = "Hello";
    strncpy(dest, src, 10);

🧠 Internal Working:
Starts copying from src to dest.
Copies until:
n characters are copied, or
'\0' is found (in which case it pads the rest with '\0').

*/
//💻 Full Example Program Demonstrating Both
#include <iostream>
#include <cstring>

int main() {
    // Case 1: strcpy with proper buffer
    char dest1[20];
    const char* src1 = "Naman";
    strcpy(dest1, src1);

    std::cout << "=== Case 1: strcpy ===\n";
    std::cout << "src1: " << src1 << "\n";
    std::cout << "dest1 (after copy): " << dest1 << "\n\n";

    // Case 2: strncpy copying fewer characters
    char dest2[20];
    const char* src2 = "IIIT Sonepat";
    strncpy(dest2, src2, 5);  // Copies only "IIIT "
    dest2[5] = '\0'; // Add null manually if not padded
    std::cout << "=== Case 2: strncpy (copy partial) ===\n";
    std::cout << "dest2 (after strncpy): " << dest2 << "\n\n";

    // Case 3: strncpy with padding
    char dest3[10];
    const char* src3 = "Hi";
    strncpy(dest3, src3, 10);  // Pads remaining with '\0'

    std::cout << "=== Case 3: strncpy with padding ===\n";
    std::cout << "src3: " << src3 << "\n";
    std::cout << "dest3 (full 10 bytes): ";
    for (int i = 0; i < 10; ++i) {
        if (dest3[i] == '\0') std::cout << "\\0 ";
        else std::cout << dest3[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
/*
📤 Sample Output:

=== Case 1: strcpy ===
src1: Naman
dest1 (after copy): Naman

=== Case 2: strncpy (copy partial) ===
dest2 (after strncpy): IIIT 

=== Case 3: strncpy with padding ===
src3: Hi
dest3 (full 10 bytes): H i \0 \0 \0 \0 \0 \0 \0 \0

⚠️ Common Mistakes & Dangers
Using strcpy without enough space	
 - ❌ Buffer overflow (UB)

Passing nullptr as src or dest	
 - ❌ Crash / undefined behavior

Forgetting null terminator after strncpy (partial copy)	
 - ❌ Garbage print
❌ Problem: strncpy does NOT add a '\0' if source is longer than n
🔸 Code Example:
#include <iostream>
#include <cstring>

int main() {
    char src[] = "HelloWorld";
    char dest[6];

    // Copy only first 5 characters from src to dest
    strncpy(dest, src, 5);

    // No null terminator added because 5 < strlen(src)
    std::cout << "Copied string: " << dest << "\n"; // ❌ UB
    return 0;
}
    
🧾 Output (example):
Copied string: HelloWorld⍰@#$%^
Or it may crash, print garbage, or go into infinite loop.

🔍 Why This Happens:
src = "HelloWorld" → 10 characters
strncpy(dest, src, 5) copies only 5 bytes: H, e, l, l, o
No '\0' is added because source is longer than n
cout expects a null-terminated string → reads into garbage memory

✅ Fix: Manually null-terminate
    char src[] = "HelloWorld";
    char dest[6];

    strncpy(dest, src, 5);
    dest[5] = '\0'; // ✅ Ensure it's null-terminated


🔬 Custom Implementations
🔧 strcpy (simplified):
    char* my_strcpy(char* dest, const char* src) {
        char* original = dest;
        while ((*dest++ = *src++));
        return original;
    }

🔧 strncpy (simplified):
    char* my_strncpy(char* dest, const char* src, size_t n) {
        size_t i;
        for (i = 0; i < n && src[i] != '\0'; ++i)
            dest[i] = src[i];
        for (; i < n; ++i)
            dest[i] = '\0';
        return dest;
    }
*/


/*
🔹 1. Does the destination string need to be empty before copying?
❌ No.
The destination (char[]) does not need to be empty before copying. Functions like strcpy() or strncpy() overwrite the content in dest starting from index 0.

However, you must ensure that:
dest has enough space to store the entire source string plus the null terminator (\0).
The existing content is irrelevant — it will be overwritten.

🔹 2. Does it always overwrite the data in destination?
✅ Yes, always — starting from index 0.
Copying functions overwrite dest from the beginning up to the end of the source string, including the \0.

Scenario	                Overwrites Data?	 Notes
dest is empty	            ✅ Yes	            Overwrites \0 at index 0
dest has previous data	    ✅ Yes	            Overwrites content from
                                                 index 0 onward
dest is too small for src	❌ UB	            Undefined behavior
                                                 (buffer overflow)
src is smaller than dest	✅ Partial	        Only a portion is
                                                 overwritten; 
                                                 rest stays as-is

🔹 3. Why doesn’t cout << dest; print everything after copy?
Because cout << dest; treats dest as a C-style string, and stops at the first null terminator \0.

Example:
    char dest[20] = "HelloWorld123";
    strcpy(dest, "Hi");
    std::cout << dest;  // Output: Hi

Even though "World123" remains in memory after index 2, cout stops printing at the \0.

💡 Null terminator (\0) marks the end of the string for all standard functions including cout, strlen, strcpy, etc.

🔹 4. Can we access memory after \0?
✅ Yes, you can manually access memory beyond the \0 as long as you're within the array bounds.
    for (int i = 0; i < 20; ++i) {
        if (dest[i] == '\0')
           std::cout << "\\0 ";
        else
            std::cout << dest[i] << " ";
    }

This loop prints all 20 characters in dest, regardless of the null terminator.
⚠️ Accessing memory beyond array bounds (like dest[20] in a char dest[20]) is undefined behavior.

🔹 5. Internal Behavior of strcpy()
    strcpy(dest, src);

Internally:
Loops through each character in src
Copies character-by-character into dest
Stops after copying \0

    while ((*dest++ = *src++) != '\0');

🔹 6. strncpy() vs strcpy()
Feature	            strcpy()	                 strncpy()
Null-termination	✅ Always	                ❌ Not guaranteed 
                                                 (if n too small)
Safer?	            ❌ Risk of buffer overflow	⚠️ Safer but tricky to
                                                 use correctly
Use Case	        When you know dest         	 When limiting copy 
                    is big enough size           to specific 

🔹 7. Memory Diagram Example
Before:
    char dest[20] = "HelloWorld123";

Memory:
Index:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 ...
Value:   H  e  l  l  o  W  o  r  l  d  1  2  3 \0 ...

After:
    strcpy(dest, "Hi");

Memory:
Index:   0   1   2   3   4   5 ...
Value:   H   i  \0   l   o   W ...
Only the first 3 bytes are overwritten — the rest remain unchanged.
*/
