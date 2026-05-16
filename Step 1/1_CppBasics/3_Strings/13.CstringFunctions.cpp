/*
| Function  | Description                          |
| --------- | ------------------------------------ |
| `strlen`  | Get length of string                 |
| `strcpy`  | Copy string                          |
| `strncpy` | Copy limited characters              |
| `strcat`  | Concatenate strings                  |
| `strncat` | Concatenate limited characters       |
| `strcmp`  | Compare strings                      |
| `strncmp` | Compare first n characters           |
| `strchr`  | Find first occurrence of character   |
| `strrchr` | Find last occurrence of character    |
| `strstr`  | Find substring                       |
| `strtok`  | Tokenize string                      |
| `memset`  | Set memory                           |
| `memcpy`  | Copy memory                          |
| `memmove` | Safe memory copy (even with overlap) |
| `memcmp`  | Compare memory blocks                |
*/
#include <iostream>
#include <cstring>   // for all C-string functions
#include <cstdlib>   // for atoi, atof, etc.

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];

    // 1. strlen - get length
    std::cout << "1. strlen(str1): " << strlen(str1) << "\n";

    // 2. strcpy - copy string
    strcpy(str3, str1);
    std::cout << "2. strcpy(str3, str1): " << str3 << "\n";

    // 3. strncpy - copy n characters
    strncpy(str3, str2, 3);
    str3[3] = '\0';  // null terminate manually
    std::cout << "3. strncpy(str3, str2, 3): " << str3 << "\n";

    // 4. strcat - concatenate
    strcat(str1, str2);  // Hello + World
    std::cout << "4. strcat(str1, str2): " << str1 << "\n";

    // 5. strncat - concatenate n characters
    char name[50] = "Mr. ";
    strncat(name, str2, 3);  // Mr. + Wor
    std::cout << "5. strncat(name, str2, 3): " << name << "\n";

    // 6. strcmp - compare strings
    std::cout << "6. strcmp(\"abc\", \"abd\"): " << strcmp("abc", "abd") << "\n";

    // 7. strncmp - compare first n chars
    std::cout << "7. strncmp(\"abcde\", \"abczz\", 3): " << strncmp("abcde", "abczz", 3) << "\n";

    // 8. strchr - find first occurrence
    const char* found = strchr("apple", 'p');
    std::cout << "8. strchr(\"apple\", 'p'): " << (found ? found : "Not Found") << "\n";

    // 9. strrchr - find last occurrence
    found = strrchr("apple", 'p');
    std::cout << "9. strrchr(\"apple\", 'p'): " << (found ? found : "Not Found") << "\n";

    // 10. strstr - find substring
    const char* pos = strstr("hello world", "world");
    std::cout << "10. strstr(\"hello world\", \"world\"): " << (pos ? pos : "Not Found") << "\n";

    // 11. strtok - split into tokens
    char sentence[] = "one,two,three";
    char* token = strtok(sentence, ",");
    std::cout << "11. strtok: ";
    while (token) {
        std::cout << "[" << token << "] ";
        token = strtok(nullptr, ",");
    }
    std::cout << "\n";

    // 12. memset - set memory
    char buffer[10];
    memset(buffer, '-', 5);
    buffer[5] = '\0';
    std::cout << "12. memset(buffer, '-', 5): " << buffer << "\n";

    // 13. memcpy - copy memory
    char source[] = "Data";
    char dest[10];
    memcpy(dest, source, strlen(source)+1);  // +1 to copy '\0'
    std::cout << "13. memcpy(dest, source): " << dest << "\n";

    // 14. memmove - safe copy (handles overlap)
    char overlap[] = "abcdefgh";
    memmove(overlap + 2, overlap, 5);  // overlapping memory
    std::cout << "14. memmove(overlap+2, overlap, 5): " << overlap << "\n";

    // 15. memcmp - compare memory
    std::cout << "15. memcmp(\"abc\", \"abd\", 3): " << memcmp("abc", "abd", 3) << "\n";

    return 0;
}

/*
Sample Output:
1. strlen(str1): 5
2. strcpy(str3, str1): Hello
3. strncpy(str3, str2, 3): Wor
4. strcat(str1, str2): HelloWorld
5. strncat(name, str2, 3): Mr. Wor
6. strcmp("abc", "abd"): -1
7. strncmp("abcde", "abczz", 3): 0
8. strchr("apple", 'p'): pple
9. strrchr("apple", 'p'): ple
10. strstr("hello world", "world"): world
11. strtok: [one] [two] [three] 
12. memset(buffer, '-', 5): ----- 
13. memcpy(dest, source): Data
14. memmove(overlap+2, overlap, 5): ababcdeh
15. memcmp("abc", "abd", 3): -1

*/
