/*
why use auto instead of just int ??
When you're working with 2D arrays or containers like vectors, each row is not an int — it’s an array or a vector.
Example with a 2D array:
        int A[2][3] = {{1,2,3}, {4,5,6}};
        
A row here is of type: int[3]
You can’t write:
        for (int row : A)       //INVALID        
You write:
        for (int (&row)[3] : A)         //VALID

This is the exact type auto& deduces in a range-based for loop:
        for (auto& row : A)  // Same as: int (&row)[3]

So instead of writing this long type, auto& does the same job safely and clearly.
*/
#include <iostream>
using namespace std;

int main() {
        int A[2][3]{};

        for (auto &row : A) {
                for (auto& elem : row) {        //auto &row and auto& row are same thing
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
