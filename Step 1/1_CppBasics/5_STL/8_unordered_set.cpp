/*
*************************************************************
 🧠 C++ UNORDERED SET
*************************************************************

==============================================================
1️⃣ INTRODUCTION TO std::unordered_set
==============================================================

std::unordered_set is a hash-table based container provided by STL.

✔ Stores UNIQUE elements only
✔ Elements are NOT stored in sorted order
✔ Average O(1) insertion, deletion, searching
✔ Internally uses HASHING
✔ Duplicate values are automatically ignored

Header File:
#include <unordered_set>

Namespace:
using namespace std;

==============================================================
2️⃣ DECLARATION & INITIALIZATION
==============================================================

// Empty unordered_set
unordered_set<int> us;

// Initializer list
unordered_set<int> us2 = {1,2,3,4};

// Duplicate ignored automatically
unordered_set<int> us3 = {1,2,2,2,3};
// Stores only: {1,2,3}

// From vector
vector<int> v = {1,2,3};
unordered_set<int> us4(v.begin(), v.end());

==============================================================
3️⃣ IMPORTANT CHARACTERISTICS
==============================================================

✔ Unique elements only
✔ No indexing
✔ No ordering
✔ Fast average operations
✔ Uses hash function internally

⚠️ Elements appear in RANDOM ORDER

Example:
unordered_set<int> us = {5,1,3};

Output may be:
3 5 1

==============================================================
4️⃣ INSERTING ELEMENTS
==============================================================

// Insert element
us.insert(10);

// Duplicate ignored
us.insert(10);

==============================================================
5️⃣ REMOVING ELEMENTS
==============================================================

// Remove by value
us.erase(10);

// Remove using iterator
auto it = us.find(5);
us.erase(it);

// Remove all elements
us.clear();

==============================================================
6️⃣ SEARCHING ELEMENTS
==============================================================

// Find element
auto it = us.find(20);

if(it != us.end()){
    cout << "Found";
}
else{
    cout << "Not Found";
}

==============================================================
7️⃣ CHECK EXISTENCE
==============================================================

// count() returns either 0 or 1
if(us.count(5)){
    cout << "Exists";
}

==============================================================
8️⃣ SIZE OPERATIONS
==============================================================

// Number of elements
us.size();

// Check empty
us.empty();

// Maximum possible size
us.max_size();

==============================================================
9️⃣ ITERATORS
==============================================================

// Using iterator
for(auto it = us.begin(); it != us.end(); ++it){
    cout << *it << " ";
}

// Range-based loop
for(auto x : us){
    cout << x << " ";
}

==============================================================
🔟 BUCKETS & HASHING (VERY IMPORTANT)
==============================================================

unordered_set stores elements in BUCKETS.

Important Functions:

// Number of buckets
us.bucket_count();

// Bucket number of element
us.bucket(10);

// Elements inside specific bucket
us.bucket_size(0);

// Load factor
us.load_factor();

// Maximum load factor
us.max_load_factor();

==============================================================
1️⃣1️⃣ REHASHING
==============================================================

// Rehash container
us.rehash(20);

// Reserve buckets
us.reserve(100);

📌 reserve(n)
Allocates enough buckets to avoid rehashing.

==============================================================
1️⃣2️⃣ HASH FUNCTION
==============================================================

// Default hash function
hash<int> h;

cout << h(10);

==============================================================
1️⃣3️⃣ CUSTOM HASH FUNCTION
==============================================================

struct customHash{
    size_t operator()(int x) const{
        return x * 31;
    }
};

unordered_set<int, customHash> us;

==============================================================
1️⃣4️⃣ UNORDERED SET OF PAIRS
==============================================================

struct pairHash{
    size_t operator()(const pair<int,int>& p) const{
        return p.first ^ p.second;
    }
};

unordered_set<pair<int,int>, pairHash> us;

==============================================================
1️⃣5️⃣ INSERT RETURN VALUE
==============================================================

auto result = us.insert(10);

result.first   -> iterator
result.second  -> true if inserted

Example:

if(result.second){
    cout << "Inserted";
}
else{
    cout << "Already Exists";
}

==============================================================
1️⃣6️⃣ ERASE RETURN VALUE
==============================================================

// Returns number of elements erased
cout << us.erase(10);

==============================================================
1️⃣7️⃣ SWAP
==============================================================

unordered_set<int> a = {1,2};
unordered_set<int> b = {3,4};

a.swap(b);

==============================================================
1️⃣8️⃣ LOAD FACTOR
==============================================================

Formula:

load_factor = size / bucket_count

Higher load factor:
❌ More collisions
❌ Slower performance

==============================================================
1️⃣9️⃣ COLLISIONS
==============================================================

Collision means:
Two elements map to same bucket.

Handled internally using chaining.

==============================================================
2️⃣0️⃣ TIME COMPLEXITY SUMMARY
==============================================================

insert()       → O(1) average
erase()        → O(1) average
find()         → O(1) average
count()        → O(1) average

Worst Case:
All become O(n)

==============================================================
2️⃣1️⃣ WHY WORST CASE O(n)?
==============================================================

If many collisions happen,
all elements may end up in same bucket.

Then searching becomes linear.

==============================================================
2️⃣2️⃣ ORDERED SET vs UNORDERED SET
==============================================================

set:
✔ Sorted
✔ O(log n)

unordered_set:
✔ Unsorted
✔ Average O(1)

==============================================================
2️⃣3️⃣ WHEN TO USE unordered_set
==============================================================

Use unordered_set when:
✔ Fast lookup needed
✔ Order does NOT matter
✔ Unique elements required

Examples:
✔ Duplicate detection
✔ Frequency checking
✔ Fast searching

==============================================================
2️⃣4️⃣ COMMON STL ALGORITHMS USED
==============================================================

--------------------------------------------------------------
🔹 find()
--------------------------------------------------------------

auto it = us.find(5);

--------------------------------------------------------------
🔹 count()
--------------------------------------------------------------

us.count(10);

--------------------------------------------------------------
🔹 erase()
--------------------------------------------------------------

us.erase(10);

--------------------------------------------------------------
🔹 insert()
--------------------------------------------------------------

us.insert(20);

--------------------------------------------------------------
🔹 clear()
--------------------------------------------------------------

us.clear();

--------------------------------------------------------------
🔹 swap()
--------------------------------------------------------------

us1.swap(us2);

==============================================================
2️⃣5️⃣ COMPLETE WORKING EXAMPLE
==============================================================
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int main(){

    unordered_set<int> us;

    us.insert(10);
    us.insert(20);
    us.insert(30);
    us.insert(20);

    cout << "Elements:\n";

    for(auto x : us){
        cout << x << " ";
    }

    cout << "\n";

    if(us.find(20) != us.end()){
        cout << "Found\n";
    }

    us.erase(10);

    cout << "After erase:\n";

    for(auto x : us){
        cout << x << " ";
    }
}

/*
==============================================================
🧠 ITERATOR INVALIDATION ⚠️
==============================================================

insert()
→ May invalidate iterators if rehashing happens

erase()
→ Only erased iterator invalidated

rehash()
→ All iterators invalidated

clear()
→ All iterators invalidated

==============================================================
🧠 UNORDERED SET — TIME & SPACE COMPLEXITY
==============================================================

--------------------------------------------------------------
1️⃣ INSERTION
--------------------------------------------------------------

insert(x)
Average  → O(1)
Worst    → O(n)

Space    → O(1)

--------------------------------------------------------------
2️⃣ SEARCHING
--------------------------------------------------------------

find(x)
count(x)

Average  → O(1)
Worst    → O(n)

--------------------------------------------------------------
3️⃣ DELETION
--------------------------------------------------------------

erase(x)

Average  → O(1)
Worst    → O(n)

--------------------------------------------------------------
4️⃣ ITERATION
--------------------------------------------------------------

Traversal → O(n)

--------------------------------------------------------------
5️⃣ CLEAR
--------------------------------------------------------------

clear() → O(n)

--------------------------------------------------------------
6️⃣ REHASH
--------------------------------------------------------------

rehash(n) → O(n)

--------------------------------------------------------------
7️⃣ RESERVE
--------------------------------------------------------------

reserve(n) → O(n)

==============================================================
🧠 INTERNAL WORKING OF unordered_set
==============================================================

Element
   ↓
Hash Function
   ↓
Bucket Index
   ↓
Stored in Bucket

==============================================================
🧠 IMPORTANT INTERVIEW NOTES
==============================================================

✔ unordered_set stores unique elements
✔ No ordering guarantee
✔ Based on hashing
✔ Average O(1) operations
✔ Worst-case O(n)
✔ No indexing possible
✔ Duplicate insertions ignored
✔ Faster than set in most cases

==============================================================
🧠 COMMON INTERVIEW QUESTIONS
==============================================================

Q1. Difference between set and unordered_set?

set:
→ Balanced BST
→ Sorted
→ O(log n)

unordered_set:
→ Hash Table
→ Unsorted
→ Average O(1)

--------------------------------------------------------------

Q2. Why collisions happen?

Different elements may produce same bucket index.

--------------------------------------------------------------

Q3. Why unordered_set can become slow?

Too many collisions.

--------------------------------------------------------------

Q4. Can unordered_set store duplicates?

❌ No

Use unordered_multiset for duplicates.

==============================================================
🧠 ONE-LINE EXAM SUMMARY
==============================================================

std::unordered_set is a hash-table based STL container
that stores UNIQUE unordered elements with average
O(1) insertion, deletion, and searching.
==============================================================
*/
