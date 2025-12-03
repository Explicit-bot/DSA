/*
🔹strlen()
✅ Function Signature:
    size_t strlen(const char* str);

✅ Purpose:
Returns the number of characters in the null-terminated C-string excluding the null character ('\0).

🧠 Internal Working:
 - It starts at the memory address pointed to by str.
 - Reads each byte until it encounters the null terminator ('\0').
 - So if it founds \0 in between the string somewhere it will give the
   size till then.(Explained in last example)
 - Counts how many bytes it passed.
 
Code:
    size_t my_strlen(const char* str) {
        size_t len = 0;
        while (str[len] != '\0') {
            ++len;
        }
        return len;
    }

What is size_t??
 -explained in the end

🧠 Example:    
    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};

🧠 strlen(str) will:
Read 'H' → count = 1
Read 'e' → count = 2
Read 'l' → count = 3
Read 'l' → count = 4
Read 'o' → count = 5
Read '\0' → STOP

✅ Returns 5

⚠️ Edge Case:
    const char* s = "";
    std::cout << strlen(s);  // Output: 0

If you pass nullptr, it leads to undefined behavior (usually a crash):
    const char* s = nullptr;
    std::cout << strlen(s);  // ❌ Crash!

Only works on null terminated char arrays like it won't work on
e.g char s[]{'H','e','e','l','l','o'};
coz there is no \0 in the end



🔹strnlen() (C++17 or POSIX in older C++ compilers)
✅ Function Signature:
    size_t strnlen(const char* str, size_t maxlen);

✅ Purpose:
 - Returns the length of the string up to maxlen characters.
 - If '\0' is found before maxlen, it returns that length.
 - Otherwise, it returns maxlen.

🧠 Internal Working:
Same as strlen, but stops at maxlen if '\0' is not found.

Code for strnlen:
    size_t my_strnlen(const char* str, size_t maxlen) {
        size_t len = 0;
        while (len < maxlen && str[len] != '\0') {
            ++len;
        }
        return len;
    }

🧠 Memory Example:
    char str[10] = {'H', 'e', 'l', 'l', 'o'}; // No null character!

Memory layout:
Index	Value
0	'H'
1	'e'
2	'l'
3	'l'
4	'o'
5–9	???

⚠️ strlen(str) here is undefined behavior (no null termination)!
✅ strnlen(str, 5) is safe → returns 5
*/
#include <iostream>
#include <cstring>  // for strlen and strnlen

int main() {
    // Case 1: Proper null-terminated string
    const char* str1 = "Naman";
    size_t len1 = strlen(str1);
    size_t nlen1 = strnlen(str1, 10);

    std::cout << "=== Case 1: Null-terminated ===\n";
    std::cout << "Input string: " << str1 << "\n";
    std::cout << "strlen(str1): " << len1 << "\n";
    std::cout << "strnlen(str1, 10): " << nlen1 << "\n\n";

    // Case 2: Manually created character array with missing '\0'
    char buffer[10] = {'H', 'e', 'l', 'l', 'o'};  // No null terminator

    std::cout << "=== Case 2: No null-terminator (undefined behavior for strlen) ===\n";
    std::cout << "Buffer content (printed manually): ";
    for (int i = 0; i < 5; ++i) std::cout << buffer[i];
    std::cout << "\n";

    // strlen(buffer); // ❌ Undefined behavior! Uncommenting may crash
    size_t safe_len = strnlen(buffer, 10);
    std::cout << "strnlen(buffer, 10): " << safe_len << " (Safe)\n\n";

    // Case 3: Null-terminator present in middle
    char str3[10] = {'H', 'i', '\0', 'T', 'h', 'e', 'r', 'e'};
    std::cout << "=== Case 3: String with early null terminator ===\n";
    std::cout << "str3 content until '\\0': " << str3 << "\n";
    std::cout << "strlen(str3): " << strlen(str3) << "\n";
    std::cout << "strnlen(str3, 10): " << strnlen(str3, 10) << "\n\n";

    // Case 4: Empty string
    const char* str4 = "";
    std::cout << "=== Case 4: Empty string ===\n";
    std::cout << "strlen(str4): " << strlen(str4) << "\n";
    std::cout << "strnlen(str4, 10): " << strnlen(str4, 10) << "\n";

    return 0;
}

