/*
🔹String Concatenation in <cstring>
C++ provides the following C-style string concatenation functions from <cstring>:

Function	Description
strcat	    Concatenates a C-string to the end of another.
strncat	    Concatenates at most n characters to avoid overflow.

*These work on null-terminated char arrays only — not on std::string.

🔸 1. char* strcat(char* dest, const char* src);
✅ Purpose:
Appends the src string to the end of dest. The result is stored in dest.
dest must have enough space to hold the result.
Both strings must be null-terminated.

✅ Syntax:
    char dest[100] = "Hello, ";
    char src[] = "World!";
    strcat(dest, src);

🧠 Internal Working:
Finds the null terminator '\0' in dest to determine where to start appending.
Copies each character from src until it finds its '\0'.
Appends the null terminator after the last character.

🔸 2. char* strncat(char* dest, const char* src, size_t n);
✅ Purpose:
Appends at most n characters from src to dest, and then appends '\0'.
Prevents buffer overflow.
Still requires dest to be large enough.

✅ Syntax:
    char dest[20] = "Hello, ";
    char src[] = "World!";
    strncat(dest, src, 3);  // Appends "Wor"
*/

//💻 Full Example Program Demonstrating Both
    #include <iostream>
    #include <cstring>

    int main() {
        // Case 1: strcat with enough space
        char dest1[50] = "Hello, ";
        const char* src1 = "Naman";
        strcat(dest1, src1);

        std::cout << "=== Case 1: strcat ===\n";
        std::cout << "After strcat(dest1, src1): " << dest1 << "\n\n";

        // Case 2: strncat appending part of the source
        char dest2[50] = "Welcome ";
        const char* src2 = "to IIIT Sonepat";
        strncat(dest2, src2, 5);  // Appends "to II"

        std::cout << "=== Case 2: strncat (only 5 characters) ===\n";
        std::cout<<"After strncat(dest2, src2, 5):"<<dest2<< "\n\n";

        // Case 3: No space in destination (unsafe!)
        char dest3[10] = "Hello"; // only 10 bytes
        const char* src3 = "World";  // strcat will write out of bounds!

        std::cout << "=== Case 3: strcat with no space (unsafe!) ===\n";
        // Uncommenting the next line is dangerous:
        // strcat(dest3, src3);  // ❌ undefined behavior

        std::cout << "dest3 has only 10 bytes and will overflow if we strcat!\n";

        return 0;
    }
/*
📤 Sample Output:
=== Case 1: strcat ===
After strcat(dest1, src1): Hello, Naman

=== Case 2: strncat (only 5 characters) ===
After strncat(dest2, src2, 5): Welcome to II

=== Case 3: strcat with no space (unsafe!) ===
dest3 has only 10 bytes and will overflow if we strcat!

🧠 Internal Memory Working (Case 1)
Let’s take:
    char dest[50] = "Hello, ";
    const char* src = "Naman";
    strcat(dest, src);

Before Concatenation:
dest	        src
"Hello, \0"	    "Naman\0"

After strcat:
dest
"Hello, Naman\0"

Characters from src are copied starting at '\0' position in dest.

⚠️ Common Mistakes
Not leaving space in dest	
 - Buffer overflow, crash, UB

Forgetting '\0' in either string	
 - strcat may read garbage memory

Using strncat but forgetting that it still appends '\0'	    
 - May cause off-by-one overflow
*/


