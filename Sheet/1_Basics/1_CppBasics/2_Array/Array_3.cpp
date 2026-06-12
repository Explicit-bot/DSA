/*
📦 What is a Multidimensional Array?
A multidimensional array is an array of arrays.
Most common: 2D array (like a matrix)

Syntax:

        data_type array_name[rows][cols];

✅ 1. Declaration & Initialization
🔹 Static Declaration
        int A[3][4]; // 3 rows, 4 columns

🔹 Initialization
        int A[2][3] = { {1, 2, 3}, {4, 5, 6} };
OR
        int A[2][3] = { 1, 2, 3, 4, 5, 6 };  // row-major order

✅ 2. Accessing Elements
        A[0][1] = 5;        // Access element in 1st row, 2nd column
        std::cout << A[1][2]; // 2nd row, 3rd column

✅ 3. Input & Output
🔹 Taking Input:
        int A[2][3];
        for (int i = 0; i < 2; ++i){
            for (int j = 0; j < 3; ++j){
                std::cin >> A[i][j];
            }   
        }

🔹 Printing:
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j){
                std::cout << A[i][j] << " ";
            }
            std::cout << std::endl;
        }

✅ 4. Memory Layout
 - Stored in row-major order.
 - Contiguous memory.
 - Access time: O(1) (constant time).

✅ 5. Dynamic 2D Arrays

        int** A = new int*[n];
        for (int i = 0; i < n; ++i)
            A[i] = new int[m];

Don't forget to free memory:

        for (int i = 0; i < n; ++i)
            delete[] A[i];
        delete[] A;
*/
#include <iostream>
using namespace std;

int main(){
    int A[5][5]{};
    for(int i{};i<5;++i){
        for(int j{};j<5;++j){
            cout<<"Enter element at ("<<i<<","<<j<<"): ";
            cin>>A[i][j];
        }
    }
    
    for(int i{1};i<5;++i){
        for(int j{1};j<5;++j){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
}

/*
        int m, n;
        std::cin >> m >> n;
        int A[m][n]{};
And VS Code (or the compiler) gives a warning like:
❗ "Variable 'A' may not be initialized" or "error: size of array 'A' is not constant"

❌ Why This Happens
In C++, standard (non-extension)  arrays must have compile-time constant sizes.
That means:

        int A[10][10];   // ✅ OK
        int A[m][n];     // ❌ Error in standard C++
📌 m and n are not constants — their values are read at runtime via cin.
*/
