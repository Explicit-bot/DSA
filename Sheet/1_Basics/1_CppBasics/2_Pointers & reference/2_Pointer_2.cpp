/*
------------------------------------------------------------
🧠 What is Pointer Arithmetic?
------------------------------------------------------------
Pointer arithmetic means performing operations like:
    +   -   ++   -- 
on pointers to move across memory locations, mainly arrays.

------------------------------------------------------------
🧱 Array & Pointer Relationship
------------------------------------------------------------
Example:

    int A[5] = {2, 4, 6, 8, 10};
    int* p = A;

Why does this work?

➡️ Array name (A) decays into pointer to first element
So:
    p = A  ≡  p = &A[0]

Memory View:

Index:   0   1   2   3   4
A:       2   4   6   8   10
Address: 200 204 208 212 216   (assuming int = 4 bytes)

p → 200 (address of A[0])

------------------------------------------------------------
📌 Core Rule of Pointer Arithmetic
------------------------------------------------------------
p + n  →  p + n × sizeof(datatype)

For int*:
    p + 1 moves 4 bytes
    p + 2 moves 8 bytes

NOT 1 byte ❌

------------------------------------------------------------
🔢 Common Pointer Operations
------------------------------------------------------------

p++      → move to next element
p--      → move to previous element
p = p+2  → move 2 elements forward
p = p-2  → move 2 elements backward

------------------------------------------------------------
🔍 Accessing Elements Using Pointer
------------------------------------------------------------

    *p         → A[0]
    *(p + 1)   → A[1]
    *(p + 2)   → A[2]
    p[i]       → same as *(p + i)

Example:

    cout << *p;       // 2
    cout << *(p+1);   // 4
    cout << p[2];     // 6

------------------------------------------------------------
📈 Memory Visualization
------------------------------------------------------------

Index   Address   A[i]   p+i      *(p+i)
0       0x1000    2      p        2
1       0x1004    4      p+1      4
2       0x1008    6      p+2      6
3       0x100C    8      p+3      8
4       0x1010    10     p+4      10

(Addresses are illustrative)

------------------------------------------------------------
🔄 Loop Using Pointer Arithmetic
------------------------------------------------------------

    for(int i = 0; i < 5; ++i)
        cout << *(p + i) << " ";

Same as:
    cout << A[i];

------------------------------------------------------------
🧠 Incrementing the Pointer Itself
------------------------------------------------------------
    p++;        // now points to A[1]
    cout << *p; // prints 4

⚠️ Once moved, original address is lost unless stored.

------------------------------------------------------------
➖ Pointer Subtraction
------------------------------------------------------------
Valid ONLY when pointers point to SAME ARRAY.

    int* p = &A[4];
    int* q = &A[1];

    p - q = 3
    q - p = -3

✔ Result is number of ELEMENTS (not bytes)
✔ Type returned: ptrdiff_t

❌ Undefined Behavior if pointers are from different arrays

------------------------------------------------------------
📌 Real Use Case: Distance Between Elements
------------------------------------------------------------

    int A[] = {5, 10, 15, 20};
    int* start = A;
    int* mid = &A[2];

    int dist = mid - start;  // 2

------------------------------------------------------------
🖨️ Printing a Pointer
------------------------------------------------------------
    cout << p;

Prints MEMORY ADDRESS (not value)

To print value:
    cout << *p;

------------------------------------------------------------
⚠️ Pre vs Post Increment with Pointers
------------------------------------------------------------
    cout << *p++;   // use value, THEN move pointer
    cout << *++p;   // move pointer, THEN use value

Example:
    int A[] = {2,4,6};
    int* p = A;

    *p++  → prints 2, p → A[1]
    *++p  → p → A[2], prints 6
============================================================
🔹 PROGRAM: Pointer Arithmetic Demonstration
==========================================================
*/

#include <iostream>
using namespace std;

int main() {
    int A[5] = {2, 4, 6, 8, 10};

    int* p = A;
    int* q = &A[4];

    cout << *p << endl;     // 2

    p++;
    cout << *p << endl;     // 4

    p--;
    cout << *p << endl;     // 2

    cout << p << endl;      // address of A[0]
    cout << p + 2 << endl;  // address of A[2]

    cout << *p << endl;     // 2
    cout << *(p + 2) << endl; // 6

    cout << q - p << endl;  // 4
    cout << p - q << endl;  // -4

    return 0;
}
