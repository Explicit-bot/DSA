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

=========================================================================================

1. Fundamental (Primary/Built-in) Datatypes
These are predefined datatypes provided by the C++ language itself.
They are the basic building blocks of programming.

A. Integer Datatype (int)- Used to store whole numbers.
E.g:
    int a = 10;
    int b = -25;

Memory- Usually 4 bytes
Range: −2,147,483,648 to 2,147,483,647

Why Integer Exists?
Computers store data in binary:0s and 1s
An integer datatype is optimized for storing whole numbers efficiently.

-----------------------------------------------------------------------------------------

B. Character Datatype (char)- Stores a single character.
E.g:
    char grade = 'A';

Important:
• character is written in single quotes ' '
• Memory- Usually 1 byte

How Characters are Stored
Characters are internally stored using ASCII values.

Example:
Character	ASCII Value
A	        65
B	        66
Z           90
a	        97
z           122
0           48
9           57

So:
    char ch = 'A';    //Actually stores:65

Important Character Datatypes:-
1. char
Usually stores ASCII characters.
E.g:
    char ch = 'A';

2. wchar_t - Wide character datatype.
Used for larger character sets.
E.g:
    wchar_t ch = L'अ';      //Prefix L is used 

3. char16_t
Used for UTF-16 characters.
E.g:
    char16_t ch = u'ह';     //Prefix u is used 

4. char32_t
Used for UTF-32 characters.
E.g:
    char32_t ch = U'🌍';    //Prefix U is used

-----------------------------------------------------------------------------------------

C. Floating Point Datatypes
Used for decimal numbers and exponentials.

E.g:
    float price = 10.5;
    double distance = 45E12    // 45E12 is equal to 45*10^12
    double distance = 45E-12    // 45E12 is equal to 45*10^-12

•Float- Usually 4 bytes - Less precision - About 6-7 decimal digits
•Double- Usually 8 bytes - More precision - About 15 decimal digits

Why Double is Preferred
Because float loses accuracy faster.
E.g: 
    float x = 3.1415926535;
May store: 
    x = 3.14159;
But,
    double y = 3.1415926535;  //will store the same as 11 digits only.

Note:- 
We must add the suffix f or F at the end of a float value. This is because the compiler interprets decimal values without the suffix as double.

-----------------------------------------------------------------------------------------
    
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

-----------------------------------------------------------------------------------------

E. Void Datatype - void means: “no datatype” or “no value”
Used mainly in functions.
when:
    •no value returned,
    •no parameters.

Example:
    void display() {
        cout << "Hello";
    }
This function returns nothing.

=========================================================================================

2. Derived Datatypes
Derived datatypes are created from fundamental datatypes.

A. Array
Stores multiple values of same datatype together.

Example:
    int arr[5] = {1,2,3,4,5};
Memory Layout: [1][2][3][4][5]      //Stored continuously in memory

•Fast access using index, e.g : cout << arr[2];  //Output: 3

-----------------------------------------------------------------------------------------

B. Pointer
Stores address of another variable.
Example:
    int x = 10;
    int* ptr = &x;

Here:
ptr stores address of x

Important:
• Usually 8 bytes on modern 64-bit systems
• Extremely important in:
    -Dynamic memory
    -Linked list
• Trees
• OS
• System programming

-----------------------------------------------------------------------------------------

C. Reference
Reference is another name (alias) for an existing variable.
Example:
    int x = 10;
    int& ref = x;

Now:
ref and x refer to same memory
Changing one changes the other.

Example:
    ref = 20;
    cout << x;      //Output: 20

-----------------------------------------------------------------------------------------

D. Function
Functions are also considered derived datatypes.

Example:
    int add(int a, int b) {
        return a + b;
    }

Here:
return type = int
parameter types = int

-----------------------------------------------------------------------------------------

E. string
Used to store text/words/sentences.

Example:
    string name = "Naman";


