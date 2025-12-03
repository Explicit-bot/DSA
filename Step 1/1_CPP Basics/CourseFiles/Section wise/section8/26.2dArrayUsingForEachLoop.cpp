/*
why use auto instead of just int ??
When you're working with 2D arrays or containers like vectors, each row is not an int — it’s an array or a vector.
Example with a 2D array:
        int A[2][3] = {{1,2,3}, {4,5,6}};
A row here is of type: int[3]
You can’t write:
        for (int row : A)  // ❌ INVALID
But auto automatically deduces the correct type:
        for (auto& row : A)  // ✅ OK


🔍 int (&row)[3] — What does it mean?
This is C++'s way of saying:
"row is a **reference (&) to an array of 3 integers (int[3])`."

Let’s dissect it:
int: type of the elements in the array
[3]: size of the array (3 elements)
&: it's a reference (so you're not making a copy)
row: the name of the variable

✅ Why is this needed?
When you do:
    int A[2][3];
You have an array of 2 arrays — each row is of type int[3].
If you want to refer to one row without copying it, you write:
        int (&row)[3]
This is the exact type auto& deduces in a range-based for loop:

        for (int (&row)[3] : A) {
         // Access row elements
        }
🔁 Equivalent with auto:

        for (auto& row : A)  // Same as: int (&row)[3]

So instead of writing this long type, auto& does the same job safely and clearly.
*/
#include <iostream>
using namespace std;

int main() {
        int A[2][3]{};

        for (auto &row : A) {
                for (auto& elem : row) {
                        cout<<"Enter element:";
                        cin>> elem;
                }
        }


    for (auto &row : A) {
        for (auto& elem : row) {
            cout << elem << " ";
        }
        cout << "\n";
    }

    return 0;
}
/*
✅ There is absolutely no difference between auto& row and auto &row.

🔍 Why?
In C++, whitespace doesn't matter in declarations like this. These are all the same:


        auto& row;
        auto &row;
        auto & row;

All three declare row as a reference to whatever type auto deduces.

🔧 But which is preferred?
It’s a matter of style, and both are valid. Common conventions:

Style	        Used By
auto& row	    Most C++ programmers, clean and compact
auto &row	    Some prefer spacing like int *ptr

🔹 Modern C++ style guides (like Google's) prefer auto& row.


*/
