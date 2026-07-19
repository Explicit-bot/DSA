/*
1. WHAT IS TYPE CONVERSION?
--------------------------------------------------------
Type Conversion means converting data from one data type
to another.

Examples:
    int -> double
    double -> int
    char -> int

C++ supports two types of conversions:
1. Implicit Conversion (Automatic Conversion)
2. Explicit Conversion (Type Casting)

=========================================================================================
1. IMPLICIT TYPE CONVERSION - Conversion automatically performed by the compiler.

Also called:
- Automatic Conversion
- Implicit Casting

Syntax: No special syntax needed.

Example:
    int num_int = 9;
    double num_double;
    num_double = num_int;
    cout << num_double;

Output: 9
Compiler automatically converts (9 -> 9.0) before storing into double.

WHY IMPLICIT CONVERSION EXISTS?
• Without it, arithmetic between different types would
be difficult.

Example:
    int a = 5;  
    double b = 2.5;     
    double c = a + b;

Internally: 5 becomes 5.0
Operation:  5.0 + 2.5 = 7.5

========================================================
WIDENING CONVERSION
========================================================
• Converting smaller type to larger type safely.
• Usually Safe as larger type can store all values of smaller type.
E.g:
    int x = 5;
    double y = x;
Internally: 5 becomes 5.0 (No data loss occurs)

Examples:
---------
    int -> double
    char -> int
    float -> double
    int -> long long

E.g: char -> int
--------
    int x = 300;
    char c = x;

Problem: char usually stores: -128 to 127.So,300 cannot fit.
Result: Overflow / unexpected value

========================================================
NARROWING CONVERSION
========================================================
• Converting larger type into smaller type.
• May cause:
    - Data loss
    - Precision loss
    - Overflow
    - Truncation

E.g:
    double x = 3.1415926535;
    float y = x;    //y=3.141592 (Precision loss - Some digits are lost.) 
    int y = x;      //9.99 becomes 9 (data loss)

TRUNCATION- Removing fractional part during floating-point to integer
conversion.
    9.99  -> 9
    3.14  -> 3
    -7.89 -> -7

Examples:
---------
    double -> int
    long long -> int
    int -> char
    double -> float

========================================================
ARITHMETIC CONVERSION RULES
========================================================
When different data types are used together,
C++ converts them to a common larger type.
    int + double   -> double
    char + int     -> int
    float + double -> double
    short + int    -> int

E.g: char -> int
Smaller integer types automatically promoted to int
during arithmetic operations.

Example:
    char a = 10;
    char b = 20;
    cout << a + b;

Internally: Both chars become int.
Result type: int

=========================================================================================
2. EXPLICIT CONVERSION (TYPE CASTING)- Manual conversion performed by programmer.

WHY EXPLICIT CASTING IS NEEDED
Example:
    int a = 5;
    int b = 2;
    cout << a / b;

Output: 2
Reason: Integer division occurs.
--------------------------------------------------------
Correct Version
    cout << (double)a / b;
Now: 5.0 / 2

Output: 2.5

========================================================
TYPES OF EXPLICIT CASTING
========================================================

I. C-style Casting
II. Function-style Casting
III. Named Casts (Modern C++)

========================================================
I. C-STYLE CASTING- Old C language style.
Syntax: 
    (data_type)expression

Example:
    double x = 3.14;
    int y = (int)x;

Output: 3

========================================================
II. FUNCTION-STYLE CASTING - Looks like function call.
Syntax:
    data_type(expression)

Example:
    double x = 3.14;
    int y = int(x);

•BOTH OLD STYLES DO SAME THING (int)x and int(x) both perform conversion.

• WHY OLD CASTS ARE DANGEROUS
- Unsafe
- Hard to debug
- Less readable
- Compiler performs weak checking
- Can force dangerous conversions

Dangerous Example:
    int x = 65;
    char* ptr = (char*)x;
May crash program.

========================================================
III. NAMED CASTS- Modern C++ provides safer casts.
Four named casts:
a. static_cast
b. dynamic_cast
c. const_cast
d. reinterpret_cast

========================================================
a. static_cast
Used For:
- Numeric conversions
- Safe related conversions

Example:
    double x = 3.14;
    int y = static_cast<int>(x);

Output: 3

Advantages:
- Safer
- More readable
- Compiler checked
- Preferred in modern C++

========================================================
b. dynamic_cast - Used mainly in inheritance and polymorphism.
Performs safe runtime casting.

Example:
    Base* b = new Derived;
    Derived* d = dynamic_cast<Derived*>(b);

Used in:
--------
Object-Oriented Programming

========================================================
c. const_cast - Used to add/remove const qualifier.

Example:
    const int x = 5;
    int* p = const_cast<int*>(&x);

Danger:
-------
Modifying truly const object causes undefined behavior.

========================================================
d. reinterpret_cast - Lowest-level cast.
Reinterprets raw memory.
Very dangerous.

Example:
    int x = 65;
    char* p = reinterpret_cast<char*>(&x);

Used in:
--------
- System programming
- Embedded systems
- Memory manipulation
*/
