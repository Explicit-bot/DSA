/*
🧩 What are lvalues and rvalues?
✅ lvalue (Left Value)
Definition: An object that has a persistent memory address.
You can take its address with &.
Can appear on the left or right side of an assignment.
    int x = 10;   // x is an lvalue
    x = 20;       // lvalue (x) on left, rvalue (20) on right
✅ You can do: int* p = &x;

✅ rvalue (Right Value)
Definition: A temporary value that does not have a memory address.
Cannot be assigned to.
Can only appear on the right side of an assignment.

    int x = 10;
    int y = x + 5;  // (x + 5) is an rvalue
🚫 You cannot do:
    int* p = &(x + 5);  // ❌ Error: rvalue has no address
💡 Examples
Expression	    Type	        Why
x	            lvalue	        Refers to a named variable
x + 5	        rvalue	        Temporary result
10	            rvalue	        Literal constant
++x	            lvalue	        Refers to x after increment
x++	            rvalue	        Returns old value temporarily
"hello"	        rvalue	        String literal, temporary
std::move(x)	rvalue	        Converts lvalue to rvalue

🔄 How lvalue and rvalue relate to references
✅ lvalue reference:
    int x = 5;
    int& ref = x;  // okay, x is lvalue
🚫 rvalue reference to lvalue:
    int x = 5;
    // int&& r = x;  // ❌ Error: x is lvalue
✅ rvalue reference:
    int&& r = 5;  // okay: 5 is rvalue
🧠 Why does this matter?
Move semantics: C++11 introduced rvalue references (&&) to allow efficient moves (e.g., avoid deep copies).

Function overloading:
    void foo(int& x);   // lvalue version
    void foo(int&& x);  // rvalue version
Depending on what you pass, the right function gets called.

✅ Summary
Term   |Can appear on left of =?|Can take address?|Has name/memory?
lvalue |Yes	                    |Yes	          |Yes
rvalue |No	                    |No	              |No (temporary)
       |                        |                 |

*/
