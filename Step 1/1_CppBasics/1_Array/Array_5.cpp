/*
| Function      | Time       |
|---------------| ---------- |
| swap          | O(1)       |
| sort          | O(n log n) |
| reverse       | O(n)       |
| merge         | O(n+m)     |
| find          | O(n)       |
| count         | O(n)       |
| binary_search | O(log n)   |
| lower_bound   | O(log n)   |
| upper_bound   | O(log n)   |
| fill          | O(n)       |
| accumulate    | O(n)       |
| rotate        | O(n)       |
| min_element() | O(n)       |
| max_element() | O(n)       |

Their uses:-
1️⃣ swap() - Swap two values
    int a = 10, b = 20;
    swap(a, b);
    // a = 20, b = 10

2️⃣ sort() - Sort array / vector
Ascending:
    Array:
        int arr[] = {5, 3, 1, 4};
        sort(arr, arr + 4);     //1,3,4,5

    Vector:
        vector<int> v = {5, 1, 3};
        sort(v.begin(), v.end());   //1,3,5

Descending:
    Array:
        sort(arr, arr + n, greater<int>());
    Vector:
        sort(v.begin(), v.end(), greater<int>());

3️⃣ reverse() — Reverse elements of array/vector.
Array:
    reverse(arr, arr + n);
Vector:
    reverse(v.begin(), v.end());

4️⃣ merge() — Merge two sorted arrays
Internally, merge() does this:
compare a[i] and b[j]
take smaller one
move pointer
So it can merge unsorted arrays too but the order will be undefined.

    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6};
    int c[6];
    merge(a, a + 3, b, b + 3, c);

Result:
    c = 1 2 3 4 5 6

5️⃣ find() — Find element in unsorted array
    auto it = find(v.begin(), v.end(), 5);
    if(it != v.end()){
        cout << "Found";
    }

6️⃣ count() — Count frequency
    vector<int> v = {1, 2, 2, 2, 3};
    int cnt = count(v.begin(), v.end(), 2);
    // cnt = 3

7️⃣ binary_search() — Check if element exists
⚠️ Array must be sorted
    bool ok = binary_search(arr, arr + n, key);
•Returns true or false.

8️⃣ lower_bound() — First index where element ≥ key
•REQUIRE a sorted array / vector.
Array:
    int arr[] = {1, 2, 4, 4, 4, 7};
    int n = 6;
    int key = 4;

    int idx = lower_bound(arr, arr + n, key) - arr; 
    cout << idx;        //2

Vector:
    vector<int> v = {1, 2, 2, 2, 3};

    auto it = lower_bound(v.begin(), v.end(), 2);
    cout << it - v.begin();  // index=1

9️⃣ upper_bound() — First index where element > key
•REQUIRE a sorted array / vector.
Array:
    int arr[] = {1, 2, 2, 2, 3};
    int n = 5;

    auto it = upper_bound(arr, arr + n, 2);
    cout << it - arr;   // 4

Vector:
    vector<int> v = {1, 2, 2, 2, 3};

    auto it = upper_bound(v.begin(), v.end(), 2);
    cout << it - v.begin();     //4

🔥 Frequency of an Element:
int freq = upper_bound(v.begin(), v.end(), 2) - lower_bound(v.begin(), v.end(), 2);

📦 Example 1 (Most common)
    vector<int> v = {1, 2, 2, 2, 3, 4};
    int x = 2;
    lower_bound(2) → index 1
    upper_bound(2) → index 4
    freq = 4 - 1 = 3
✅ There are 3 occurrences of 2

🧪 Example 2: Element not present
    vector<int> v = {1, 3, 5, 7};
    int x = 4;
    lower_bound(4) → index 2
    upper_bound(4) → index 2
    freq = 2 - 2 = 0
✅ Frequency is 0 (clean & safe)

🧪 Example 3: All elements same
    vector<int> v = {5, 5, 5, 5};
    int x = 5;
    lower_bound(5) → 0
    upper_bound(5) → 4
    freq = 4 - 0 = 4

🧪 Example 4: Single occurrence
    vector<int> v = {1, 2, 3, 4, 5};
    int x = 3;
    lower_bound(3) → 2
    upper_bound(3) → 3
    freq = 3 - 2 = 1

1️⃣0️⃣ fill() — Initialize / reset array
    int arr[5];
    fill(arr, arr + 5, 0);

1️⃣1️⃣ accumulate() — sum
#include <numeric>
int sum = accumulate(arr, arr + n, 0);

Vector:
int sum = accumulate(v.begin(), v.end(), 0);

1️⃣2️⃣ rotate() — Rotate left by k
    rotate(v.begin(), v.begin() + k, v.end());
Example:
1 2 3 4 5
k = 2
Rotated array: 3 4 5 1 2

1️⃣3️⃣ min_element() / max_element()
Syntax
min_element(begin, end);
max_element(begin, end);

What they do:
Find minimum / maximum element

Return type:
Iterator

Time Complexity:
O(n)

Example:
    vector<int> v7 = {5,1,9,2};
    cout << *min_element(v7.begin(), v7.end()) << " ";
    cout << *max_element(v7.begin(), v7.end());

Output:
1 9

1️⃣4️⃣ Insertion - Adding a new element at a specific position.
Steps-
•Shift elements right
•Insert new value

Example (Insert 25 at index 2)
    for(int i = n; i > 2; i--){
        arr[i] = arr[i-1];      Capacity of arr>n
    }
    arr[2] = 25;
    n++;

⏱ Time Complexity:
Beginning / Middle → O(n)
End → O(1) (if space exists)

1️⃣5️⃣ Deletion - Removing an element from a given position.
Steps-
•Shift elements left
•Reduce size

Example (Delete index pos)
    for(int i = pos; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    n--;
⏱ Time Complexity: O(n)
*/
