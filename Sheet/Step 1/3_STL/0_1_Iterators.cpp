/***********************************************************
ITERATORS 
WHAT IS AN ITERATOR?
***********************************************************
An ITERATOR is an object that:
- Points to an element inside a container
- Allows traversal (moving) through the container
- Works like a pointer but is container-aware

Think of iterator as:
"Smart pointer for STL containers"

Iterators allow:
Container  <---->  Algorithms

Why Iterators?
- vector  -> contiguous memory
- list    -> linked list
- set/map -> tree

Algorithms should not care HOW data is stored.
Iterators hide internal structure and provide a COMMON interface.

***********************************************************
 * 1. DECLARING & INITIALIZING ITERATORS
 ***********************************************************
void iterator_basics() {
    vector<int> v = {10, 20, 30};

    // ❌ Old / verbose wayARE
    vector<int>::iterator it1 = v.begin();

    // ✅ Modern CP style (recommended)
    auto it2 = v.begin();

    it2 points to first element (10)    
}

Time Complexity:
Declaration & initialization → O(1)

***********************************************************
 * 2. begin() and end() (MOST IMPORTANT)
 ***********************************************************
Every STL container provides:
- begin() → iterator to FIRST element
- end()   → iterator to ONE-PAST-LAST element

void begin_end_demo() {
    vector<int> v = {10, 20, 30};

    auto it1 = v.begin();  // points to 10
    auto it2 = v.end();    // points AFTER 30 (invalid element)

    cout << *v.begin() << endl; // ✅ OK
    // cout << *v.end();        // ❌ Undefined Behavior (UB)
}

Time Complexity:
begin() → O(1)
end()   → O(1)

***********************************************************
 * 3. DEREFERENCING ITERATORS
 ***********************************************************
*it        → value
it->first → key   (map / set of pairs)
it->second→ value (map)

void dereference_demo() {
    map<int,int> mp = {{1,10}, {2,20}};

    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

Time Complexity:
Dereferencing → O(1)


NOTE:
- set / map ❌ no indexing
- iterators are mandatory there    
Time Complexity:
Traversal → O(n)

***********************************************************
 * 4. ITERATORS WITH ALGORITHMS
 ***********************************************************
void algorithm_demo() {
    vector<int> v = {1, 4, 2, 3};

    // find()
    auto it = find(v.begin(), v.end(), 2);
    if (it != v.end()) {
        cout << "Found" << endl;
    }

    // sort() → Random Access Iterators only
    sort(v.begin(), v.end());
}

Time Complexity:
find() → O(n)
sort() → O(n log n)

***********************************************************
 5. lower_bound / upper_bound (VECTOR)
 ***********************************************************
IMPORTANT:
- Container MUST be sorted

void lower_bound_vector() {
    vector<int> v = {1, 3, 5, 7};
    int x = 5;

    auto it = lower_bound(v.begin(), v.end(), x);

    if (it != v.end() && *it == x) {
        cout << "Exists" << endl;
    }
    
    lower_bound → first element >= x
    upper_bound → first element > x
    
}

Time Complexity:
lower_bound() → O(log n)
upper_bound() → O(log n)

***********************************************************
 * 6. lower_bound IN set / map
 ***********************************************************
void lower_bound_set() {
    set<int> s = {1, 3, 5, 7};

    auto it = s.lower_bound(4);

    ⚠️ DO NOT use std::lower_bound(s.begin(), s.end())
    That would be O(n)

    Use member function → tree-based    
}

Time Complexity:
set::lower_bound() → O(log n)
map::lower_bound() → O(log n)

***********************************************************
 * 7. REVERSE ITERATORS
 ***********************************************************
void reverse_iterator_demo() {
    vector<int> v = {1, 2, 3};

    for (auto it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

Time Complexity:
Traversal → O(n)

***********************************************************
 * 8. erase() WHILE ITERATING
***********************************************************
void erase_demo() {
    vector<int> v = {1, 2, 3, 2, 4};
    int x = 2;

    for (auto it = v.begin(); it != v.end(); ) {
        if (*it == x)
            it = v.erase(it); // returns next valid iterator
        else
            it++;
    }
}

Time Complexity:
vector::erase() → O(n)
set::erase(it)  → O(log n)

***********************************************************
 * 9. ITERATOR INVALIDATION RULES
 ***********************************************************
VECTOR:
- push_back() → ❌ may invalidate
- erase()     → ❌ invalidates erased + after

SET / MAP:
- insert()    → ✅ safe
- erase(it)   → ❌ invalidates erased only

CP RULE:
Never store vector iterators across modifications

*/
