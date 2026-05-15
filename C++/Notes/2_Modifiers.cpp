/*
C++ Data Type Modifiers
•Modifiers are keywords that change the behavior, size, range, or sign of basic
 data types.
•A modifier modifies a primitive type.
•E.g:
    short int x;
    long int y;
    unsigned int z;
Here:
    •short
    •long
    •unsigned
are modifiers.

C++ has these major modifiers:
| Modifier    | Purpose                     |
| ----------- | --------------------------- |
|  short      | Reduce size                 |
|  long       | Increase size               |
|  signed     | Allow positive and negative |
|  unsigned   | Only positive values        |
|  long long  | Very large integer range    |

Compatible Combinations:
| Base Type | short  | long | long long | signed | unsigned |
| --------- | ------ | ---- | --------- | ------ | -------- |
|  int      | ✅     | ✅    | ✅        | ✅      | ✅       |
|  char     | ❌     | ❌    | ❌        | ✅      | ✅       |
|  float    | ❌     | ❌    | ❌        | ❌      | ❌       |
|  double   | ❌     | ✅    | ❌        | ❌      | ❌       |
|  bool     | ❌     | ❌    | ❌        | ❌      | ❌       |

Important Note:
By default:
    int
is already:
    signed int
So these are same:
    int x;
    signed int x;

Modifier combinations possible:
Integer Types- If int is omitted, compiler usually assumes int.
    
    short int or short or signed short int or signed short
    unsigned short int or unsigned short

    int or signed or signed int 
    unsigned int or unsigned

    long int or long or signed long or signed long int
    unsigned long int or unsigned long 
    
    long long int or long long or signed long long or signed long long int
    unsigned long long int or unsigned long long

Character Types-char does NOT automatically mean signed or unsigned in standard C++.
    char
    signed char
    unsigned char
    wchar_t -------
    char16_t      |---------- Will study when required
    char32_t      |
    char8_t -------

Floating Types-
    float
    double
    long double

Important:-
•Integer Literal 10 is automatically: int

•Similarly,decimal Literal 3.14 is automatically: double NOT float.
That is why we write: 3.14f for float.

•Character Literal 'A' is type: char

•String Literal "Hello" is NOT string.
Internally it becomes: const char[] (character array)
Very important later for pointers/arrays.
*/
