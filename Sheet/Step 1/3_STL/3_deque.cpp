/*
*************************************************************
 🧠 C++ DEQUE (Double Ended Queue)
*************************************************************
==============================================================
1️⃣ INTRODUCTION TO std::deque
==============================================================
std::deque (Double Ended Queue) is a sequence container in C++ STL
that allows FAST insertion and deletion at BOTH ends.

Key Characteristics:
✔ Dynamic size
✔ Fast insertion & deletion at FRONT and BACK
✔ Random access supported (like vector)
❌ NOT stored in contiguous memory
❌ Slightly slower than vector for indexing

#include <deque>
using namespace std;

==============================================================
2️⃣ DECLARATION & INITIALIZATION
==============================================================
// Declaration
deque<int> dq;
deque<string> names;

// Initializer list
deque<int> dq1 = {1, 2, 3};

// Fixed size (default initialized)
deque<int> dq2(5);          // {0,0,0,0,0}

// Fixed size with custom value
deque<int> dq3(5, 10);      // {10,10,10,10,10}

// Copy constructor
deque<int> dq4(dq1);

// From array
int arr[] = {1, 2, 3};
deque<int> dq5(arr, arr + 3);

==============================================================
3️⃣ INTERNAL MEMORY MODEL (IMPORTANT 🧠)
==============================================================
vector → contiguous memory
deque  → segmented memory (multiple blocks)

Why?
✔ Allows O(1) push_front()
✔ Avoids shifting elements

📌 This is why:
- dq[i] is slightly slower than v[i]
- data() is NOT reliable like vector

==============================================================
4️⃣ ADDING ELEMENTS
==============================================================
// Add at back
dq.push_back(10);
dq.emplace_back(20);

// Add at front
dq.push_front(5);
dq.emplace_front(3);

// Insert at position
dq.insert(dq.begin() + 2, 99);

// Emplace at position
dq.emplace(dq.begin() + 1, 7);

==============================================================
5️⃣ REMOVING ELEMENTS
==============================================================
// Remove from back
dq.pop_back();

// Remove from front
dq.pop_front();

// Remove element at index
dq.erase(dq.begin() + 2);

// Remove range
dq.erase(dq.begin(), dq.begin() + 3);

// Remove all elements
dq.clear();

==============================================================
6️⃣ SIZE & CAPACITY
==============================================================
dq.size();       // Number of elements
dq.empty();      // Check if empty

⚠️ NOTE:
deque DOES NOT expose capacity()
(no reserve(), no shrink_to_fit())

==============================================================
7️⃣ ACCESSING ELEMENTS
==============================================================
// Random access (allowed)
dq[0];          // Fast but unsafe
dq.at(0);       // Safe (throws exception)

// First & last elements
dq.front();
dq.back();

==============================================================
8️⃣ ITERATORS (SAME AS VECTOR)
==============================================================
#include <iostream>

// Normal iterator
for(auto it = dq.begin(); it != dq.end(); it++){
    cout << *it << " ";
}

// Range-based loop (most common)
for(auto x : dq){
    cout << x << " ";
}

// Reverse iterator
for(auto it = dq.rbegin(); it != dq.rend(); it++){
    cout << *it << " ";
}

// Constant iterators
dq.cbegin();
dq.cend();

==============================================================
9️⃣ SEARCHING ELEMENTS
==============================================================
#include <algorithm>

auto it = find(dq.begin(), dq.end(), 10);

if(it != dq.end())
    cout << "Found";

==============================================================
🔟 SORTING & REVERSING
==============================================================
// Sorting (works fine)
sort(dq.begin(), dq.end());

// Reverse deque
reverse(dq.begin(), dq.end());

==============================================================
1️⃣1️⃣ BINARY SEARCH UTILITIES
==============================================================
⚠️ Deque MUST be sorted

binary_search(dq.begin(), dq.end(), 5);

auto lb = lower_bound(dq.begin(), dq.end(), 5);
auto ub = upper_bound(dq.begin(), dq.end(), 5);

// Iterator → index
int index = lb - dq.begin();

==============================================================
1️⃣2️⃣ COUNT, MIN & MAX
==============================================================
count(dq.begin(), dq.end(), 5);

*min_element(dq.begin(), dq.end());
*max_element(dq.begin(), dq.end());

==============================================================
1️⃣3️⃣ ERASE–REMOVE IDIOM
==============================================================
dq.erase(remove(dq.begin(), dq.end(), 5), dq.end());

==============================================================
1️⃣4️⃣ COPYING & SWAPPING
==============================================================
deque<int> d1 = dq;

// Swap two deques (O(1))
dq1.swap(dq2);

==============================================================
1️⃣5️⃣ DEQUE OF PAIRS
==============================================================
#include <utility>

deque<pair<int,int>> dp;
dp.push_back({1,2});
dp.emplace_front(3,4);

for(auto p : dp){
    cout << p.first << " " << p.second;
}

==============================================================
1️⃣6️⃣ 2D DEQUE (RARE BUT VALID)
==============================================================
deque<deque<int>> mat(3, deque<int>(4, 0));

// Access
mat[i][j];

==============================================================
1️⃣7️⃣ ITERATOR INVALIDATION ⚠️
==============================================================
auto it = dq.begin();

dq.push_front(10);  // ❌ it MAY become invalid
dq.push_back(20);   // ❌ it MAY become invalid
dq.insert(...);     // ❌ invalidates iterators
dq.erase(...);      // ❌ invalidates erased ones

==============================================================
1️⃣8️⃣ DEQUE vs VECTOR (VERY IMPORTANT FOR CP)
==============================================================
vector:
✔ Faster random access
❌ Slow push_front()

deque:
✔ Fast push_front() & push_back()
✔ No reallocation pain
❌ Slightly slower indexing

📌 USE CASE RULE:
Need front + back ops → deque
Need pure indexing → vector

==============================================================
1️⃣9️⃣ DEQUE vs QUEUE
==============================================================
queue → FIFO only
deque → Full control (front + back + indexing)

==============================================================
2️⃣0️⃣ TIME COMPLEXITY SUMMARY
==============================================================
Access (dq[i])       → O(1)
push_back            → O(1)
push_front           → O(1)
pop_back/front       → O(1)
insert / erase mid   → O(n)
find                 → O(n)
sort                 → O(n log n)
swap                 → O(1)

==============================================================
2️⃣1️⃣ COMPLETE WORKING EXAMPLE
==============================================================
*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    deque<int> dq = {3, 1, 2};

    dq.push_front(10);
    dq.push_back(5);

    sort(dq.begin(), dq.end());

    for(auto x : dq)
        cout << x << " ";
}
