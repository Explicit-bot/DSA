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
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                std::cin >> A[i][j];

🔹 Printing:

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j)
                std::cout << A[i][j] << " ";
            std::cout << std::endl;
        }
✅ 4. Memory Layout
 - Stored in row-major order.
 - Contiguous memory.
 - Access time: O(1) (constant time).

✅ 5. Use Cases in CP
 - Matrices (Math problems)
 - Grids (pathfinding, DP)
 - Game boards (like chess, sudoku)
 - Graph adjacency matrix
 - Image processing (pixel manipulation)

✅ 6. Best Practices
✔️ Use fixed-size arrays only if bounds are small (≤ 1e3).
✔️ For large sizes, use vector<vector<int>> (dynamic memory).
✔️ Avoid hardcoding dimensions — use variables.

✅ 7. Programs
🔹 Sum of all elements:

        int sum = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                sum += A[i][j];

🔹 Transpose of Matrix:

        int T[m][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                T[j][i] = A[i][j];

🔹 Matrix Multiplication:
Requires A[rows][cols1], B[cols1][cols2], result C[rows][cols2]

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols2; ++j)
                for (int k = 0; k < cols1; ++k)
                    C[i][j] += A[i][k] * B[k][j];

✅ 8. Dynamic 2D Arrays

        int** A = new int*[n];
        for (int i = 0; i < n; ++i)
            A[i] = new int[m];

    Don't forget to free memory:

        for (int i = 0; i < n; ++i)
            delete[] A[i];
        delete[] A;

✅ 9. STL Alternative: vector<vector<int>>
Easier and safer:

        vector<vector<int>> A(n, vector<int>(m));

📌 Summary
Concept	                    Use/Meaning
int A[2][3]	                2D Array (2 rows, 3 cols)
Row-major storage	        Memory layout: row-wise
vector<vector<int>>	        Safer, dynamic size
Common use	                Matrices, grids, DP
Time complexity	            Access: O(1), Input/Print: O(n²)
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
No. of rows and columns
int m{};
int n{};
cout<<"Enter no. of Rows:";
cin>>m;
cout<<"Enter no. of Columns:";
cin>>n;

int A[m][n]{};
*/
/*
🔎 Problem
You wrote:
        int m, n;
        std::cin >> m >> n;
        int A[m][n]{};
And VS Code (or the compiler) gives a warning like:

❗ "Variable 'A' may not be initialized" or "error: size of array 'A' is not constant"

❌ Why This Happens
In C++, standard (non-extension) multidimensional arrays must have compile-time constant sizes.

That means:

        int A[10][10];   // ✅ OK
        int A[m][n];     // ❌ Error in standard C++
📌 m and n are not constants — their values are read at runtime via cin.
*/
