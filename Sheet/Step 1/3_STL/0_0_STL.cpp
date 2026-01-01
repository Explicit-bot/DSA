/*
*****************************************************
 🔥 C++ STL (Standard Template Library) 
*****************************************************
STL = Collection of generic classes & functions
Used for data storage, manipulation, searching, sorting
Saves time + optimized + reusable

====================================================
  1️⃣ MAIN COMPONENTS OF STL
====================================================
STL has 4 core parts:
1. Containers  -> store data
2. Algorithms  -> operate on data
3. Iterators   -> traverse containers
4. Functors    -> objects behaving like functions

====================================================
  2️⃣ CONTAINERS
====================================================
---- (A) Sequence Containers (ordered) ----
#include <vector>        // dynamic array
#include <deque>         // double-ended queue
#include <list>          // doubly linked list
#include <array>         // fixed-size array
#include <forward_list>  // singly linked list

vector      -> fast access, dynamic size
deque       -> insertion at both ends
list        -> fast insertion/deletion
array       -> fixed size, faster than vector

---- (B) Associative Containers (sorted) ----
#include <set>
#include <map>
#include <multiset>
#include <multimap>

set         -> unique + sorted
map         -> key-value (unique keys)
multiset    -> duplicate allowed
Time: O(log n)

---- (C) Unordered Containers (hash-based) ----
#include <unordered_set>
#include <unordered_map>

unordered_set / map
Average Time: O(1)
Not sorted

---- (D) Container Adapters ----
#include <stack>
#include <queue>
#include <priority_queue>

stack           -> LIFO
queue           -> FIFO
priority_queue  -> max/min heap

====================================================
  3️⃣ ITERATORS
====================================================
Iterator = pointer-like object to traverse containers
Common functions:
begin() -> first element
end()   -> after last element

vector<int> v = {1,2,3};

for(auto it = v.begin(); it != v.end(); it++){
    cout << *it;
}

====================================================
  4️⃣ ALGORITHMS
====================================================
#include <algorithm>

Common algorithms:
sort()          -> sort data
reverse()       -> reverse range
find()          -> search element
count()         -> count occurrences
max_element()   -> largest element
min_element()   -> smallest element
binary_search() -> search in sorted container

sort(v.begin(), v.end());
reverse(v.begin(), v.end());

====================================================
  5️⃣ FUNCTORS (Function Objects)
====================================================
Class that behaves like a function
Used internally by STL

sort(v.begin(), v.end(), greater<int>());

🔥 WHAT DOES AMORTIZED TIME COMPLEXITY MEAN?
 Example: std::vector::push_back()
*************************************************************
Amortized = average cost per operation over a long sequence
of operations, not the cost of a single operation.

👉 Even if some operations are expensive,
    overall performance is still cheap.

==============================================================
🧠 Why push_back() is NOT always O(1)
==============================================================
#include <vector>
using namespace std;
----------------------------
Case 1️⃣: Normal push (CHEAP)
----------------------------
vector<int> v;

v.push_back(1);
v.push_back(2);
v.push_back(3);

If capacity is available:
✔ Element is added at the end
✔ No reallocation happens
✔ Time Complexity = O(1)

----------------------------
Case 2️⃣: Capacity FULL (EXPENSIVE 😬)
----------------------------
// Assume current capacity = 4
v.push_back(5);

What happens internally:

1️⃣ New memory block is allocated (larger capacity)
2️⃣ ALL existing elements are copied to new memory
3️⃣ Old memory block is deleted
4️⃣ New element is inserted

⏱️ Time Complexity = O(n)

==============================================================
⚖️ Why is push_back() still O(1) AMORTIZED?
==============================================================
Capacity Growth Example (Typical Doubling Strategy)
Push No. | Capacity | Cost
--------------------------
1        | 1        | O(1)
2        | 2        | O(1)
3        | 4        | O(n)  // reallocation
4        | 4        | O(1)
5        | 8        | O(n)  // reallocation
6        | 8        | O(1)

💡 Expensive operations happen RARELY
💡 Cheap operations happen MOST of the time

Total cost of all push_back operations = O(n)
Total number of operations               = n

👉 Average cost per operation = O(n) / n = O(1)

*/
