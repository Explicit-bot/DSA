/*
C++ Standard Library VECTOR

| Type     | Operation / Algorithm | Complexity                   |
| -------- | --------------------- | ---------------------------- |
| Access   |  v[i]                 | O(1)                         |
| Access   |  v.at(i)              | O(1)                         |
| Access   |  front()              | O(1)                         |
| Access   |  back()               | O(1)                         |
| Access   |  data()               | O(1)                         |
| Capacity |  size()               | O(1)                         |
| Capacity |  capacity()           | O(1)                         |
| Capacity |  empty()              | O(1)                         |
| Capacity |  max_size()           | O(1)                         |
| Insert   |  push_back()          | O(1) amortized (Worst: O(n)) |
| Insert   |  emplace_back()       | O(1) amortized (Worst: O(n)) |
| Insert   |  insert()             | O(n)                         |
| Insert   |  emplace()            | O(n)                         |
| Delete   |  pop_back()           | O(1)                         |
| Delete   |  erase(pos)           | O(n)                         |
| Delete   |  erase(first,last)    | O(n)                         |
| Delete   |  clear()              | O(n)                         |
| Memory   |  reserve()            | O(n)                         |
| Memory   |  resize()             | O(n)                         |
| Memory   |  shrink_to_fit()      | O(n)                         |
| Utility  |  swap()               | O(1)                         |
| Utility  |  assign()             | O(n)                         |
| Iterator |  begin()  /  end()    | O(1)                         |
| Iterator |  rbegin()  /  rend()  | O(1)                         |
| Search   |  find()               | O(n)                         |
| Search   |  count()              | O(n)                         |
| Search   |  binary_search()      | O(log n)                     |
| Search   |  lower_bound()        | O(log n)                     |
| Search   |  upper_bound()        | O(log n)                     |
| Sorting  |  sort()               | O(n log n)                   |
| Sorting  |  stable_sort()        | O(n log n)                   |
| Utility  |  reverse()            | O(n)                         |
| Utility  |  min_element()        | O(n)                         |
| Utility  |  max_element()        | O(n)                         |
| Numeric  |  accumulate()         | O(n)                         |

DEQUE
| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Access   |  dq[i]                | O(1)       |
| Access   |  dq.at(i)             | O(1)       |
| Access   |  front()              | O(1)       |
| Access   |  back()               | O(1)       |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |
| Insert   |  push_back()          | O(1)       |
| Insert   |  push_front()         | O(1)       |
| Delete   |  pop_back()           | O(1)       |
| Delete   |  pop_front()          | O(1)       |
| Insert   |  insert()             | O(n)       |
| Delete   |  erase()              | O(n)       |
| Delete   |  clear()              | O(n)       |
| Search   |  find()               | O(n)       |
| Search   |  count()              | O(n)       |
| Search   |  binary_search()      | O(log n)   |
| Search   |  lower_bound()        | O(log n)   |
| Search   |  upper_bound()        | O(log n)   |
| Sorting  |  sort()               | O(n log n) |
| Utility  |  reverse()            | O(n)       |


LIST
| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Access   |  front()              | O(1)       |
| Access   |  back()               | O(1)       |
| Insert   |  push_back()          | O(1)       |
| Insert   |  push_front()         | O(1)       |
| Delete   |  pop_back()           | O(1)       |
| Delete   |  pop_front()          | O(1)       |
| Insert   |  insert(iterator)     | O(1)       |
| Delete   |  erase(iterator)      | O(1)       |
| Delete   |  remove()             | O(n)       |
| Delete   |  clear()              | O(n)       |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |
| Search   |  find()               | O(n)       |
| Search   |  count()              | O(n)       |
| Search   |  lower_bound()        | O(n)       |
| Search   |  upper_bound()        | O(n)       |
| Sorting  |  sort()               | O(n log n) |
| Utility  |  reverse()            | O(n)       |
| Utility  |  merge()              | O(n)       |
| Utility  |  splice()             | O(1)       |

FORWARD_LIST
| Type    | Operation / Algorithm | Complexity |
| ------- | --------------------- | ---------- |
| Access  |  front()              | O(1)       |
| Insert  |  push_front()         | O(1)       |
| Delete  |  pop_front()          | O(1)       |
| Insert  |  insert_after()       | O(1)       |
| Delete  |  erase_after()        | O(1)       |
| Delete  |  remove()             | O(n)       |
| Delete  |  clear()              | O(n)       |
| Search  |  find()               | O(n)       |
| Search  |  count()              | O(n)       |
| Sorting |  sort()               | O(n log n) |
| Utility |  reverse()            | O(n)       |

SET
| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Insert   |  insert()             | O(log n)   |
| Delete   |  erase()              | O(log n)   |
| Delete   |  clear()              | O(n)       |
| Search   |  find()               | O(log n)   |
| Search   |  count()              | O(log n)   |
| Search   |  lower_bound()        | O(log n)   |
| Search   |  upper_bound()        | O(log n)   |
| Search   |  equal_range()        | O(log n)   |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |

MULTISET
| Type     | Operation / Algorithm | Complexity             |
| -------- | --------------------- | ---------------------- |
| Insert   |  insert()             | O(log n)               |
| Delete   |  erase(iterator)      | O(log n)               |
| Delete   |  erase(value)         | O(log n + occurrences) |
| Delete   |  clear()              | O(n)                   |
| Search   |  find()               | O(log n)               |
| Search   |  count()              | O(log n + occurrences) |
| Search   |  lower_bound()        | O(log n)               |
| Search   |  upper_bound()        | O(log n)               |
| Search   |  equal_range()        | O(log n)               |
| Capacity |  size()               | O(1)                   |
| Capacity |  empty()              | O(1)                   |

MAP
| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Access   |  operator[]           | O(log n)   |
| Access   |  at()                 | O(log n)   |
| Insert   |  insert()             | O(log n)   |
| Insert   |  emplace()            | O(log n)   |
| Delete   |  erase()              | O(log n)   |
| Delete   |  clear()              | O(n)       |
| Search   |  find()               | O(log n)   |
| Search   |  count()              | O(log n)   |
| Search   |  lower_bound()        | O(log n)   |
| Search   |  upper_bound()        | O(log n)   |
| Search   |  equal_range()        | O(log n)   |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |

MULTIMAP
| Type     | Operation / Algorithm | Complexity            |
| -------- | --------------------- | --------------------- |
| Insert   |  insert()             | O(log n)              |
| Insert   |  emplace()            | O(log n)              |
| Delete   |  erase()              | O(log n)              |
| Delete   |  clear()              | O(n)                  |
| Search   |  find()               | O(log n)              |
| Search   |  count()              | O(log n + duplicates) |
| Search   |  lower_bound()        | O(log n)              |
| Search   |  upper_bound()        | O(log n)              |
| Search   |  equal_range()        | O(log n)              |
| Capacity |  size()               | O(1)                  |
| Capacity |  empty()              | O(1)                  |

UNORDERED_SET
| Type     | Operation / Algorithm | Complexity             |
| -------- | --------------------- | ---------------------- |
| Insert   |  insert()             | O(1) avg (Worst: O(n)) |
| Delete   |  erase()              | O(1) avg (Worst: O(n)) |
| Delete   |  clear()              | O(n)                   |
| Search   |  find()               | O(1) avg (Worst: O(n)) |
| Search   |  count()              | O(1) avg (Worst: O(n)) |
| Capacity |  size()               | O(1)                   |
| Capacity |  empty()              | O(1)                   |

UNORDERED_MAP
| Type     | Operation / Algorithm | Complexity             |
| -------- | --------------------- | ---------------------- |
| Access   |  operator[]           | O(1) avg (Worst: O(n)) |
| Access   |  at()                 | O(1) avg (Worst: O(n)) |
| Insert   |  insert()             | O(1) avg (Worst: O(n)) |
| Insert   |  emplace()            | O(1) avg (Worst: O(n)) |
| Delete   |  erase()              | O(1) avg (Worst: O(n)) |
| Delete   |  clear()              | O(n)                   |
| Search   |  find()               | O(1) avg (Worst: O(n)) |
| Search   |  count()              | O(1) avg (Worst: O(n)) |
| Capacity |  size()               | O(1)                   |
| Capacity |  empty()              | O(1)                   |

STACK
| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Insert   |  push()               | O(1)       |
| Delete   |  pop()                | O(1)       |
| Access   |  top()                | O(1)       |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |

QUEUE
| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Insert   |  push()               | O(1)       |
| Delete   |  pop()                | O(1)       |
| Access   |  front()              | O(1)       |
| Access   |  back()               | O(1)       |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |

PRIORITY_QUEUE
| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Insert   |  push()               | O(log n)   |
| Delete   |  pop()                | O(log n)   |
| Access   |  top()                | O(1)       |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |
| Heap     |  make_heap()          | O(n)       |
| Heap     |  push_heap()          | O(log n)   |
| Heap     |  pop_heap()           | O(log n)   |

STRING
| Type     | Operation / Algorithm | Complexity     |
| -------- | --------------------- | -------------- |
| Access   |  s[i]                 | O(1)           |
| Access   |  at()                 | O(1)           |
| Access   |  front()              | O(1)           |
| Access   |  back()               | O(1)           |
| Capacity |  size()               | O(1)           |
| Capacity |  length()             | O(1)           |
| Capacity |  empty()              | O(1)           |
| Insert   |  push_back()          | O(1) amortized |
| Delete   |  pop_back()           | O(1)           |
| Insert   |  append()             | O(n)           |
| Insert   |  operator+=           | O(n)           |
| Insert   |  insert()             | O(n)           |
| Delete   |  erase()              | O(n)           |
| Modify   |  replace()            | O(n)           |
| Utility  |  substr()             | O(k)           |
| Search   |  find()               | O(n)           |
| Search   |  rfind()              | O(n)           |
| Search   |  find_first_of()      | O(n)           |
| Search   |  find_last_of()       | O(n)           |
| Sorting  |  sort()               | O(n log n)     |
| Utility  |  reverse()            | O(n)           |

C++ Standard Library OTHER STL CONTAINERS & CONTAINER ADAPTERS
1️⃣ ARRAY
Internal Structure: Fixed Size Static Array
Header: #include<array>

Declaration: array<int,5> arr;

| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Access   |  arr[i]               | O(1)       |
| Access   |  arr.at(i)            | O(1)       |
| Access   |  front()              | O(1)       |
| Access   |  back()               | O(1)       |
| Access   |  data()               | O(1)       |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |
| Capacity |  max_size()           | O(1)       |
| Modify   |  fill()               | O(n)       |
| Utility  |  swap()               | O(n)       |
| Iterator |  begin()  /  end()    | O(1)       |
| Search   |  find()               | O(n)       |
| Search   |  count()              | O(n)       |
| Search   |  binary_search()      | O(log n)   |
| Search   |  lower_bound()        | O(log n)   |
| Search   |  upper_bound()        | O(log n)   |
| Sorting  |  sort()               | O(n log n) |
| Utility  |  reverse()            | O(n)       |

2️⃣ BITSET
Internal Structure: Compact Bit Array
Header: #include<bitset>
Declaration: bitset<8> bs;

| Type       | Operation / Algorithm | Complexity     |
| ---------- | --------------------- | -------------- |
| Access     |  bs[i]                | O(1)           |
| Modify     |  set()                | O(1)           |
| Modify     |  reset()              | O(1)           |
| Modify     |  flip()               | O(1)           |
| Search     |  any()                | O(n/word_size) |
| Search     |  none()               | O(n/word_size) |
| Search     |  all()                | O(n/word_size) |
| Count      |  count()              | O(n/word_size) |
| Utility    |  size()               | O(1)           |
| Utility    |  test()               | O(1)           |
| Conversion |  to_ulong()           | O(n)           |
| Conversion |  to_string()          | O(n)           |

3️⃣ UNORDERED_MULTISET
Internal Structure:Hash Table
Duplicates allowed.
Header:#include<unordered_set>
Declaration:unordered_multiset<int> ums;

| Type     | Operation / Algorithm | Complexity             |
| -------- | --------------------- | ---------------------- |
| Insert   |  insert()             | O(1) avg (Worst: O(n)) |
| Delete   |  erase()              | O(1) avg (Worst: O(n)) |
| Delete   |  clear()              | O(n)                   |
| Search   |  find()               | O(1) avg (Worst: O(n)) |
| Search   |  count()              | O(k) avg (Worst: O(n)) |
| Capacity |  size()               | O(1)                   |
| Capacity |  empty()              | O(1)                   |

k = duplicates count

4️⃣ UNORDERED_MULTIMAP
Internal Structure:Hash Table
Duplicate keys allowed.
Header:#include<unordered_map>
Declaration:unordered_multimap<int,int> umm;

| Type     | Operation / Algorithm | Complexity             |
| -------- | --------------------- | ---------------------- |
| Insert   |  insert()             | O(1) avg (Worst: O(n)) |
| Insert   |  emplace()            | O(1) avg (Worst: O(n)) |
| Delete   |  erase()              | O(1) avg (Worst: O(n)) |
| Delete   |  clear()              | O(n)                   |
| Search   |  find()               | O(1) avg (Worst: O(n)) |
| Search   |  count()              | O(k) avg (Worst: O(n)) |
| Capacity |  size()               | O(1)                   |
| Capacity |  empty()              | O(1)                   |

5️⃣ PAIR
Header:#include<utility>
Declaration:pair<int,int> p;

| Type    | Operation / Algorithm | Complexity |
| ------- | --------------------- | ---------- |
| Access  |  first                | O(1)       |
| Access  |  second               | O(1)       |
| Utility |  make_pair()          | O(1)       |
| Utility | comparison            | O(1)       |
| Utility |  swap()               | O(1)       |

6️⃣ TUPLE
Header:#include<tuple>
Declaration:tuple<int,int,string> t;

| Type    | Operation / Algorithm | Complexity |
| ------- | --------------------- | ---------- |
| Access  |  get<i>()             | O(1)       |
| Utility |  make_tuple()         | O(1)       |
| Utility | comparison            | O(k)       |
| Utility |  swap()               | O(k)       |

k = tuple size

7️⃣ VALARRAY
Internal Structure:Numeric Array Optimized for Math
Header:#include<valarray>
Declaration:valarray<int> va;

| Type    | Operation / Algorithm | Complexity |
| ------- | --------------------- | ---------- |
| Access  |  operator[]           | O(1)       |
| Access  |  size()               | O(1)       |
| Numeric |  sum()                | O(n)       |
| Numeric |  min()                | O(n)       |
| Numeric |  max()                | O(n)       |
| Numeric | arithmetic ops        | O(n)       |
| Utility |  resize()             | O(n)       |
| Utility |  swap()               | O(1)       |

8️⃣ SPAN (C++20)
Internal Structure:Non-owning Array View
Header:#include<span>
Declaration:span<int> sp(arr);

| Type     | Operation / Algorithm | Complexity |
| -------- | --------------------- | ---------- |
| Access   |  operator[]           | O(1)       |
| Access   |  front()              | O(1)       |
| Access   |  back()               | O(1)       |
| Access   |  data()               | O(1)       |
| Capacity |  size()               | O(1)       |
| Capacity |  empty()              | O(1)       |
| Utility  |  subspan()            | O(1)       |
| Iterator |  begin()  /  end()    | O(1)       |

🔥 IMPORTANT INTERVIEW NOTES
Container	        Internal DS
vector	            Dynamic Array
deque	            Segmented Array
list	            Doubly Linked List
forward_list	    Singly Linked List
set/map	            Red Black Tree
unordered_map/set	Hash Table
priority_queue	    Heap
stack	            Adapter
queue	            Adapter
bitset	            Compact Bit Array

🔥 CONTAINERS SUPPORTING RANDOM ACCESS
Container	Random Access
vector	    ✅ O(1)
deque	    ✅ O(1)
array	    ✅ O(1)
string	    ✅ O(1)
list	    ❌
set/map	    ❌

🔥 CONTAINERS SUPPORTING DUPLICATES
Container	            Duplicates
vector	                ✅
deque	                ✅
list	                ✅
multiset	            ✅
multimap	            ✅
unordered_multiset	    ✅
unordered_multimap	    ✅
set	                    ❌
map	                    ❌
*/