/*
🔹 1. Q: If we have:
char dest3[10] = "Hello";  
const char* src3 = "World";
...and we do strcat(dest3, src3), does it replace the \0 or append after it?

A:
strcat() starts writing at the location of the \0 in dest, replacing it with the first character of src. So it effectively overwrites the null terminator, then appends src, and finally adds a new \0 at the end.

🔹 2. Q: But if dest3[10] already has all 10 bytes filled by "Hello", how can strcat() work without error?
A:
It does not work safely — it causes undefined behavior.
"Hello" uses 6 bytes (5 characters + \0), so only 4 bytes are left.
"World" needs 6 bytes → not enough space, so strcat() will overwrite memory beyond dest3, which is dangerous.

🔹 3. Q: What if we forget to add \0 at the end of the destination string?
A:
Then strcat() will not know where to start appending (it uses strlen(dest) internally), and will keep searching for a \0 in memory, possibly reading garbage → ❌ undefined behavior and possibly a crash.

🔹 4. Q: You said earlier that uninitialized spaces in char arrays are filled with \0 — does that ensure safety?
A:
Only when you use initializer lists, like:
    char dest[10] = {'H', 'e', 'l', 'l', 'o'}; // fills rest with \0
In that case, yes — the rest of the array is filled with \0, so strlen() will work.
But still, strcat() may not be safe unless enough space is available for the whole concatenated string and the null terminator.

🔹 5. Q: So you're saying strlen() works but strcat() doesn't? Why?
A:
Yes, in such partially initialized arrays:
✅ strlen() just scans until it finds the first \0 (which exists due to zero-filling).
❌ strcat() needs enough free space to copy all of src and add a new \0. If space is insufficient, it causes memory overrun.

🔹 6. Q: What if the size of dest was increased to 12 instead of 10? Would strcat() work?
A:
✅ Yes! Here's the math:
"Hello" = 6 bytes (H, e, l, l, o, \0)
"World" = 6 bytes (W, o, r, l, d, \0)
Concatenation will result in "HelloWorld\0" = 11 bytes
dest[12] has enough space → Safe ✅

🔹 7. Q: How can I be 100% sure that using strcat(dest, src) is safe?
A:
Follow this golden rule:
    strlen(dest) + strlen(src) + 1 <= sizeof(dest)
+1 is for the final \0
Always use sizeof(dest) instead of strlen(dest) when checking capacity

🔹 8. Q: Is there a safer alternative to strcat()?
A:
Yes. Use strncat():
    strncat(dest, src, n);  // appends at most n characters from src

But even this is not fully safe unless you manage the size properly. Safer option in C++ is using std::string.

🔹 9. Q: If dest and src overlap in memory, is strcat() safe?
A: ❌ No, strcat() assumes dest and src do not overlap.
Overlapping memory may lead to corruption or undefined behavior.
Use memmove() if overlapping is a possibility.

🔹 10. Q: What if I do strcat(dest, dest)? Will it work?
A: ❌ No, it invokes undefined behavior. You're modifying and reading the same string at once, which strcat() isn’t designed to handle.

🔹 11. Q: Does strcat() automatically add the null terminator \0 after appending?
A: ✅ Yes. strcat() appends characters from src and adds a \0 at the end of the result.

🔹 12. Q: What happens if the src string is not null-terminated?
A: ❌ Undefined behavior. strcat() will keep reading memory until it accidentally finds a \0 or hits a segmentation fault.

🔹 15. Q: What’s the difference between strncat and memcpy for string concatenation?
A:
strncat() is for null-terminated strings. It locates the \0, then appends src.
memcpy() just blindly copies memory — you must manage the offset, size, and \0 manually.

🔹 16. Q: Why might strcat() not crash even if I overflow the buffer?
A:
Because of undefined behavior — it might:
Work silently (very dangerous)
Overwrite other variables
Corrupt memory
Crash unexpectedly later
This makes it harder to debug. Always prefer safe patterns.

🔹 17. Q: Can I safely use strcat() inside a loop to build large strings?
A: Not recommended for C-style strings. Use:
std::string (preferred in C++)
strncat() carefully, only if buffer size is managed manually

🔹 19. Q: What happens if dest is uninitialized (e.g., char* dest;) and we call strcat(dest, src);?
A: ❌ Undefined behavior. dest points to garbage memory — writing into it will likely cause a crash.

🔹 20. Q: Is strcat() thread-safe?
A: ❌ No. If two threads write to the same dest buffer using strcat() without synchronization, it leads to data races and corrupted strings.


*/
