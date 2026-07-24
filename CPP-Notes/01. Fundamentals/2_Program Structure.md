# Program Structure in C++

Every C++ program follows a basic structure.

Understanding this structure makes it easier to read, write, and debug programs.

A minimal C++ program looks like this:

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello World";

    return 0;
}
```

---

# Basic Structure

```
Documentation / Comments
        │
Preprocessor Directives
        │
Namespace Declaration
        │
Global Declarations (Optional)
        │
main() Function
        │
Statements
        │
return Statement
```

---

# 1. Comments

Comments are ignored by the compiler.

They are used to:

- Explain code
- Improve readability
- Temporarily disable code
- Write notes

### Single-Line Comment

```cpp
// This is a comment
```

Shortcut (VS Code):

```
cmnd + /
```

---

### Multi-Line Comment

```cpp
/*
This
is
a
multi-line
comment
*/
```

Shortcut (VS Code):

```
Shift + option + A
```

---

# 2. Preprocessor Directives

Preprocessor directives begin with the `#` symbol.

They are processed **before compilation**.

Common directives:

```cpp
#include
#define
#ifdef
#ifndef
#pragma
```

Example:

```cpp
#include <iostream>
```

This tells the preprocessor to include the **iostream** header file.

---

# Header Files

Header files contain:

- Function declarations
- Classes
- Templates
- Constants

Common header files:

| Header | Purpose |
|---------|----------|
| `<iostream>` | Input / Output |
| `<string>` | Strings |
| `<cmath>` | Mathematics |
| `<vector>` | Dynamic Arrays |
| `<fstream>` | File Handling |
| `<iomanip>` | Output Formatting |

---

# Angle Brackets vs Double Quotes

### System Header

```cpp
#include <iostream>
```

Compiler searches system include directories.

---

### User Header

```cpp
#include "Student.h"
```

Compiler searches current project first.

---

# 3. Namespace

Many library functions belong to the **std** namespace.

Without it:

```cpp
std::cout << "Hello";
std::cin >> x;
```

With:

```cpp
using namespace std;
```

we can simply write:

```cpp
cout << "Hello";
cin >> x;
```

---

## Why Namespaces Exist

Different libraries may contain functions with the same name.

Namespaces avoid naming conflicts.

Example:

```cpp
A::print();

B::print();
```

---

## Is `using namespace std;` Recommended?

For small beginner programs:

✔ Yes

For large projects:

❌ Usually avoided.

Preferred:

```cpp
std::cout
std::cin
std::string
```

This avoids polluting the global namespace.

---

# 4. Global Declarations (Optional)

Anything declared outside every function belongs to the global scope.

Examples:

```cpp
int x = 10;

const double PI = 3.14159;

void display();
```

Global declarations are optional.

---

# 5. main() Function

Execution of every C++ program begins from the `main()` function.

Syntax:

```cpp
int main()
{

}
```

Every program must have exactly one `main()` function.

---

## Why is it Called main()?

The operating system looks for `main()` as the entry point of the program.

Execution starts here.

---

# Return Type of main()

```cpp
int main()
```

means:

The function returns an integer.

Usually:

```cpp
return 0;
```

---

## Meaning of return 0

```cpp
return 0;
```

means:

Program terminated successfully.

Non-zero values generally indicate an error.

Example:

```cpp
return 1;
```

---

# Statements

Statements are instructions executed by the program.

Example:

```cpp
cout << "Hello";

int x = 10;

x++;
```

Most statements end with a semicolon (`;`).

---

# Code Blocks

A block is a group of statements enclosed within braces.

Syntax:

```cpp
{
    statements
}
```

Examples:

```cpp
if(condition)
{
    ...
}
```

```cpp
while(condition)
{
    ...
}
```

```cpp
for(...)
{
    ...
}
```

---

# Semicolon (;)

The semicolon marks the end of a statement.

Correct:

```cpp
int x = 10;
```

Incorrect:

```cpp
int x = 10
```

This produces a compilation error.

---

# Braces { }

Braces define a block of code.

Example:

```cpp
if(x > 0)
{
    cout << x;
}
```

Although a single statement can omit braces:

```cpp
if(x > 0)
    cout << x;
```

Using braces is recommended for better readability and fewer bugs.

---

# Indentation

Indentation does not affect compilation.

It improves readability.

Good:

```cpp
if(x > 0)
{
    cout << x;
}
```

Poor:

```cpp
if(x>0){
cout<<x;
}
```

---

# A Complete Example

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World\n";

    int age = 20;

    cout << age;

    return 0;
}
```

Execution flow:

```
Program Starts
      │
      ▼
main()
      │
      ▼
Statements execute one by one
      │
      ▼
return 0
      │
      ▼
Program Ends
```

---
