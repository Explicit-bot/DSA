/*
🔹 What is a Pointer?
A pointer is a variable that stores the memory address of another variable.

        int x = 10;
        int *p = &x;  // 'p' stores the address of 'x'

- x is a normal integer.
 - &x means “address of x”.
 - p is a pointer to an integer (int*).
 - *p accesses the value at that address (i.e., dereferencing the  pointer).

🔹 Declaration Syntax

        <data_type> *pointer_name;

Examples:

        int* p;       // pointer to int
        float* fptr;  // pointer to float
        char* cptr;   // pointer to char

🔹 Why Use Pointers?
 - Dynamic memory allocation (heap memory).
 - Efficient parameter passing to functions (especially large objects).
 - Building data structures (linked lists, trees, graphs).
 - Direct hardware access or system-level programming.
 - Low-level operations and performance optimization.

🔹 How Pointers Work (Internally)
Every variable is stored at a memory address. A pointer holds that address.
        int a = 5;
        int* ptr = &a;

        std::cout << &a << "\n";   // prints address of a
        std::cout << ptr << "\n";  // same as &a
        std::cout << *ptr << "\n"; // value at that address (5)

🔹 Memory Diagram
Assume int a = 5; stored at address 0x100

Variable | Value | Address
---------|-------|---------
a        |   5   | 0x100
p        | 0x100 | 0x200

*p → go to 0x100 → value is 5
p → value of pointer → 0x100

🔹 *p — Dereferencing
This means you are accessing the value stored at the address that p holds.

Continuing the same example:

        cout << *p;  // This will print 10, which is the value at the address stored in p

Here:
*p means "go to the address stored in p, and fetch the value from there"
        int x = 10;
        int* p = &x;

        std::cout << *p;  // prints 10
        *p = 20;          // modifies x to 20
    
What is the Size of a Pointer?
A Pointer are declared using data type. But its size is not dependent on its data type.
Purpose of data type is for pointer arithmetic. Not for size.
In Present day compilers every pointer takes 8 bytes.

int *p1;
float *p2;
double *p3;
char *p4;
struct Test *p5;        // pointer to structure.   
Rectangle *p6;          // pointer to an object. 

All pointers from p1 to p6, they take 8 bytes.

*/

# include<iostream>
using namespace std;

int main()
{
	int a=10;
	int *p=&a;
	cout<<a<<endl;  //value stored in a
	cout<<&a<<endl; //address of a
	cout<<p<<endl;  //address stored in pointer(&a)
	cout<<&p<<endl; //address of pointer
	cout<<*p<<endl; //Pointer dereferencing (value stored in a)
	return 0;
}
/*
✅ You should write * with the variable name, not with the type.
So prefer:

        int *p;  // preferred style
Rather than:

        int* p;  // not wrong, but misleading in certain cases

🔍 Why? Here's the deeper reason:
The * binds to the variable, not the type.

        int* p1, p2;
        
You might expect both p1 and p2 to be pointers, but only p1 is a pointer!

This is equivalent to:

int *p1;
int p2;  // not a pointer!

✅ Better Style for Clarity:

        int *p1, *p2;  // both are pointers
That makes it clear that * applies to each variable individually.

💡 Best Practice
When declaring multiple pointers in one line, always write * with each variable:
        int *a, *b, *c;

Or even better: declare them separately for clarity:
        int* a;
        int* b;
        int* c;
*/
