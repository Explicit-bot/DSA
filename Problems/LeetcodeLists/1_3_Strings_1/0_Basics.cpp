/*
1. ASCII
Character	ASCII
A-Z         65-90
a-z	        97-122
0-9	        48-57
Space	    32

ASCII Relationships
Uppercase and lowercase differ by 32.
A = 65
a = 97
97-65 = 32

2. #include <cctype>
| Function      | Purpose              | Return Type         | Complexity |
| ------------- | -------------------- | ------------------- | ---------- |
|  isalpha(c)   | Alphabet?            | int (0 or non-zero) | O(1)       |
|  isdigit(c)   | Digit?               | int                 | O(1)       |
|  isalnum(c)   | Letter or digit?     | int                 | O(1)       |
|  islower(c)   | Lowercase letter?    | int                 | O(1)       |
|  isupper(c)   | Uppercase letter?    | int                 | O(1)       |
|  isspace(c)   | Whitespace?          | int                 | O(1)       |
|  ispunct(c)   | Punctuation?         | int                 | O(1)       |
|  isxdigit(c)  | Hex digit?           | int                 | O(1)       |
|  isprint(c)   | Printable character? | int                 | O(1)       |
|  iscntrl(c)   | Control character?   | int                 | O(1)       |
|  isgraph(c)   | Visible character?   | int                 | O(1)       |
|  tolower(c)   | Convert to lowercase | int                 | O(1)       |
|  toupper(c)   | Convert to uppercase | int                 | O(1)       |


*/