=========================================================================================
3. User-defined Datatypes
These are created by programmers.
Main user-defined datatypes:
Type	    Purpose
struct	    Group different data
class	    OOP programming
union	    Shared memory
enum	    Named constants
typedef	    Alias name

A. typedef
• To give meaning full names to the variables typedef is used
• It is also used to define user define data type
• It is used for better readability of a program

Ex:
    #include <iostream>

    typedef int marks ;
    typedef int rollno ;
    typedef unsigned long long int ull;

    int main( ) {
        marks m1, m2, m3;
        rollno r1 ,r2, r3;
        ull x;

    }
Code becomes cleaner and easier to read.

-----------------------------------------------------------------------------------------

B. Enumerated
Enum is a way to give meaningful names to a fixed set of related numbers so humans can understand the code.
enum GameState {
    MENU,
    PLAYING,
    PAUSED,
    GAME_OVER
};

Would you want to read this?
    if (state == 3) {
    ???  
    }

Or this?
    if (state == GAME_OVER) {
        rip  
    }
This is where enum helps.

🧠 What actually happens
Compiler stores enums as integers
Ex :
enum days { mon , tue , wed , thu , fri , sat , sun };
            0     1     2      3      4     5     6
    
Internally:
mon → 0
tue → 1
wed → 2
thu → 3
fri → 4
sat → 5
sun → 6

Day d = wed;   // computer sees: int d = 2;
➡️ No extra memory, no extra time, zero overhead

•Here you can access the values that are assigned to it already
you cannot define your own values here.
•By default the index value assigned is 0 but you can change it if you
  want  e.g.
    enum dept { CS=2, IT , EEE=9, CIVIL };
                 2    3     9       10
•Enum Size - Usually 4 bytes
 Because internally enums are generally stored as integers.

-----------------------------------------------------------------------------------------

C. struct
• Structure groups different datatypes together.
• By default all members in struct are public.
Example:
    struct Student {
        string name;
        int roll;
        float cgpa;
    };
Now we can create objects: 
    Student s1;

Assign values:
    s1.name = "Naman";
    s1.roll = 21;
    s1.cgpa = 8.5;

Why struct Exists
Without struct:
    string name1;
    int roll1;
    float cgpa1;

    string name2;
    int roll2;
    float cgpa2;

- Messy and difficult to manage.
- Struct groups related data together.

-----------------------------------------------------------------------------------------

D. class
Class is an advanced version of struct used in Object Oriented Programming.
A class contains:
* Data members
* Member functions

Example:
    class Student {
    public:
        string name;
        int roll;

        void display() {
            cout << name << " " << roll;
        }
    };

Object creation:
Student s1;

In struct: members are public by default
In class: members are private by default

-----------------------------------------------------------------------------------------

E. union
Union allows multiple members to share the same memory location.
Example:
    union Data {
        int x;
        char ch;
    };

    Data d;
    d.x = 65;

    cout << d.x;        //gives 65

    Now if:
    d.ch = 'A';

Previous value may get overwritten because same memory is shared.
• In struct: Each member gets separate memory
• In union: All members share same memory so only one member should be used at a time.


Why union Exists ??
Used for:
* Memory optimization
* Embedded systems
* Low-level programming
* Hardware communication

-----------------------------------------------------------------------------------------

Note:
1. Datatype sizes can vary depending on:
   * Compiler
   * Operating system
   * Architecture (32-bit or 64-bit)
So,Always use sizeof(datatype) instead of assuming size.

2. Modern systems are usually 64-bit systems so pointers are generally 8 bytes.

3. C++ is strongly typed:
    * Every variable must have a datatype
    * Datatype determines:
        - memory allocation
        - range
        - operations allowed
        - performance

------------------- Use sizeof() to check the size of any datatype ----------------------
*/
#include<iostream>
using namespace std;

int main() {

    cout << sizeof(int);       //Datatype(e.g. int , char ,long etc)

    return 0;
}

