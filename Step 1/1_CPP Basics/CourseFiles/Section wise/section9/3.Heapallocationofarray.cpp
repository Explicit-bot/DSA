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

/*
No, p[2], p[3], and p[4] will not automatically take zero as values. Instead, they will contain garbage values unless explicitly initialized.

Explanation:

    int* p = new int[5];
    p[0] = 2;
    p[1] = 3;
Only p[0] and p[1] are assigned.

The remaining elements (p[2], p[3], p[4]) will hold indeterminate (garbage) values.

This is because new int[5] does not zero-initialize by default.

✅ How to zero-initialize:

    int* p = new int[5]();  // Note the parentheses

This will set all elements to 0.

✅ Or use C++11 list initialization:

    int* p = new int[5]{0};  // Initializes all elements to 0

You can also partially initialize:

    int* p = new int[5]{2, 3};  // p[0]=2, p[1]=3, rest = 0

🔥 Tip for Competitive Programming (CP):
Always initialize arrays if you rely on default values. Uninitialized variables can lead to unpredictable bugs and wrong answers.

No, you cannot directly initialize a dynamic array (int* p = new int[5];) using initializer list syntax like p = {1, 2}; — that’s invalid in C++ and will give a compiler error.

❌ Invalid:

    int* p = new int[5];
    p = {1, 2};  // ❌ Error: invalid initializer

✅ Correct way: Initialize manually

    int* p = new int[5];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

✅ Alternative (C++11 and above): Use std::vector
If you want easy initialization, prefer std::vector:

    #include <vector>
    std::vector<int> p = {1, 2, 3, 4, 5};
You get:
 - Bounds safety
 - Auto memory management
 - Easy initialization



            
In C++, you must use delete[] p;, not delete p[];.

✅ Correct:

    int* p = new int[5];  // allocate array of 5 ints
    delete[] p;           // correct way to delete array

❌ Incorrect:

    delete p[];   // ❌ syntax error — invalid C++ syntax

You’ll get a compiler error with delete p[]; because it's not a valid statement in C++.

⚠️ Why delete[]?
 - When you use new[], it allocates an array on the heap.
 - So, you must use delete[] to properly deallocate all elements of that array.
 - If you use just delete p;, only the first element is destroyed causing memory leaks.
*/
