/*
Given an integer N, print the following pattern.
for example N=5
*       * 
  *   *   
    *     
  *   *   
*       * 
*/

#include <iostream>
using namespace std;

void pattern0(int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1)  
                cout << "* "; 
            else
                cout << "  ";
        }
        cout << "\n";
    }
}
int main() {
    int n;
    cout << "Enter size of square grid: ";
    cin >> n;

    pattern0(n);
}
