/*
you can create arrays of any valid data type — both built-in and user-defined types.
Let’s go through it in a structured way:
✅ 1. Built-in Data Type Arrays
You can make arrays of all these built-in types:
                                                   (only values of the same data type)
Data Type           Array Declaration Example           Valid Elements You Can Enter
int                 int arr[5];                         1, -10, 999, 0
float               float scores[3];                    1.5, -0.99, 3.1415
double              double values[2];                   123.456, -9.99, 1.0e10
char                char name[10];                      ‘a’, ‘Z’, ‘3’, ‘@’
bool                bool flags[4];                      true, false
long                long big[5];                        100000L, -999999L
short               short s[5];                         small integers
unsigned int        unsigned int u[5];                  0, 1, 99999

✅ 2. User-defined Type Arrays
You can also make arrays of structs, classes, or enums:
🔹 Struct Example:
    struct Point {
    int x, y;
    };

    Point points[5];  // Array of 5 points

🔹 Class Example:
    class Student {
    public:
        std::string name;
        int roll;
    };

    Student students[3];

🔹 Enum Example:
    enum Color { RED, GREEN, BLUE };
    Color palette[3];  // Can hold RED, GREEN, or BLUE

✅ 3. Pointer Arrays
You can store pointers:
    int* ptrs[5];  // array of 5 int pointers
    char* names[10]; // array of C-style strings

✅ 4. String Arrays
Use either:
🔸 C-style:
    char names[3][20];  // 2D array of chars for 3 names (max 20 chars each)
🔸 C++ std::string:
std::string names[3];  // Array of 3 string objects

🛑 What Can’t Be an Array Type?
❌ Invalid Array Types                  Why Not?
void arr[5];                            void has no size — can’t store data
function arr[5];                        Functions can’t be stored directly
auto arr[5];                            Type deduction needs initialization
*/
