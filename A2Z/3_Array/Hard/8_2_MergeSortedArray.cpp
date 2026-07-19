//Two fixed size array 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
==========================================================
MERGE TWO SORTED ARRAYS WITHOUT EXTRA SPACE
==========================================================

Problem:
You are given two sorted arrays:

arr1 -> size n
arr2 -> size m

Merge them such that:
- first n smallest elements remain in arr1
- remaining m largest elements remain in arr2

Constraints:
- No extra array allowed
- Arrays have fixed sizes

Example:
arr1 = [1,4,8,10]
arr2 = [2,3,9]

Output:
arr1 = [1,2,3,4]
arr2 = [8,9,10]

==========================================================
INTERVIEW PROGRESSION
==========================================================

1. Brute Force (Extra Array)
2. Better Approach (Insertion Style)
3. Optimal Approach 1 (Swap + Sort)
4. Optimal Approach 2 (Gap Method)

==========================================================
*/


/*
==========================================================
1. BRUTE FORCE (USING EXTRA ARRAY)
==========================================================

Idea:
- Merge both arrays into temp array
- Copy back

Time Complexity:
O(n+m)

Space Complexity:
O(n+m)
*/

void MergeArraysBrute(vector<int>& arr1, vector<int>& arr2){

    int n = arr1.size();
    int m = arr2.size();

    vector<int> temp;

    int i = 0;
    int j = 0;

    while(i < n && j < m){

        if(arr1[i] <= arr2[j]){

            temp.push_back(arr1[i]);
            ++i;
        }
        else{

            temp.push_back(arr2[j]);
            ++j;
        }
    }

    while(i < n){

        temp.push_back(arr1[i]);
        ++i;
    }

    while(j < m){

        temp.push_back(arr2[j]);
        ++j;
    }

    for(int k = 0; k < n; ++k){
        arr1[k] = temp[k];
    }

    for(int k = 0; k < m; ++k){
        arr2[k] = temp[k+n];
    }
}


/*
==========================================================
2. BETTER APPROACH (INSERTION STYLE)
==========================================================

Idea:
- Traverse arr1
- If arr1[i] > arr2[0]:
    swap them
    place swapped element in correct position in arr2

Time Complexity:
O(n*m)

Space Complexity:
O(1)
*/

void MergeArraysBetter(vector<int>& arr1, vector<int>& arr2){

    int n = arr1.size();
    int m = arr2.size();

    for(int i = 0; i < n; ++i){

        if(arr1[i] > arr2[0]){

            swap(arr1[i], arr2[0]);

            int first = arr2[0];

            int k;

            for(k = 1; k < m && arr2[k] < first; ++k){

                arr2[k-1] = arr2[k];
            }

            arr2[k-1] = first;
        }
    }
}


/*
==========================================================
3. OPTIMAL APPROACH 1 (SWAP + SORT)
==========================================================

Idea:
- Compare:
    largest element of arr1
    smallest element of arr2

- Swap if needed
- Finally sort both arrays

Time Complexity:
O(n log n + m log m)

Space Complexity:
O(1)
*/

void MergeArraysOptimal1(vector<int>& arr1, vector<int>& arr2){

    int n = arr1.size();
    int m = arr2.size();

    int left = n - 1;
    int right = 0;

    while(left >= 0 && right < m){

        if(arr1[left] > arr2[right]){

            swap(arr1[left], arr2[right]);

            --left;
            ++right;
        }
        else{
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}


/*
==========================================================
4. OPTIMAL APPROACH 2 (GAP METHOD)
==========================================================

MOST IMPORTANT INTERVIEW SOLUTION

Inspired by Shell Sort.

Idea:
Treat both arrays as one virtual combined array.

Compare elements at distance = gap.

Reduce gap gradually.

Time Complexity:
O((n+m) log(n+m))

Space Complexity:
O(1)
*/

void swapIfGreater(vector<int>& a,
                   vector<int>& b,
                   int i,
                   int j){

    if(a[i] > b[j]){

        swap(a[i], b[j]);
    }
}

void MergeArraysOptimal2(vector<int>& arr1, vector<int>& arr2){

    int n = arr1.size();
    int m = arr2.size();

    int len = n + m;

    int gap = (len / 2) + (len % 2);

    while(gap > 0){

        int left = 0;
        int right = left + gap;

        while(right < len){

            // both pointers in arr1
            if(left < n && right < n){

                swapIfGreater(arr1, arr1, left, right);
            }

            // left in arr1, right in arr2
            else if(left < n && right >= n){

                swapIfGreater(arr1, arr2, left, right - n);
            }

            // both pointers in arr2
            else{

                swapIfGreater(arr2,
                              arr2,
                              left - n,
                              right - n);
            }

            ++left;
            ++right;
        }

        if(gap == 1){
            break;
        }

        gap = (gap / 2) + (gap % 2);
    }
}


/*
==========================================================
UTILITY FUNCTION
==========================================================
*/

void PrintArrays(vector<int>& arr1, vector<int>& arr2){

    cout << "arr1: ";

    for(int x : arr1){
        cout << x << " ";
    }

    cout << endl;

    cout << "arr2: ";

    for(int x : arr2){
        cout << x << " ";
    }

    cout << endl;
}


/*
==========================================================
MAIN FUNCTION
==========================================================
*/

int main(){

    int n, m;

    cout << "Enter size of arr1: ";
    cin >> n;

    cout << "Enter size of arr2: ";
    cin >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    cout << "Enter elements of arr1:\n";

    for(int i = 0; i < n; ++i){
        cin >> arr1[i];
    }

    cout << "Enter elements of arr2:\n";

    for(int i = 0; i < m; ++i){
        cin >> arr2[i];
    }

    cout << "\nOriginal Arrays:\n";

    PrintArrays(arr1, arr2);

    /*
    ======================================================
    CHOOSE ANY ONE APPROACH
    ======================================================
    */

    // MergeArraysBrute(arr1, arr2);

    // MergeArraysBetter(arr1, arr2);

    // MergeArraysOptimal1(arr1, arr2);

    MergeArraysOptimal2(arr1, arr2);

    cout << "\nMerged Arrays:\n";

    PrintArrays(arr1, arr2);

    return 0;
}
