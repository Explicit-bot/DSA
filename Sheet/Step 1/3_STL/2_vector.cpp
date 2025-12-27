/*
*************************************************************
 🧠 C++ VECTOR 
*************************************************************
==============================================================
1️⃣ INTRODUCTION TO std::vector
==============================================================
std::vector is a dynamic array provided by the C++ STL.
Key Characteristics:
✔ Stores elements in contiguous memory (like arrays)
✔ Automatically resizes when elements are added
✔ Fast random access using index
✔ Insertion/deletion in the middle is slow (shifting required)

#include <vector>
using namespace std;

==============================================================
2️⃣ DECLARATION & INITIALIZATION
==============================================================
Declaration
vector<int> v;
vector<string> names;

Initialization Methods
// Initializer list
vector<int> v1 = {1, 2, 3};

// Fixed size, default values (0)
vector<int> v2(5);          // {0,0,0,0,0}

// Fixed size with custom value
vector<int> v3(5, 10);      // {10,10,10,10,10}

// Copy constructor
vector<int> v4(v1);

// From array
int arr[] = {1, 2, 3};
vector<int> v5(arr, arr + 3);

==============================================================
3️⃣ SIZE, CAPACITY & MEMORY MANAGEMENT
==============================================================
// Number of elements actually stored
v.size();

// Total memory allocated (>= size)
v.capacity();

// Maximum possible size (system dependent)
v.max_size();

Memory control
v.reserve(100);      // Pre-allocate memory (no resizing)
v.shrink_to_fit();   // Release unused memory

📌 NOTE:
capacity grows automatically (usually doubles)
reserve() avoids repeated reallocations
reserve(n) guarantees NO reallocation but ONLY until size <= n

==============================================================
4️⃣ ADDING ELEMENTS
==============================================================
// Add element at the end
v.push_back(10);

// Faster for objects (constructs in-place)
v.emplace_back(20);

// Insert at beginning
v.insert(v.begin(), 5);

// Insert at specific index
v.insert(v.begin() + 2, 99);

// In-place insert (advanced usage)
v.emplace(v.begin(), 7);

==============================================================
5️⃣ REMOVING ELEMENTS
==============================================================
// Remove last element
v.pop_back();

// Remove first element
v.erase(v.begin());

// Remove element at index
v.erase(v.begin() + 2);

//Remove Range
v.erase(v.begin(),v.begin()+4)

// Remove all elements
v.clear();


==============================================================
6️⃣ RESIZE vs RESERVE vs ASSIGN
==============================================================
// resize → changes SIZE
v.resize(5);

// reserve → changes CAPACITY only
v.reserve(10);

// assign → replaces entire content
v.assign(4, 100);   // {100,100,100,100}

// Assign from another vector
v.assign(v1.begin(), v1.end());

==============================================================
7️⃣ ACCESSING ELEMENTS
==============================================================
// Fast but unsafe (no bounds check)
v[0];

// Safe access (throws exception if out of range)
v.at(0);

// First and last elements
v.front();
v.back();

// Pointer to internal array
int* ptr = v.data();

⚠️ WARNING:
data() pointer becomes INVALID after resize or reallocation

==============================================================
8️⃣ CHECKING VECTOR STATE
==============================================================
// Check if vector is empty
v.empty();

==============================================================
9️⃣ ITERATORS (VERY IMPORTANT)
==============================================================
// Normal iterator
for(auto it = v.begin(); it != v.end(); it++){
    cout << *it << " ";
}

// Range-based loop (most common)
for(auto x : v){
    cout << x << " ";
}

// Reverse iterator
for(auto it = v.rbegin(); it != v.rend(); it++){
    cout << *it << " ";
}

==============================================================
🔟 SEARCHING ELEMENTS
==============================================================
#include <algorithm>

auto it = find(v.begin(), v.end(), 10);

if(it != v.end())
    cout << "Found";

==============================================================
1️⃣1️⃣ SORTING & REVERSING
==============================================================
// Ascending sort
sort(v.begin(), v.end());

// Descending sort
sort(v.begin(), v.end(), greater<int>());

// Reverse vector
reverse(v.begin(), v.end());


==============================================================
1️⃣2️⃣ BINARY SEARCH UTILITIES (SORTED VECTOR)
==============================================================
// Check existence
binary_search(v.begin(), v.end(), 5);

// First >= 5
auto lb = lower_bound(v.begin(), v.end(), 5);

// First > 5
auto ub = upper_bound(v.begin(), v.end(), 5);

// Convert iterator to index
int index = lb - v.begin();

==============================================================
1️⃣3️⃣ COUNT, MIN & MAX
==============================================================
// Count occurrences
count(v.begin(), v.end(), 5);

// Minimum & maximum elements
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());

==============================================================
1️⃣4️⃣ ERASE–REMOVE IDIOM (IMPORTANT)
==============================================================
// Remove ALL occurrences of 5
v.erase(remove(v.begin(), v.end(), 5), v.end());

==============================================================
1️⃣5️⃣ COPYING & SWAPPING
==============================================================
// Copy vector
vector<int> a = v;

// Swap two vectors (O(1))
v1.swap(v2);

==============================================================
1️⃣6️⃣ VECTOR OF PAIRS
==============================================================
#include <utility>

vector<pair<int,int>> vp;
vp.push_back({1,2});
vp.emplace_back(1,2);

for(auto p : vp){
    cout << p.first << " " << p.second;
}

==============================================================
1️⃣7️⃣ 2D VECTOR (MATRIX)
==============================================================
vector<vector<int>> mat(3, vector<int>(4, 0));

// Access element
mat[i][j];

==============================================================
1️⃣8️⃣ ITERATOR INVALIDATION ⚠️
==============================================================
auto it2 = v.begin();
v.push_back(10);  // it2 MAY become invalid

Invalidated by:
✔ push_back (if reallocation happens)
✔ insert
✔ erase

==============================================================
19 TIME COMPLEXITY SUMMARY
==============================================================
Access (v[i])        → O(1)
push_back            → O(1) amortized
insert / erase       → O(n)
find                 → O(n)
sort                 → O(n log n)
swap                 → O(1)

==============================================================
2️⃣0 VECTOR vs ARRAY
==============================================================
Array  → fixed size
Vector → dynamic size

==============================================================
2️⃣2️⃣ COMPLETE WORKING EXAMPLE
==============================================================
*/

