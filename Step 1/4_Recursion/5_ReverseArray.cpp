/*
***
Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force approach
vector<int> revbrute(int arr[],int n){
    vector<int> rev{};
    for(int i{n-1};i>=0;--i){
        rev.push_back(arr[i]);
    }
    return rev;
}

//Using Recursion
void revrec(int arr[],int i,int n){
    if(i>=n/2){
        return;
    }

    swap(arr[i],arr[n-i-1]);
    revrec(arr,i+1,n);
}

//Optimal approach (Two pointer)
void revOptimal(int arr[],int n){
    int p1=0;
    int p2=n-1;

    while(p2>p1){
        swap(arr[p1],arr[p2]);
        ++p1;
        --p2;
    }
}

//Using STL reverse
void revSTL(int arr[], int n) {
    reverse(arr, arr + n);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];     //You must not initialize as it is Variable length array
    cout << "Enter elements of arr:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int arr2[n];
    int arr3[n];
    for (int i = 0; i < n; i++) {
        arr2[i]=arr[i];
        arr3[i]=arr[i];
    }

    
    cout << "Reversed array(Using Brute force):\n";
    vector<int> ans = revbrute(arr, n);
    for (int x : ans) {
        cout << x << " ";
    }
    
    cout<<"\n";

    cout << "Reversed array(Using Optimal approach):\n";
    revOptimal(arr2,n);
    for (int x : arr2) {
        cout << x << " ";
    }

    cout<<"\n";

    cout << "Reversed array(Using Recursion):\n";
    revrec(arr3,0,n-1);
    for (int x : arr3) {
        cout << x << " ";
    }
    cout<<"\n";

    cout << "Reversed array(Using STL reverse):\n";
    revSTL(arr,n);
    for (int x : arr3) {
        cout << x << " ";
    }

    return 0;
}


/*
| Approach        | Time  | Space|
|----------------|-------|-------|
| Brute Force    | O(n)  | O(n)  |
| Recursion      | O(n)  | O(n)  |
| Two Pointer    | O(n)  | O(1)  |
| STL reverse()  | O(n)  | O(1)  |


You must not initialize as it is Variable length array"
usually means something like this is NOT allowed:
    int n = 5;
    int arr[n] = {1,2,3,4,5}; // ❌
*/
