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

========================================================
2. IMPLICIT TYPE CONVERSION
========================================================
Conversion automatically performed by the compiler.

Also called:
------------
- Automatic Conversion
- Implicit Casting

Syntax:
-------
No special syntax needed.

Example:
    int num_int = 9;
    double num_double;
    num_double = num_int;
    cout << num_double;

Output: 9
Compiler automatically converts
    9 -> 9.0
before storing into double.

========================================================
3. WIDENING CONVERSION
========================================================
Converting smaller type to larger type safely.

Examples:
---------
    int -> double
    char -> int
    float -> double
    int -> long long

• Usually Safe as larger type can store all values of smaller type.
Example:
    int x = 5;
    double y = x;

Internally: 5 becomes 5.0 (No data loss occurs)

========================================================
4. IMPLICIT CONVERSION: double -> int
========================================================

Example:
--------

#include <iostream>
using namespace std;

int main() {

    double num_double = 9.99;

    int num_int;

    num_int = num_double;

    cout << num_int;
}

Output:
-------
9

Explanation:
------------
Decimal part gets removed.

9.99 -> 9

This is called truncation.

========================================================
5. NARROWING CONVERSION
========================================================

Definition:
------------
Converting larger type into smaller type.

Examples:
---------
    double -> int
    long long -> int
    int -> char
    double -> float

Danger:
-------
May cause:
    - Data loss
    - Precision loss
    - Overflow
    - Truncation

========================================================
6. TRUNCATION
========================================================
Definition:
------------
Removing fractional part during floating-point to integer
conversion.

Example:
--------

double x = 9.99;
int y = x;

Result:
-------
y = 9

IMPORTANT:
----------
C++ DOES NOT ROUND.

Examples:
---------
9.99  -> 9
3.14  -> 3
-7.89 -> -7

========================================================
7. DATA LOSS DURING CONVERSION
========================================================

--------------------------------------------------------
A) INTEGER DATA LOSS
--------------------------------------------------------

Example:
--------

int x = 300;
char c = x;

Problem:
--------
char usually stores:
    -128 to 127

300 cannot fit.

Result:
-------
Overflow / unexpected value

--------------------------------------------------------
B) FLOATING POINT PRECISION LOSS
--------------------------------------------------------

Example:
--------

double x = 3.1415926535;
float y = x;

Problem:
--------
float has lower precision than double.

Result:
-------
Some digits are lost.

--------------------------------------------------------
C) FLOATING POINT -> INTEGER
--------------------------------------------------------

Example:
--------

double x = 7.99;
int y = x;

Result:
-------
7

Fraction removed.

========================================================
8. WHY IMPLICIT CONVERSION EXISTS
========================================================

Without it, arithmetic between different types would
be difficult.

Example:
--------
int a = 5;
double b = 2.5;

double c = a + b;

Internally:
-----------
5 becomes 5.0

Operation:
----------
5.0 + 2.5 = 7.5

========================================================
9. INTEGER PROMOTION
========================================================

Definition:
------------
Smaller integer types automatically promoted to int
during arithmetic operations.

Example:
--------

char a = 10;
char b = 20;

cout << a + b;

Internally:
-----------
Both chars become int.

Result type:
------------
int

========================================================
10. ARITHMETIC CONVERSION RULES
========================================================

When different data types are used together,
C++ converts them to a common larger type.

Examples:
---------

int + double   -> double
char + int     -> int
float + double -> double
short + int    -> int

========================================================
11. EXPLICIT CONVERSION (TYPE CASTING)
========================================================

Definition:
------------
Manual conversion performed by programmer.

Programmer explicitly tells compiler:

"Convert this value into another type."

========================================================
12. WHY EXPLICIT CASTING IS NEEDED
========================================================

Example:
--------

int a = 5;
int b = 2;

cout << a / b;

Output:
-------
2

Reason:
-------
Integer division occurs.

--------------------------------------------------------
Correct Version
--------------------------------------------------------

cout << (double)a / b;

Now:
----
5.0 / 2

Output:
-------
2.5

========================================================
13. TYPES OF EXPLICIT CASTING
========================================================

1. C-style Casting
2. Function-style Casting
3. Named Casts (Modern C++)

========================================================
14. C-STYLE CASTING
========================================================

Old C language style.

Syntax:
-------

(data_type)expression

Example:
--------

double x = 3.14;

int y = (int)x;

Output:
-------
3

========================================================
15. FUNCTION-STYLE CASTING
========================================================

Looks like function call.

Syntax:
-------

data_type(expression)

Example:
--------

double x = 3.14;

int y = int(x);

========================================================
16. BOTH OLD STYLES DO SAME THING
========================================================

(int)x

and

int(x)

