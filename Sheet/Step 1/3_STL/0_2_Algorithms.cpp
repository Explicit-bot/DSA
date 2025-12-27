/*************************************************************
 IMPORTANT STL ALGORITHMS 
==============================================================
1️⃣ sort()
==============================================================
Syntax
    sort(begin, end);

What it does:
Sorts elements in ascending order
Internally uses Introsort (Quick + Heap + Insertion sort)

Return type:
void (returns nothing)

Containers supported:
✔ vector
✔ deque
✔ array
❌ NOT list (needs random access iterators)

Time Complexity:
Best    → O(n log n)
Average → O(n log n)
Worst   → O(n log n)

Example:
    vector<int> v1 = {5, 2, 9, 1};
    sort(v1.begin(), v1.end());

Output:
1 2 5 9

CP Usage:
✔ Almost every problem
✔ Preprocessing before binary search, greedy, two pointers

//Sort using comparisions
bool comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

sort(vp.begin(), vp.end(), comp);

==============================================================
2️⃣ binary_search()  ⚠️ SORTED REQUIRED
==============================================================
Syntax
    binary_search(begin, end, value);

What it does:
Checks whether a value exists using binary search

Return type:
bool

Containers supported:
✔ vector
✔ deque
✔ array
⚠️ MUST be sorted

Time Complexity:
O(log n)

Example:
    vector<int> v2 = {1,2,3,4,5};
    cout << binary_search(v2.begin(), v2.end(), 3);

Output:
1

CP Usage:
✔ Membership checking
✔ Faster than find() on sorted data

==============================================================
3️⃣ lower_bound()  🔥 VERY IMPORTANT
==============================================================
Syntax
lower_bound(begin, end, x);

What it does:
Finds FIRST position where element ≥ x
Does NOT check existence only

Return type:
Iterator
end() if no element ≥ x

Containers supported:
✔ vector
✔ deque
✔ array
⚠️ MUST be sorted

Time Complexity:
O(log n)

Example:
    vector<int> v3 = {1,2,2,2,3,4};
    auto lb = lower_bound(v3.begin(), v3.end(), 2);
    cout << lb - v3.begin();

Output:
1

CP Usage:
✔ Frequency counting
✔ Binary search problems
✔ Range queries

==============================================================
4️⃣ upper_bound()
==============================================================
Syntax
    upper_bound(begin, end, x);

What it does:
Finds FIRST element strictly > x

Return type:
Iterator

Time Complexity:
O(log n)

Example:
    auto ub = upper_bound(v3.begin(), v3.end(), 2);
    cout << ub - v3.begin();

Output:
4

CP Usage:   ***********
count of x = upper_bound - lower_bound

==============================================================
5️⃣ find()
==============================================================
Syntax
    find(begin, end, value);

What it does:
Linear search for a value

Return type:
Iterator if found
end() if not found

Containers supported:
✔ ALL containers

Time Complexity:
O(n)

Example:
    vector<int> v4 = {3,6,9};
    auto it = find(v4.begin(), v4.end(), 6);
    cout << (it != v4.end());

Output:
1

CP Usage:
✔ Unsorted data
✔ Small constraints

==============================================================
6️⃣ accumulate()  🔥 CP FAVORITE
==============================================================
Header required:
#include <numeric>

Syntax
accumulate(begin, end, initial_value);

What it does:
Adds all elements (can also use custom operation)

Return type:
Accumulated value

Containers supported:
✔ vector
✔ array
✔ deque

Time Complexity:
O(n)

Example:
    vector<int> v5 = {1,2,3,4};
    cout << accumulate(v5.begin(), v5.end(), 0);

Output:
10

CP Usage:
✔ Prefix sums
✔ Sum checks

==============================================================
7️⃣ count()
==============================================================
Syntax
count(begin, end, value);

What it does:
Counts occurrences of a value

Return type:
int

Time Complexity:
O(n)

Example:
    vector<int> v6 = {1,2,2,2,3};
    cout << count(v6.begin(), v6.end(), 2);

Output:
3

==============================================================
8️⃣ min_element() / max_element()
==============================================================
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

==============================================================
9️⃣ reverse()
==============================================================
Syntax
reverse(begin, end);

What it does:
Reverses the range

Return type:
void

Time Complexity:
O(n)

Example:
    vector<int> v8 = {1,2,3};
    reverse(v8.begin(), v8.end());

Output:
3 2 1

==============================================================
🔟 next_permutation()  🔥 MUST KNOW
==============================================================
Syntax
next_permutation(begin, end);

What it does:
Generates the next lexicographical permutation

Return type:
bool

Time Complexity:
O(n)

Example:
    vector<int> v9 = {1,2,3};
    next_permutation(v9.begin(), v9.end());

Output:
1 3 2

==============================================================
1️⃣1️⃣ remove() + erase()  ⚠️ VERY IMPORTANT
==============================================================
Syntax
remove(begin, end, value);

What remove() does:
Shifts unwanted elements to the end
DOES NOT change container size

Correct CP Usage (Erase–Remove Idiom):
    vector<int> v10 = {1,2,3,2,4};
    v10.erase(remove(v10.begin(), v10.end(), 2), v10.end());

Output:
1 3 4

Time Complexity:
O(n)

==============================================================
1️⃣2️⃣ unique()  🔥 DUPLICATE REMOVAL
==============================================================
Syntax
unique(begin, end);

What it does:
Removes CONSECUTIVE duplicates
Usually used after sorting

Return type:
Iterator to new logical end

Time Complexity:
O(n)

Example:
    vector<int> v11 = {1,1,2,2,3};
    v11.erase(unique(v11.begin(), v11.end()), v11.end());

Output:
1 2 3

==============================================================
🔁 std::rotate() — the official STL move
==============================================================
📌 Syntax
rotate(start, middle, end);

🧠 What it actually does
It rotates the range [start, end) such that
middle becomes the new first element.

🔄 Left Rotation (most common in CP)
Example: Left rotate by k

    vector<int> v = {1, 2, 3, 4, 5};
    int k = 2;

    rotate(v.begin(), v.begin() + k, v.end());
    // v becomes {3, 4, 5, 1, 2}

🔄 Right Rotation (aka “rotate backwards”)
Right rotate by k is just a small brain-flip 🧠

    int k = 2;
    rotate(v.begin(), v.end() - k, v.end());
    // {4, 5, 1, 2, 3}

⚡ Time & Space Complexity
Time: O(n)
Space: O(1) (in-place, no extra array 😮‍🔥)

std::rotate() works on:
array
vector
deque
string
any container with Forward Iterators
*/
