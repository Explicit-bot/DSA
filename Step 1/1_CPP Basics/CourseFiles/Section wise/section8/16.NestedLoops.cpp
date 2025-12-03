/*
🔁 Nested for Loops in C++
A nested for loop is a for loop written inside another for loop. It is commonly used for:
 - Patterns
 - Matrices (2D arrays)
 - Combinations of elements
*/
#include <iostream>
using namespace std;

int main() {
    int outer_limit, inner_limit;

    // Take number of rows and columns as input
    cout << "Enter number of rows (outer_limit): ";
    cin >> outer_limit;

    cout << "Enter number of columns (inner_limit): ";
    cin >> inner_limit;

    // Nested for loops 
    //outer loop acts as row inner one as column
    for (int i = 0; i < outer_limit; ++i) {
        for (int j = 0; j < inner_limit; ++j) {
            cout <<"("<< i<<","<<j<<")";
        }
        cout << endl;  // Move to next line after printing a row
    }

    return 0;
}

