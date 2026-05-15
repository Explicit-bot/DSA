/*
                        ====================================================
                                                Pointer
                        ====================================================
• A pointer is a variable that stores the memory address of another variable.
e.g
        int x = 10;
        int *p = &x;  // 'p' stores the address of 'x'
        
        cout << &a << "\n";     // prints address of a
        cout << ptr << "\n";    // same as &a
        cout << *ptr << "\n";   // value at that address (10)
- x is a normal integer.
- &x means “address of x”.
- p is a pointer to an integer (int*).
- *p accesses the value at that address (i.e., dereferencing the  pointer).

• Declaration Syntax:-
        <data_type> *pointer_name;
E.g.
        int* p;       // pointer to int
        float* fptr;  // pointer to float
        char* cptr;   // pointer to char
• Size of every pointer is 8 bytes.

                        ====================================================
                                Heap Memory Allocation in C++
                        ====================================================
✅ Syntax:
1. For Single Variable
    int *p = new int;      // allocate memory for one int
    *p = 10;               // assign value
    delete p;              // deallocate memory

2. For Array
    int *arr = new int[5];     // allocate array of 5 integers
    arr[0] = 1;
    arr[1] = 2;
    // ...
    delete[] arr;              // deallocate array memory
❗ Always use delete[] when using new[].

🔁 Smart Pointers 
In modern C++, it's better to use smart pointers like std::unique_ptr or std::shared_ptr to automatically manage heap memory.
Example:
    #include <memory>
    std::unique_ptr<int> p = std::make_unique<int>(10);

🔍 What is a Memory Leak?
A memory leak happens when:
 - You allocate memory on the heap using new 
 - But forget to deallocate it using delete
This causes unused memory to remain occupied — your program loses access to it, and the system doesn’t reclaim it until the program exits.
If you set p = nullptr before calling delete p,
then the memory is leaked permanently — because the original address is lost, and you can no longer delete it until the program exits

                ====================================================
                                Dangling Pointer
                ====================================================
If a pointer is having an address of a memory location which is
already deallocated.
example:
    int *p=new int[5];
    delete []p;
Now p is a Dangling pointer.

✅ How to prevent dangling pointers?
 - Set pointer to nullptr after delete:
    delete p;
    p = nullptr;
 - Avoid returning addresses of local variables.
 - Use smart pointers (std::unique_ptr, std::shared_ptr) in modern C++ — they handle memory safely and automatically.
 - Avoid raw pointers when possible. Prefer references or smart pointers.

                ====================================================
                                    NULL vs nullptr
                ====================================================
NULL:
•it is a constant whose value is 0.
•NULL means, pointer is not pointing on any valid location.
•In place of NULL, 0 can be used.
•Using 0 in place of NULL may create confusion for programmer.

nullptr 
•It is a keyword in C++.
•nullptr means, pointer is not pointing on any valid location.(same
as NULL)
•Nullptr doesn’t mean 0.
•0 cannot be used in its place. 

                    ====================================================
                                    Zero Initialize
                    ====================================================
✅ How to zero-initialize Array pointer:
    int* p = new int[5]();  // Note the parentheses
This will set all elements to 0.

Or use C++11 list initialization:
    int* p = new int[5]{0};  // Initializes all elements to 0

You can also partially initialize:
    int* p = new int[5]{2, 3};  // p[0]=2, p[1]=3, rest = 0

• You can use {} only at the point of allocation.
  But,you cannot directly initialize a dynamic array (int* p = new int[5];) 
  using initializer list syntax like p = {1, 2, 3, 4, 5}; 
  — that’s invalid in C++ and will give a compiler error.

❌ Invalid:
    int* p = new int[5];
    p = {1, 2};  // ❌ Error: invalid initializer coz it is not address but pointer takes address.

✅ Correct way: Initialize manually
    int* p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

*/

# include<iostream>
using namespace std;
    
int main(){
    int *p=new int[5];
    p[0]=2;
    p[1]=3;  //p[2],p[3],p[4] will take garbage values
            
    cout<<p[1];

    delete []p; //should be written like that not p[]

    p=nullptr;
}

