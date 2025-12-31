/*
 ✅ DATATYPES AN ARRAY CAN BE OF (C++)
An array can be created for ANY data type, but:
➡️ All elements of the array must be of the SAME data type.

==============================================================
🔹 1️⃣ Primitive / Built-in Data Types
e.g.
int arr1[10];
char arr2[10];
float arr3[10];
double arr4[10];
bool arr5[10];

Complete list of primitive types:
• int
• char
• float
• double
• bool

==============================================================
🔹 2️⃣ Modified Primitive Types

short a1[10];
long a2[10];
long long a3[10];
unsigned int a4[10];
unsigned long long a5[10];

/*
Includes:
• short
• long
• long long
• signed
• unsigned
• All combinations (unsigned int, unsigned long, etc.)
*/


/*
==============================================================
🔹 3️⃣ Pointer Types
An array whose elements are pointers.
•Any datatype allowed
•All elements must point to SAME type

e.g.
int* p1[10];
char* p2[10];
void* p3[10];

🧠 Meaning
ptrs is an array
Size = 5
Each element is of type int*
So memory looks like:

ptrs:
[ p0 | p1 | p2 | p3 | p4 ]   // stored on stack / static
   ↓    ↓    ↓
  int  int  int   (somewhere else)

👉 The array stores addresses, not values.

🔹 Example (important)
int a = 10, b = 20, c = 30;
int* ptrs[3] = {&a, &b, &c};

cout << *ptrs[0]; // 10
cout << *ptrs[1]; // 20
cout << *ptrs[2]; // 30

🔹 char* names[10] (very common)
char* names[3] = {"Ram", "Shyam", "Aman"};

What happens?
Each element stores the address of a string literal
String literals are stored in read-only memory

⚠️ This is NOT a 2D array.
You cannot modify:
names[0][0] = 'K'; // ❌ undefined behavior

🧠 void* voidArr[n]; 
Declares an array of n generic pointers, where each element can store the address of any data type.

🔹 What it means
voidArr → array
Size → n
•Each element type → void* (generic pointer)
•Each element stores only an address, not the value.

✅ What it can do
•Can point to any data type (int, double, char, struct, etc.)
•Allows storing heterogeneous pointers in one array

int a = 10;
double b = 2.5;

void* voidArr[2];
voidArr[0] = &a;
voidArr[1] = &b;

❌ Limitations:-
• Cannot dereference directly
• No pointer arithmetic
• No type safety

*voidArr[0];     // ❌ invalid
voidArr[0] + 1;  // ❌ invalid

✅ Correct usage (type casting required)
cout << *(int*)voidArr[0];     // OK
cout << *(double*)voidArr[1];  // OK

📍 Memory
The array itself is stored on stack / static (depending on scope)
The data it points to can be anywhere (stack, heap, static)

==============================================================
🔹 4️⃣ Array of Arrays (Multidimensional Arrays)

int mat1[3][4];
char mat2[5][10];

Includes:
• 2D arrays
• 3D arrays
• n-dimensional arrays

==============================================================
🔹 5️⃣ User-Defined Data Types
e.g.
🔸 Structure Array 
    struct Student {
        int id;
    };
    Student students[10];

🔸 Class Array
    class Box {
        int x;
    };
    Box boxes[5];

🔸 Union Array 
    union Data {
        int x;
    };
    Data dataArr[5];

🔸 Enum Array 
    enum Color { RED, GREEN, BLUE };
    Color colors[3];

==============================================================
🔹 6️⃣ STL / Library Data Types
e.g.
string sArr[5];
pair<int,int> pArr[5];
vector<int> vArr[5];

Examples of STL types used in arrays:
• string
• pair<>
• array<>
• vector<>
• map<> , set<>   (arrays of them are allowed)

==============================================================
🔹 7️⃣ Typedef / Using Aliases

using ll = long long;
ll numArr[10];

Alias → still treated as a valid datatype

❌ What is NOT Allowed
•Mixed datatypes
    int arr[] = {1, 2, 3.5};

•void has no size
    void arr[10];

==============================================================
8️⃣ String Array
A string array means:
→ A way to store MULTIPLE STRINGS using an array.

In C++, string arrays can be implemented in TWO
fundamentally different ways:
🔸 1️⃣ C-STYLE STRING ARRAY
    char names[3][20];

names → array name
3     → number of strings
20    → maximum characters per string

Each string is:
• A char array
• Ends with a null character '\0'

📌 Important Observations
• You can store 3 strings
• Each string can store at most 19 characters
• 1 character is reserved for '\0'

📍 MEMORY LAYOUT (VERY IMPORTANT)
This is a 2D array of characters.
Memory is FULLY CONTIGUOUS and allocated at compile time.
names:

[ R  a  m  \0  ?  ?  ?  ... ]   ← names[0]
[ S  h  y  a  m  \0  ?  ... ]   ← names[1]
[ A  m  a  n  \0  ?  ... ]      ← names[2]

• Each row has FIXED length = 20
• Unused positions contain garbage

🔹 How to Assign Values?
 ❌ NOT allowed
names[0] = "Ram";   // ❌ illegal

Reason:
names[0] is an ARRAY, not a pointer.
Arrays cannot be assigned after declaration.

 ✅ Correct way
#include <cstring>

strcpy(names[0], "Ram");
strcpy(names[1], "Shyam");
strcpy(names[2], "Aman");

⚠️ LIMITATIONS OF C-STYLE STRING ARRAYS
• Fixed size (wastes memory or may overflow)
• Risk of buffer overflow
• Manual copying (strcpy, strlen)
• Difficult to resize or modify

✅ WHY DOES THIS STILL EXIST?
• Legacy C code
• Embedded systems
• Low-level programming
• Some competitive programming constraints


🔸 2️⃣ C++ std::string ARRAY (RECOMMENDED)
    #include <string>
    using namespace std;

    string names2[3];
• names2 is an array of 3 std::string objects
• Each element is a full-fledged object
• Each string manages its own memory dynamically

🔹 How to Use?
names2[0] = "Ram";
names2[1] = "Shyam";
names2[2] = "Aman";

✔ No strcpy
✔ No size worries

📍 MEMORY BEHAVIOR (IMPORTANT CONCEPT)
• Array of string objects → Stack / Static memory
• Actual characters       → Heap (managed internally)
• Memory grows and shrinks automatically



--------------------------------------------------------------
✅ ADVANTAGES OF std::string ARRAYS
• No fixed size
• No buffer overflow
• Easy assignment and modification
• Works with STL algorithms
• Cleaner and safer code

🔥 HEAD-TO-HEAD COMPARISON (EXAM GOLD)
Feature              | char names[3][20] | std::string names[3]
--------------------------------------------------------------
Type                 | 2D char array     | Array of objects
String length        | Fixed (20)        | Dynamic
Memory safety        | ❌ Risky          | ✅ Safe
Assignment           | strcpy()          | =
Modification         | Manual            | Easy
Preferred today      | ❌ No             | ✅ Yes

*/
