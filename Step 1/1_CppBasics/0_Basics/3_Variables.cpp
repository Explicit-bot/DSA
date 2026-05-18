/*
================================================================================
                                VARIABLES IN C++
================================================================================
What is a Variable?
-------------------
A variable is a named memory location used to store data.

When your program runs, RAM (memory) is used.
A variable gives a name to a portion of that memory.

E.g:
    int age = 20;

Here:
    int  -> datatype
    age  -> variable name (identifier)
    =    -> assignment operator
    20   -> value stored

Meaning:
"Create a memory location named age capable of storing an integer
and store value 20 inside it."

--------------------------------------------------------------------------------
What Happens Internally?
--------------------------------------------------------------------------------
Compiler:
I.   Checks datatype
II.  Reserves memory
III. Associates name with memory address
IV.  Stores binary representation of value

--------------------------------------------------------------------------------
Variables are Stored in Memory
--------------------------------------------------------------------------------
Variables are generally stored in RAM during program execution.

Local variables are usually stored in stack memory.
Global variables are usually stored in data segment memory.

--------------------------------------------------------------------------------
Identifier
--------------------------------------------------------------------------------
The name given to variables, functions, arrays, classes, etc.
is called an identifier.

Example:
    int age = 20;

Here:
    age is an identifier.

--------------------------------------------------------------------------------
Variable Naming Rules
--------------------------------------------------------------------------------
I.   Only alphabets (a-z, A-Z), digits (0-9), and underscore (_) allowed.
II.  No special symbols allowed except underscore (_).
III. Cannot start with a digit.
IV.  Cannot use reserved keywords.
V.   Variable names are case-sensitive.
Examples:
    age
    Age
    AGE

All are different variable names.

--------------------------------------------------------------------------------
Reserved Keywords
--------------------------------------------------------------------------------
Reserved keywords are predefined words already understood by compiler.

Examples:
    int
    float
    if
    else
    while
    return
    class
    public
    private etc.

Invalid:
    int while = 5;

--------------------------------------------------------------------------------
A Variable Must Be Declared Before Use
--------------------------------------------------------------------------------
Invalid:
    cout << x;
    int x = 10;

Correct:
    int x = 10;
    cout << x;

================================================================================
                DECLARATION vs INITIALIZATION vs ASSIGNMENT
================================================================================

Basic Syntax:
--------------
    datatype variable_name;

--------------------------------------------------------------------------------
A. Declaration
--------------------------------------------------------------------------------
Creating variable.

Example:
    int x;

Memory is reserved.

--------------------------------------------------------------------------------
B. Initialization
--------------------------------------------------------------------------------
Giving first value at creation time.

Example:
    int x = 10;

--------------------------------------------------------------------------------
C. Assignment
--------------------------------------------------------------------------------
Giving/changing value later.

Example:
    x = 50;

--------------------------------------------------------------------------------
Important Distinction
--------------------------------------------------------------------------------
Declaration:
    Creates variable name.

Initialization:
    Gives first value.

Assignment:
    Changes value later.

================================================================================
            DECLARATION vs DEFINITION
================================================================================

Declaration:
    Tells compiler that variable exists.

Definition:
    Actually allocates memory.

Example:
    extern int x;   // Declaration

    int x = 10;    // Definition

Usually both happen together:
    int x;

================================================================================
                    TYPES OF VARIABLE INITIALIZATION
================================================================================

--------------------------------------------------------------------------------
A. Copy Initialization
--------------------------------------------------------------------------------
Syntax:
    int x = 10;

Looks like copying.

--------------------------------------------------------------------------------
B. Direct Initialization
--------------------------------------------------------------------------------
Syntax:
    int x(10);

Uses parentheses.

--------------------------------------------------------------------------------
C. Brace Initialization (Uniform Initialization)
--------------------------------------------------------------------------------
Modern C++ preferred style.

Syntax:
    int x{10};

or

    int x = {10};

Why Important?
---------------
Prevents narrowing conversion.

Example:
    int x{3.5};   // ERROR

Because decimal data may be lost.

But this works:
    int x = 3.5; // Allowed but dangerous

Value becomes:
    3

Fraction lost.

--------------------------------------------------------------------------------
Narrowing Conversion
--------------------------------------------------------------------------------
Converting a larger or more precise datatype into a smaller or
less precise datatype causing possible data loss.

Example:
    int x = 3.9;

Value becomes:
    3

--------------------------------------------------------------------------------
D. Default Initialization
--------------------------------------------------------------------------------
Syntax:
    int x;

No value assigned.

Local variables contain garbage values.
Global,static variables auto initialized to zero.

--------------------------------------------------------------------------------
Garbage Value
--------------------------------------------------------------------------------
The random value present in an uninitialized local variable.

Example:
    int x;
    cout << x;

Output may be unpredictable.

--------------------------------------------------------------------------------
E. Value Initialization
--------------------------------------------------------------------------------
Syntax:
    int x{};

Automatically initializes variable to zero/default value.

| Type  | Value |
|-------|--------|
| int   | 0      |
| float | 0.0    |
| char  | '\0'   |
| bool  | false  |

--------------------------------------------------------------------------------
All Main Initialization Types
--------------------------------------------------------------------------------
    int a = 10;   // Copy initialization
    int b(10);    // Direct initialization
    int c{10};    // Brace initialization
    int d = {10}; // Brace copy initialization
    int e;        // Default initialization
    int f{};      // Value initialization

================================================================================
                            SCOPE OF VARIABLES
================================================================================

Scope:
-------
Scope means:
"Where variable can be accessed."

Main Types:
------------
I.   Global Scope
II.  Local Scope
III. Block Scope
IV.  Function Scope
V.   Class Scope
VI.  Namespace Scope

--------------------------------------------------------------------------------
A. Local Scope
--------------------------------------------------------------------------------
Variables declared inside a function are local variables.
Accessible only inside that function.

Example:

    #include<iostream>
    using namespace std;

    int main() {
        int x = 10;

        cout << x;
    }

x exists only inside main().

--------------------------------------------------------------------------------
B. Block Scope
--------------------------------------------------------------------------------
A block-scoped variable is declared inside {} braces.

Can exist inside:
    • function
    • if block
    • loop
    • nested block

Created when block starts.
Destroyed when block ends.

Example 1:
-----------
    if(x > 0) {
        int temp = x;
        cout << temp;
    }

temp exists only inside if block.

Example 2:
-----------
    for(int i = 0; i < 5; i++) {
        int square = i * i;
        cout << square;
    }

square is created and destroyed during each iteration.

--------------------------------------------------------------------------------
C. Global Scope
--------------------------------------------------------------------------------
Variables declared outside all functions.

Accessible everywhere.

Example:

    #include<iostream>
    using namespace std;

    int x = 100;

    int main() {
        cout << x;
    }

================================================================================
                    LOCAL vs GLOBAL VARIABLE
================================================================================

Example:

    #include<iostream>
    using namespace std;

    int x = 50;

    int main() {

        int x = 10;

        cout << x;
    }

Output:
    10

Local variable gets priority.
Global variable becomes hidden.

--------------------------------------------------------------------------------
Accessing Hidden Global Variable
--------------------------------------------------------------------------------
Use Scope Resolution Operator ::

Example:
    cout << ::x;

================================================================================
                        VARIABLE SHADOWING
================================================================================

Variable Shadowing (Name Hiding):
---------------------------------
A variable declared in an inner scope hides variables of same name
in outer scopes.

Compiler Search Order:
-----------------------
Block Scope -> Local Scope -> Global Scope

Nearest scope gets highest priority.

Example:

    #include<iostream>
    using namespace std;

    int x = 100; // Global variable

    int main() {

        int x = 50; // Local variable

        int &mainX = x;

        {
            int x = 10; // Block variable

            cout << x << endl;      // 10
            cout << mainX << endl;  // 50
            cout << ::x << endl;    // 100
        }

        return 0;
    }

Important Points:
-----------------
x      -> nearest block variable
::x    -> global variable
mainX  -> reference to main's local variable

Hidden local variables cannot be directly accessed by name.

================================================================================
                        LIFETIME OF VARIABLES
================================================================================

Lifetime:
---------
"How long variable exists in memory."

Local Variable:
----------------
Destroyed after block ends.

Global Variable:
-----------------
Exists until entire program ends.

================================================================================
                        CONSTANTS vs VARIABLES
================================================================================

Variable:
----------
Can change value.

Example:
    int age = 20;
    age = 25;

Constant:
----------
Cannot change value.

Example:
    const int age = 20;

================================================================================
                        AUTO TYPE DEDUCTION
================================================================================

Modern C++ feature where compiler automatically detects datatype.

Example:
    auto x = 10;
    auto y = 3.14;

Compiler decides:
    x -> int
    y -> double

================================================================================
                        DYNAMIC INITIALIZATION
================================================================================

Initialization using expressions/runtime values.

Example:
    int a = 10;
    int b = a + 5;

================================================================================
                        VARIABLE MEMORY ADDRESS
================================================================================

Every variable has a memory address.

Example:
    int x = 10;

    cout << &x;

&varname gives address of variable.

================================================================================
                    STORAGE-BASED CLASSIFICATION
================================================================================

Variables can also be classified based on storage:

I.   Local Variables
II.  Global Variables
III. Static Variables
IV.  Register Variables
V.   External Variables

================================================================================
                    VALUES vs REFERENCES
================================================================================

Normal Variables:
-----------------
Store actual values.

References:
-------------
Store alias (another name) for existing variable.

Example:
    int x = 10;

    int &ref = x;

================================================================================
                            BEST PRACTICES
================================================================================

I.   Always initialize variables.
II.  Use meaningful variable names.
III. Prefer brace initialization {} in modern C++.
IV.  Avoid same variable names in nested scopes.
V.   Keep variable scope as small as possible.

================================================================================
                                IMPORTANT 
================================================================================

1. A variable is an abstraction over a memory location.
2. Brace initialization is safer because it prevents narrowing conversion.
3. Nearest scope gets highest priority during variable lookup.
================================================================================
*/
