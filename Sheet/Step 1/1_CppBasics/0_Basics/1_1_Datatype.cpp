/*
Datatypes in C++
│
├── 1. Fundamental / Primary Datatypes
│   │
│   ├── Integer Type
│   │   ├── int (4 bytes)
│   │   └── char (1 byte)
│   │
│   ├── Floating Point Type
│   │   ├── float (4 bytes)
│   │   └── double (8 bytes)
│   │
│   ├── Boolean Type
│   │   └── bool (1 byte)
│   │
│   └── Void Type
│       └── void (no storage)
│
├── 2. Derived Datatypes
│   │
│   ├── Array
│   ├── Pointer
│   ├── Reference
│   └── Function
│   └── string
|   
│
└── 3. User-defined Datatypes
    │
    ├── struct
    ├── class
    ├── union
    ├── enum    (explained in 5_Important_Concepts.cpp)
    └── typedef (explained in 5_Important_Concepts.cpp)
  
1. Fundamental (Primary/Built-in) Datatypes
These are predefined datatypes provided by the C++ language itself.
They are the basic building blocks of programming.

Main fundamental datatypes are:

A. Integer Datatype (int)- Used to store whole numbers.
E.g:
    int a = 10;
    int b = -25;

Memory
Usually:4 bytes

Range
Typically: −2,147,483,648 to 2,147,483,647

Why Integer Exists?
Computers store data in binary:0s and 1s
An integer datatype is optimized for storing whole numbers efficiently.

B. Character Datatype (char)- Stores a single character.
E.g:
    char grade = 'A';

Important:
character is written in single quotes ' '

Memory
Usually:1 byte

How Characters are Stored
Characters are internally stored using ASCII values.

Example:
Character	ASCII Value
A	        65
B	        66
Z           90
a	        97
z           122

So:
    char ch = 'A';
Actually stores:65

Example
    #include<iostream>
    using namespace std;

    int main() {
        char ch = 'A';

        cout << ch << endl;
        cout << (int)ch << endl;
    }

Output:
A
65

C. Floating Point Datatypes
Used for decimal numbers and exponentials.

E.g:
float price = 10.5;
double distance = 45E12    // 45E12 is equal to 45*10^12
double distance = 45E-12    // 45E12 is equal to 45*10^-12

Type	Precision
float	Single precision
double	Double precision

Float vs Double:
Float-Usually 4 bytes
Less precision
About 6-7 decimal digits

Double-Usually 8 bytes
More precision
About 15 decimal digits

Why Double is Preferred
Because float loses accuracy faster.
Example:
    float x = 3.1415926535;

May store:
3.14159
But double stores much more accurately.

Note:-
We must add the suffix f or F at the end of a float value. This is because the compiler interprets decimal values without the suffix as double.

D. Boolean Datatype (bool)- usually 1 byte
Stores:
true
false

E.g:
    bool isPassed = true;


Internal Representation
Value	Stored As
true	1
false	0

E. Void Datatype
void means:“no datatype” or “no value”

Used mainly in functions.

Used when:
no value returned,
no parameters.

Example:

void show();

E.g:
    void display() {
        cout << "Hello";
    }

This function returns nothing.

2. Derived Datatypes
Derived datatypes are created from fundamental datatypes.
Will Study later in detail

3. User-defined Datatypes
These are created by programmers.

Main user-defined datatypes:

Type	    Purpose
struct	    Group different data
class	    OOP programming
union	    Shared memory
enum	    Named constants
typedef	    Alias name

Will study later in detail 


+-------------------+--------------------------------+----------------------------------------------+
| Datatype          | Stores                        | Important Point                              |
+-------------------+--------------------------------+----------------------------------------------+
| int (4 bytes)     | Whole numbers                 | Most commonly used integer datatype          |
| char (1 byte)     | Single character              | Stores ASCII character like 'A'              |
| float (4 bytes)   | Decimal numbers               | Less precise decimal storage                 |
| double (8 bytes)  | Decimal numbers               | More precise than float                      |
| bool (1 byte)     | True or False                 | Internally stores 0 or 1                     |
| void (0 bytes)    | No value                      | Used when nothing is returned by function    |
| array             | Multiple same-type values     | Elements stored continuously in memory       |
| pointer (8 bytes) | Memory address                | Stores address of variable                   |
| reference         | Alias of variable             | Another name of existing variable            |
| struct            | Different datatypes together  | User-defined collection                      |
| class             | Data + functions together     | Base of Object Oriented Programming          |
| union             | Shared memory members         | Only one member active at a time             |
| enum (4 bytes)    | Named integer constants       | Makes code more readable                     |
| string            | Collection of characters/text | Used for words and sentences                 |
+-------------------+--------------------------------+----------------------------------------------+


------------- Use this to check the size of any datatype-----------------

#include<iostream>
using namespace std;

int main() {

    cout << sizeof(//Datatype(e.g. int , char ,long etc));

    return 0;
}
*/

