//Program to Multiply Matrices
#include <iostream>
using namespace std;

int main(){
    int a[100][100]{}, b[100][100]{}, mult[100][100]{}, r1{}, c1{}, r2{}, c2{}, i{};
    int j{}, k{};

    // Keep asking until valid dimensions are entered
    while (true) {
        cout << "Enter rows and columns for first matrix (r1 c1): ";
        cin >> r1 >> c1;
        cout << "Enter rows and columns for second matrix (r2 c2): ";
        cin >> r2 >> c2;

        if (c1 == r2) break; // Valid dimensions

        cout << "Matrix multiplication not possible (c1 != r2). Please try again.\n\n";
    }

 // Storing elements of first matrix.
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i){
        for(j = 0; j < c1; ++j){
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
         }
    }

 // Storing elements of second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; ++i){
        for(j = 0; j < c2; ++j){
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }
    }   


 // Multiplying matrix a and b and storing in array mult.
    for(int i{};i<r1;++i){
        for(int j{};j<c2;++j){
            mult[i][j]=0;
            for(int k{};k<c1;++k){
                mult[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    
 // Displaying the multiplication of two matrix.
    cout<<"Result matrix:\n";
    for(int i{};i<r1;++i){
        for(int j{};j<c2;++j){
            cout<<mult[i][j]<<"\t";
        }
        cout<<endl;
    }
   
 return 0;
}

/*
The error you're seeing is caused by using uniform initialization ({}) in a for loop like this:

        for(i{}; i < r1; ++i) // ❌ INVALID in C++
This syntax is only allowed when you declare the variable inside the loop, like:

        for(int i{}; i < r1; ++i) // ✅ VALID: declaring and initializing
✅ Fix
Since you're using i, j, and k already declared earlier:

        int i{}, j{}, k{};
Then in the loop, you must not reinitialize them using {}, just use assignment (=):

        for(i = 0; i < r1; ++i) {
            for(j = 0; j < c2; ++j) {
                mult[i][j] = 0;
                for(k = 0; k < c1; ++k) {
                    mult[i][j] += a[i][k] * b[k][j];
                }
            }
        }

🔁 Summary
Case	                        Syntax	Valid?
Declare and initialize	        for(int i{}; i < n; ++i)	✅
Already declared outside	    for(i = 0; i < n; ++i)	✅
Already declared, but use {}	for(i{}; i < n; ++i)	❌ ❌
*/