#include <iostream>
using namespace std;

int main(){
    vector<int> v = {3,1,2};

    v.push_back(4);
    sort(v.begin(), v.end());

    for(auto x : v)
        cout << x << " ";
}
/*
==============================================================
🔹 std::vector::front() & std::vector::back()
==============================================================
Definition:
front() returns the FIRST element of the vector.
back() returns the LAST element of the vector.

Equivalent to:
v.front() == v[0];
v.back() == v[v.size() - 1];

Time Complexity:
O(1)

Important Notes:
✔ Returns a REFERENCE to the first or last element
✔ Can be used to READ or MODIFY the element
❌ Calling front() or back() on an empty vector causes UNDEFINED BEHAVIOR

==============================================================
⚠️ SAFETY CHECK (VERY IMPORTANT)
==============================================================
if(!v.empty()){
    cout << v.front();
    cout << v.back();
}
*/



/*
==============================================================
🧠 C++ VECTOR — TIME & SPACE COMPLEXITY (CHEAT SHEET)
==============================================================

--------------------------------------------------------------
1️⃣ ACCESS OPERATIONS
--------------------------------------------------------------
v[i]            → O(1) time, O(1) space   // No bounds check
v.at(i)         → O(1) time, O(1) space   // Throws exception
v.front()       → O(1) time, O(1) space
v.back()        → O(1) time, O(1) space
v.data()        → O(1) time, O(1) space

⚠️ Calling front()/back() on empty vector → UNDEFINED BEHAVIOR


--------------------------------------------------------------
2️⃣ SIZE & CAPACITY
--------------------------------------------------------------
v.size()        → O(1)
v.capacity()    → O(1)
v.max_size()    → O(1)
v.empty()       → O(1)


--------------------------------------------------------------
3️⃣ ADDING ELEMENTS
--------------------------------------------------------------
v.push_back(x)      → O(1) amortized
v.emplace_back(x)   → O(1) amortized
v.insert(pos, x)    → O(n)
v.emplace(pos, x)   → O(n)

📌 push_back() worst case → O(n) (reallocation happens)


--------------------------------------------------------------
4️⃣ REMOVING ELEMENTS
--------------------------------------------------------------
v.pop_back()        → O(1)
v.erase(pos)        → O(n)
v.erase(l, r)       → O(n)
v.clear()           → O(n)


--------------------------------------------------------------
5️⃣ MEMORY MANAGEMENT
--------------------------------------------------------------
v.reserve(n)        → O(n)
v.resize(n)         → O(n)
v.shrink_to_fit()   → O(n)

📌 reserve() avoids repeated reallocations


--------------------------------------------------------------
6️⃣ ASSIGN & COPY
--------------------------------------------------------------
v.assign(n, x)              → O(n)
v.assign(it1, it2)          → O(n)
vector<int> v2 = v1         → O(n) time, O(n) space


--------------------------------------------------------------
7️⃣ ITERATION
--------------------------------------------------------------
Index loop                → O(n)
Iterator loop             → O(n)
Range-based for loop      → O(n)
Reverse iterator          → O(n)


--------------------------------------------------------------
8️⃣ SEARCHING ( <algorithm> )
--------------------------------------------------------------
find()              → O(n)
count()             → O(n)

(binary search utilities require SORTED vector)

binary_search()     → O(log n)
lower_bound()       → O(log n)
upper_bound()       → O(log n)


--------------------------------------------------------------
9️⃣ SORTING & REVERSING
--------------------------------------------------------------
sort()              → O(n log n) time, O(log n) space
reverse()           → O(n) time, O(1) space


--------------------------------------------------------------
🔟 MIN / MAX
--------------------------------------------------------------
min_element()       → O(n)
max_element()       → O(n)


--------------------------------------------------------------
1️⃣1️⃣ ERASE–REMOVE IDIOM
--------------------------------------------------------------
v.erase(remove(v.begin(), v.end(), x), v.end());

remove()            → O(n)
erase()             → O(n)
Total               → O(n) time, O(1) space


--------------------------------------------------------------
1️⃣2️⃣ SWAP
--------------------------------------------------------------
v1.swap(v2)         → O(1) time, O(1) space
// Only internal pointers are swapped


--------------------------------------------------------------
1️⃣3️⃣ VECTOR OF PAIRS
--------------------------------------------------------------
push_back({a,b})    → O(1) amortized
emplace_back(a,b)   → O(1) amortized
Traversal           → O(n)


--------------------------------------------------------------
1️⃣4️⃣ 2D VECTOR
--------------------------------------------------------------
mat[i][j]           → O(1)
Traversal           → O(rows × cols)


--------------------------------------------------------------
1️⃣5️⃣ ITERATOR INVALIDATION ⚠️ (VERY IMPORTANT)
--------------------------------------------------------------
push_back()     → May invalidate (if reallocation)
insert()        → Invalidates
erase()         → Invalidates
reserve()       → Invalidates
clear()         → Invalidates


--------------------------------------------------------------
1️⃣6️⃣ ONE-LINE EXAM SUMMARY
--------------------------------------------------------------
std::vector provides O(1) random access, amortized O(1) insertion
at the end, and O(n) insertion/deletion elsewhere due to shifting.

==============================================================
*/
