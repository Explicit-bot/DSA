/***********************************************************
ITERATORS 
WHAT IS AN ITERATOR?
***********************************************************
An ITERATOR is an object that:
- Points to an element inside a container
- Allows traversal (moving) through the container
- Works like a pointer but is container-aware

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
it->first  → key   (map / set of pairs)
it->second → value (map)

it->first    ==    (*it).first
it->second   ==    (*it).second

*it.first    // ❌ WRONG
(*it).first  // ✅ CORRECT

void dereference_demo() {
    map<int,int> mp = {{1,10}, {2,20}};

    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

Time Complexity:
Dereferencing → O(1)

| Aspect       | ++it                                         | it + 1                         |
| ------------ | -------------------------------------------- | -------------------------------- |
| Meaning      | Move to next element                         | Jump 1 position ahead        |
| Works for    | All iterators                                | Only random-access iterators     |
| Containers   | vector, deque, list, set, map, unordered_map | vector, deque, array             |
| Safety       | ✅ STL-safe, universal                       | ❌ Limited, can fail to compile   |
| How it moves | Container-aware                              | Pointer arithmetic               |
| CP usage     | ⭐ Recommended everywhere                    | 🚫 Avoid in traversal            |
| Performance  | Optimal                                      | Same (when valid)                |

NOTE:
- set / map ❌ no indexing
- iterators are mandatory there    
Time Complexity:
Traversal → O(n)

***********************************************************
 * 4. REVERSE ITERATORS
 ***********************************************************
- rbegin() → last element
- rend() → before first (never deref)

//++it moves backward
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
 * 5. ITERATOR INVALIDATION RULES
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