/*
📥 Sample Output:
=== Case 1: Null-terminated ===
Input string: Naman
strlen(str1): 5
strnlen(str1, 10): 5

=== Case 2: No null-terminator (undefined behavior for strlen) ===
Buffer content (printed manually): Hello
strnlen(buffer, 10): 5 (Safe)

=== Case 3: String with early null terminator ===
str3 content until '\0': Hi
strlen(str3): 2
strnlen(str3, 10): 2

=== Case 4: Empty string ===
strlen(str4): 0
strnlen(str4, 10): 0


✅ Code:
    size_t nlen1 = strnlen(str1, 10);

🔍 What is 10 for?
The 10 is the maximum number of characters strnlen() will look at in the string str1.

📌 strnlen(str1, 10) means:
“Count the length of str1, but look at most 10 characters — even if there’s no null terminator ('\0) within that.”

✅ Use cases:
When you’re dealing with unsafe or untrusted input (e.g., user input, buffer data).
Prevents reading past the intended memory (avoids buffer overrun).

🔧 Example:
    const char* str1 = "HelloWorld123";
    size_t nlen1 = strnlen(str1, 10);
    std::cout << nlen1; // Output: 10
Even though the full string is 13 chars, it returns 10 because we told it to stop at 10.
⚠️ If there's a '\0' before the 10th character:

It will stop early.
    const char* str1 = "Hi\0World";
    size_t nlen1 = strnlen(str1, 10); // returns 2


What is size_t??
size_t is an unsigned integer type used to represent sizes or counts, like array lengths or number of characters.

It's the standard return type for functions like strlen() and sizeof.

✅ Why use size_t in my_strlen(const char* str)?
The function counts characters (always ≥ 0), so a non-negative type is ideal.
size_t can store very large values (better than int), and avoids overflow in large strings.
It ensures compatibility with built-in functions.

🧠 Example:
size_t my_strlen(const char* str) {
    size_t len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

In short:
size_t is used for safe, non-negative counting of memory or elements — perfect for string lengths.
*/


/*
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s1[30]{"Hello world"};
    char s2[15]{"CH"};
    
    cout<<"Length before copy:"<<strlen(s1)<<"\n";
    strcpy(s1,s2);
    cout<<"s1 after copy:"<<s1<<"\n";
    cout<<"Length after copy:"<<strlen(s1)<<"\n";
    
    int count{};
    for(int i{0};i<13;++i){
        cout<<"element "<<count<<":"<<s1[i]<<"\n";
        ++count;
    }

    //changing \0 to a character
    s1[2]='A';
    cout<<"s1 after changing:"<<s1<<"\n";
    cout<<"Length after changing:"<<strlen(s1)<<"\n";
    cout<<"This only prints till\0.This will not be printed"<<"\n";

}

After copying in s1 if you check size of the char array it will give 2 as output coz the criteria of length calculation is it stops when it reaches \0 so what u get is visible length but there are still characters in the array . 

🧠 strlen(s1) will:
Read 'C' → count = 1
Read 'H' → count = 2
Read '\0' → STOP
doesn't read 'l'
doesn't read 'o'
doesn't read ' '
doesn't read 'w'
doesn't read 'o'
doesn't read 'r'
doesn't read 'l'
doesn't read 'd'

as u can see when i changed the \0 at index 2 to A the new length of Char array becomes 11.

Did you know that cout will stop printing if it encounter \0 in the buffer data you gave
*/

/*
🔹 Q1: What does strnlen(str1, 10) do?
A:
It returns the length of the string str1, but checks at most 10 characters.
If it finds '\0' before 10 characters, it stops there.
If not, it returns 10.

🔹 Q2: Is it necessary to give a number like 10 in strnlen()?
A:
✅ Yes, it's mandatory.
That second argument tells strnlen() how many characters to scan at most — it's what makes it safer than strlen().

🔹 Q3: So, will strnlen(str1, 10) always return 10 if there’s no '\0'?
A:
✅ Yes — if '\0' is not found in the first 10 characters, strnlen() returns 10.
But if it finds '\0' earlier (e.g. at index 5), it returns 5.

🔹 Q4: In char buffer[10] = {'H', 'e', 'l', 'l', 'o'}; why does strnlen(buffer, 10) return 5?
A:
Even though you didn't add '\0', the remaining elements of the array (indices 5 to 9) are automatically zero-initialized.
So strnlen() finds '\0' at index 5 and returns 5.

🔹 Q5: If strnlen() returns 5 here, shouldn't strlen(buffer) also work?
A:
✅ Yes, in this specific case it works — because '\0' exists due to zero-initialization.
But in general, strlen() is unsafe unless you're sure the string is null-terminated.
strnlen() is safe, because it limits how far it reads.

🔹 Q6: What if we do this?
    char buffer[5] = {'H', 'e', 'l', 'l', 'o'};
    size_t len = strnlen(buffer, 10);

A:
❌ This causes undefined behavior because:
The array has only 5 valid bytes
You're asking strnlen() to scan up to 10
It may read out of bounds, causing crashes or garbage output
*/
