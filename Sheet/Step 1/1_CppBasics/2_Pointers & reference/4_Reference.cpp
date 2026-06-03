/*
✅ 1. What is a Reference?
A reference in C++ is simply another name (alias) for an existing variable.
• It must be initialised when declared
• It cannot be modified to refer other variable
it doesn't occupy any memory normally but:
📌 Important Examples:
🧪 Example 1: Variable with Reference
    int a = 5;
    int& ref = a;
ref is just another name for a.
No additional memory is guaranteed to be allocated.

🧪 Example 2: Reference in a Struct
    struct Example {
        int& ref;
    };

    int main() {
        int x = 10;
        Example obj{x};
    }
Here, ref must be implemented as a pointer internally.
So, it will occupy space (usually 8 bytes on 64-bit systems).


int a = 10;
int& ref = a;  // ref is a reference to a
ref = 20;      // a becomes 20
Both ref and a refer to the same memory location.

Changes to the reference affect the original variable.

✅ 2. Syntax

    datatype &ref_name = original_variable;
The & is not "address-of" here. It's part of the type declaration.

✅ 3. Key Properties of References
Property	                        
 - Description
Must be initialized when declared	 
 - Can't create an uninitialized reference

Cannot be reassigned to another var	
 - Unlike pointers, you can't change what it refers to

No null references	 
 - A reference must always refer to something

Acts as an alias	 
 - It does not occupy separate memory

✅ 4. Why Use References?
 - To avoid copying large objects (efficiency)
 - To modify arguments in functions
 - To implement operator overloading
 - To use range-based for loops
 - For returning multiple values via output parameters

✅ 5. Reference vs Pointer
Reference	            Pointer
Cannot be null	        Can be null
Must be initialized	    Can be assigned later
No arithmetic allowed	Pointer arithmetic allowed
Auto-dereferencing	    Needs * to dereference

✅ 6. Types of References
🔹 A. L-value Reference (T&)
Binds to variables with a name (L-values)

    int x = 5;
    int& ref = x;  // ✅ valid

🔹 B. R-value Reference (T&&) — C++11+
Binds to temporary unnamed values (R-values)
Used in move semantics and optimization
        int&& ref = 10 + 5;  // ✅ valid

🔹 C. Const References
Can bind to both L-values and R-values
Used when you don't want to modify the referred object
        const int& ref1 = 100;  // OK, binds to temporary
        const int& ref2 = x;    // OK

✅ 7. References in Functions
🔸 Pass by Reference
    void update(int& num) {
        num = 50;
    }

    int main() {
        int x = 10;
        update(x);  // x becomes 50
    }

🔸 Return by Reference
    int& getRef(int& a) {
        return a;
    }

    int main() {
       int x = 10;
       getRef(x) = 100;  // x becomes 100
    }

✅ 8. Reference in Range-Based For Loop

    int arr[] = {1, 2, 3};

    for (int& x : arr) {
        x += 1;
    }
x modifies the actual array elements.
If you use int x, it would copy the values instead.

*/

#include <iostream>
using namespace std;

int main(){
    int x=10;
    int &y=x;

    cout<<x<<endl;
    ++y;
    cout<<"value of x and y are:"<<x<<","<<y<<endl;
    ++x;
    cout<<"value of x and y are:"<<x<<","<<y<<endl;

    cout<<"Address of x:"<<&x<<"\n";
    cout<<"Address of y:"<<&y<<"\n";
}

/*
🔹 Statement:
int*& z = y;
This line means:
✅ z is a reference to a pointer to an int.

💡 Breakdown:
Component	  Meaning
int *	      Pointer to an int
&z	          z is a reference (it must refer to something)
int*& z	      z is a reference to a pointer to int
= y;	      y must be a variable of type int* (a pointer to an int)

So z becomes an alias for the pointer y, not the int that y points to.

🧠 Analogy:
Let’s look at this example:

int x = 42;
int* y = &x;     // y is a pointer to x
int*& z = y;     // z is a reference to the pointer y
Now:

z is another name for y (not for x)

So changing z changes y, and since y points to x, *z or *y gives x

🔍 Usage:
int a = 5;
int b = 10;

int* y = &a;
int*& z = y;   // z is a reference to y

z = &b;        // this actually modifies y, since z is a reference to y

std::cout << *y << "\n";  // prints 10, not 5
So even though we wrote z = &b, it changed y — because z is just a reference to y.
*/