both perform conversion.

========================================================
17. WHY OLD CASTS ARE DANGEROUS
========================================================

Problems:
---------
- Unsafe
- Hard to debug
- Less readable
- Compiler performs weak checking
- Can force dangerous conversions

Dangerous Example:
------------------

int x = 65;

char* ptr = (char*)x;

May crash program.

========================================================
18. MODERN C++ NAMED CASTS
========================================================

Modern C++ provides safer casts.

Four named casts:
-----------------
1. static_cast
2. dynamic_cast
3. const_cast
4. reinterpret_cast

========================================================
19. static_cast
========================================================

Most commonly used cast.

Used For:
---------
- Numeric conversions
- Safe related conversions

Example:
--------

double x = 3.14;

int y = static_cast<int>(x);

Output:
-------
3

Advantages:
-----------
- Safer
- More readable
- Compiler checked
- Preferred in modern C++

========================================================
20. dynamic_cast
========================================================

Used mainly in inheritance and polymorphism.

Performs safe runtime casting.

Example:
--------

Base* b = new Derived;

Derived* d = dynamic_cast<Derived*>(b);

Used in:
--------
Object-Oriented Programming

========================================================
21. const_cast
========================================================

Used to add/remove const qualifier.

Example:
--------

const int x = 5;

int* p = const_cast<int*>(&x);

Danger:
-------
Modifying truly const object causes undefined behavior.

========================================================
22. reinterpret_cast
========================================================

Lowest-level cast.

Reinterprets raw memory.

Very dangerous.

Example:
--------

int x = 65;

char* p = reinterpret_cast<char*>(&x);

Used in:
--------
- System programming
- Embedded systems
- Memory manipulation

========================================================
23. WHICH CAST SHOULD YOU USE?
========================================================

static_cast
-------------
Normal conversions

dynamic_cast
--------------
Inheritance casting

const_cast
-----------
Removing/adding const

reinterpret_cast
-----------------
Raw memory reinterpretation

========================================================
24. MODERN C++ BEST PRACTICE
========================================================

Preferred:
----------

static_cast<int>(x)

Avoid:
------

(int)x

========================================================
25. COMPARISON EXAMPLE
========================================================

#include <iostream>
using namespace std;

int main() {

    double x = 9.99;

    int a = (int)x;

    int b = int(x);

    int c = static_cast<int>(x);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}

Output:
-------
9
9
9

========================================================
26. IMPORTANT INTERVIEW CONCEPTS
========================================================

Implicit Conversion:
--------------------
Automatic conversion by compiler.

Explicit Conversion:
--------------------
Manual conversion by programmer.

Widening Conversion:
--------------------
Safe larger conversion.

Example:
    int -> double

Narrowing Conversion:
---------------------
Unsafe smaller conversion.

Example:
    double -> int

Truncation:
-----------
Removing decimal part.

Example:
    9.99 -> 9

Precision Loss:
---------------
Loss of digits.

Example:
    double -> float

========================================================
27. BEST PRACTICES
========================================================

1. Prefer static_cast
---------------------

int x = static_cast<int>(3.14);

--------------------------------------------------------

2. Avoid C-style casts
----------------------

(int)x

--------------------------------------------------------

3. Be careful with narrowing conversions
----------------------------------------

int x = 1e10;

May overflow.

--------------------------------------------------------

4. Watch integer division
-------------------------

5 / 2 = 2

Use casting if decimal result needed.

========================================================
28. REAL-WORLD EXAMPLE
========================================================

Wrong:
------

int total = 5;
int students = 2;

double avg = total / students;

Output:
-------
2

Reason:
-------
Integer division occurs first.

--------------------------------------------------------
Correct Version
--------------------------------------------------------

double avg = static_cast<double>(total) / students;

Output:
-------
2.5

========================================================
29. QUICK REVISION TABLE
========================================================

int -> double
--------------
Type: Widening
Safe: Yes

double -> int
--------------
Type: Narrowing
Safe: No

float -> double
----------------
Type: Widening
Safe: Yes

double -> float
----------------
Type: Narrowing
Safe: Precision loss possible

char -> int
------------
Type: Promotion
Safe: Yes

========================================================
30. MOST IMPORTANT CORE IDEA
========================================================

Compiler tries to preserve information whenever possible.

Safe:
-----
int -> double

Unsafe:
-------
double -> int

When destination type cannot fully store source value,
information gets lost.

========================================================
31. ONE-LINE SUMMARY
========================================================

Implicit Conversion:
    Automatic by compiler

Explicit Conversion:
    Manual by programmer

Widening Conversion:
    Usually safe

Narrowing Conversion:
    Risky

Preferred Modern Cast:
    static_cast

========================================================
*/
