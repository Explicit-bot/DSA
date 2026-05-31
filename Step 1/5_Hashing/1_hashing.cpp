/*
########################## HASHING ####################################
=======================================================================
1. WHY HASHING EXISTS
=======================================================================

Arrays are extremely fast because they allow:

arr[index]

direct memory access.

Time Complexity:
O(1)

BUT arrays have a limitation:

✔ Indices must be integers.

You CANNOT do:

arr["Naman"]

because strings are not valid array indices.

So we need a way to convert:
"complex keys" → integers

That process is called:

# HASHING




=======================================================================
2. WHAT IS HASHING?
=======================================================================

Hashing means:

Converting a key into an integer using a hash function.

Example:

"Naman" -> 87234612
"Rahul" -> 12987312

The generated integer is called:

# Hash Value

Main Goal:
✔ Fast insertion
✔ Fast searching
✔ Fast deletion

Average Complexity:
O(1)




=======================================================================
3. HASH FUNCTION
=======================================================================

A hash function is an algorithm that converts:

KEY -> INTEGER

Conceptually:

hash(key)

Example:

hash("Naman") = 87234612

Properties of a GOOD hash function:

1. Fast
2. Deterministic
3. Uniform distribution
4. Low collisions

IMPORTANT:
Same input must ALWAYS generate same hash
during execution.




=======================================================================
4. HASH TABLE
=======================================================================

A hash table is basically:

ARRAY + HASH FUNCTION

Internally contains:

# BUCKETS

Hash table workflow:

Key
 ↓
Hash Function
 ↓
Hash Value
 ↓
Bucket Index
 ↓
Store/Search element




=======================================================================
5. WHAT IS A BUCKET?
=======================================================================

A bucket is:

One storage slot/container inside the hash table.

Conceptually:

Bucket 0
Bucket 1
Bucket 2
Bucket 3
Bucket 4

Internally this is basically an array.

Think:

bucket[0]
bucket[1]
bucket[2]

etc.

Buckets store actual elements.




=======================================================================
6. HOW BUCKET IS CHOSEN
=======================================================================

Step 1:
Compute hash value.

Example:

hash("Naman") = 87234612

Step 2:
Compress into valid bucket index.

Formula:

bucket_index = hash(key) % bucket_count

Example:

87234612 % 5 = 2

So:

"Naman" goes to Bucket 2




=======================================================================
7. COMPLETE INTERNAL FLOW
=======================================================================

unordered_map<string,int> mp;

mp["Naman"] = 10;

Internally:

"Naman"
   ↓
Hash Function
   ↓
87234612
   ↓
% bucket_count
   ↓
Bucket 2
   ↓
Store ("Naman",10)




=======================================================================
8. WHAT IS COLLISION?
=======================================================================

Collision occurs when:

Different keys map to same bucket.

Example:

hash(15)%5 = 2
hash(25)%5 = 2

Both want Bucket 2.

This is called:

# COLLISION

IMPORTANT:
Collision means:

Different keys
Same bucket

NOT:
Same keys




=======================================================================
9. WHY COLLISIONS ARE UNAVOIDABLE
=======================================================================

Because:

✔ Huge number of possible keys
✔ Finite number of buckets

Eventually:
Multiple keys MUST share buckets.

This is related to:

# PIGEONHOLE PRINCIPLE




=======================================================================
10. GOALS OF GOOD HASHING
=======================================================================

A good hash table tries to:

1. Minimize collisions
2. Spread keys uniformly
3. Keep operations near O(1)

Good distribution:

Bucket 0 -> few elements
Bucket 1 -> few elements
Bucket 2 -> few elements

Bad distribution:

Everything -> Bucket 2




=======================================================================
11. COLLISION RESOLUTION TECHNIQUES
=======================================================================

Collisions cannot be fully avoided.

So we must HANDLE them.

Two major approaches:

1. Chaining
2. Open Addressing




=======================================================================
12. CHAINING
=======================================================================

MOST COMMON collision handling method.

Used by most STL unordered_map implementations.

Idea:

Store all collided elements inside same bucket.

Example:

Bucket 2
   ↓
15
   ↓
25
   ↓
35

Usually implemented using:

✔ Linked Lists
✔ Dynamic containers




=======================================================================
13. INSERTION IN CHAINING
=======================================================================

Suppose:

hash(25)%5 = 2

Go to Bucket 2.

Add element to chain.

Example:

Bucket 2:
15 -> 25




=======================================================================
14. SEARCH IN CHAINING
=======================================================================

Search 35:

Step 1:
Find bucket.

hash(35)%5 = 2

Step 2:
Traverse chain.

15 -> not match
25 -> not match
35 -> found




=======================================================================
15. ADVANTAGES OF CHAINING
=======================================================================

✔ Simple implementation
✔ Easy insertion
✔ Flexible
✔ Handles high load factor better

Disadvantages:
❌ Extra memory for pointers
❌ Long chains reduce performance
❌ Cache inefficient




=======================================================================
16. OPEN ADDRESSING
=======================================================================

Alternative collision resolution technique.

Idea:

If bucket occupied,
find another empty bucket.

No linked lists used.

Everything stays inside main table.




=======================================================================
17. LINEAR PROBING
=======================================================================

Simplest open addressing method.

If bucket occupied:

Try next bucket.

Example:

Bucket 2 occupied
→ Try 3
→ Try 4
→ Try 5

until empty bucket found.




=======================================================================
18. PROBLEM WITH LINEAR PROBING
=======================================================================

# PRIMARY CLUSTERING

Large consecutive occupied regions form.

Example:

2 3 4 5 6 occupied

Future collisions become worse.




=======================================================================
19. QUADRATIC PROBING
=======================================================================

Instead of:

+1 +1 +1

Use:

+1² +2² +3²

Better spreading.
Less clustering.




=======================================================================
20. DOUBLE HASHING
=======================================================================

Uses second hash function for jumps.

Formula:

index = (h1(key) + i*h2(key)) % m

Very powerful probing method.




=======================================================================
21. CHAINING vs OPEN ADDRESSING
=======================================================================

                 CHAINING        OPEN ADDRESSING
---------------------------------------------------------
Memory           More            Less
Cache Locality   Worse           Better
Deletion         Easier          Harder
Load Handling    Better          Worse
STL Use          Usually Yes     Usually No




=======================================================================
22. LOAD FACTOR
=======================================================================

Formula:

Load Factor = Number of Elements / Number of Buckets

Example:

100 elements
10 buckets

Load Factor = 10

High load factor means:

✔ More collisions
✔ Longer chains
✔ Worse performance




=======================================================================
23. REHASHING
=======================================================================

When load factor becomes too high:

Hash table creates:
✔ Bigger bucket array
✔ Recomputes bucket positions
✔ Redistributes elements

This is called:

# REHASHING

unordered_map does this automatically.




=======================================================================
24. WHY PRIME NUMBERS ARE USED
=======================================================================

Many hash tables use prime numbers for:

✔ Bucket counts
✔ Hash multipliers

Reason:
Better distribution
Less repetitive patterns
Reduced clustering




=======================================================================
25. SIMPLE STRING HASHING IDEA
=======================================================================

Characters have ASCII values.

Example:

'N' = 78
'a' = 97

Naive hash:

Sum of ASCII values.

"Naman"

= 78+97+109+97+110
= 491




=======================================================================
26. PROBLEM WITH SIMPLE HASHING
=======================================================================

"abc"
"cab"

can produce same sum.

Collision.

Bad distribution.

Real hash functions are MUCH smarter.




=======================================================================
27. POLYNOMIAL ROLLING HASH
=======================================================================

Common advanced string hashing technique.

Conceptually:

hash(s) =
s0*p^0 + s1*p^1 + s2*p^2 + ...

where:
✔ s0,s1... = character values
✔ p = prime number

Advantages:
✔ Order matters
✔ Better distribution
✔ Fewer collisions




=======================================================================
28. WHAT MAKES A GOOD HASH FUNCTION?
=======================================================================

A good hash function should:

1. Be fast
2. Minimize collisions
3. Spread uniformly
4. Avoid clustering
5. Be deterministic

Bad hash function example:

hash(string s) = s.length()

Problem:
All same-length strings collide.




=======================================================================
29. WHY DIFFERENT COMPILERS USE DIFFERENT HASHES
=======================================================================

C++ standard defines:

✔ Behavior
NOT:
✔ Exact implementation

Different compilers use different STL libraries.

Examples:

GCC    -> libstdc++
Clang  -> libc++
MSVC   -> Microsoft STL

Each implementation may use:
✔ Different hash functions
✔ Different optimizations
✔ Different bucket strategies




=======================================================================
30. 32-bit vs 64-bit SYSTEMS
=======================================================================

Hash outputs often use:

size_t

Usually:

32-bit system -> 32-bit size_t
64-bit system -> 64-bit size_t

So hash values may differ across systems.




=======================================================================
31. HASH COLLISION ATTACKS
=======================================================================

Attackers may intentionally generate:

Many colliding keys.

Result:

✔ Huge chains
✔ O(n) behavior
✔ Server slowdown

This is called:

# HASH DOS ATTACK

Modern systems use:
✔ Better hashes
✔ Randomization
✔ Security improvements




=======================================================================
32. IMPORTANT HASHING GUARANTEE
=======================================================================

C++ guarantees:

If:

a == b

then:

hash(a) == hash(b)

MUST be true.

BUT:

Different keys may STILL produce same hash.




=======================================================================
33. COMPLEXITY OF unordered_map
=======================================================================

AVERAGE CASE:

Insert  -> O(1)
Search  -> O(1)
Delete  -> O(1)

WORST CASE:

O(n)

when too many collisions occur.




=======================================================================
34. unordered_map vs map
=======================================================================

                unordered_map         map
-------------------------------------------------------
Internal DS     Hash Table            Red-Black Tree
Ordering        Unordered             Sorted
Average Search  O(1)                  O(log n)
Worst Search    O(n)                  O(log n)
Collisions      Yes                   No




=======================================================================
35. CUSTOM HASH FUNCTIONS
=======================================================================

Sometimes default hashing is not enough.

Reasons:
✔ Custom structs/classes
✔ Better performance
✔ Reduce collision attacks
✔ Competitive programming

Example:

struct MyHash {
    size_t operator()(string s) const {
        return s.length();
    }
};

Usage:

unordered_map<string,int,MyHash> mp;

IMPORTANT:
Above hash function is BAD because:

All same-length strings collide.




=======================================================================
36. CUSTOM HASH FOR pair<int,int>
=======================================================================

Very common in CP.

Example:

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return p.first ^ (p.second << 1);
    }
};

Usage:

unordered_map<pair<int,int>,int,PairHash> mp;

Concepts Used:

^   -> XOR
<<  -> Left Shift

Used for:
✔ Bit mixing
✔ Better distribution




=======================================================================
37. splitmix64 (ADVANCED HASH)
=======================================================================

Very popular advanced competitive programming hash.

Used to reduce hacking/collision attacks.


struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {

        x += 0x9e3779b97f4a7c15;

        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;

        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {

        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();

        return splitmix64(x + FIXED_RANDOM);
    }
};

Usage:

unordered_map<long long,int,custom_hash> mp;

Advantages:
✔ Better distribution
✔ Harder to hack
✔ Reduces worst-case collisions
✔ Popular in competitive programming




=======================================================================
38. STRING -> INTEGER COMPRESSION
=======================================================================

Very common optimization.

Idea:

Convert strings into compact integer IDs.

Example:


unordered_map<string,int> id;


id["Delhi"]  = 0;
id["Mumbai"] = 1;
id["Jaipur"] = 2;

Now arrays/vectors can be used efficiently:

vector<int> arr(3);

Advantages:
✔ Faster indexing
✔ Less memory
✔ Better cache locality
✔ Useful in graphs & DP




=======================================================================
39. REAL-WORLD APPLICATIONS OF HASHING
=======================================================================

Hashing is heavily used in:

✔ Databases
✔ Search Engines
✔ Caches
✔ Compilers
✔ Social Media
✔ Gaming Systems
✔ Web Servers
✔ NLP Systems
✔ Competitive Programming
✔ Graph Systems




=======================================================================
40. FINAL MENTAL MODEL
=======================================================================

A hash table is:

ARRAY OF BUCKETS

Workflow:

Key
 ↓
Hash Function
 ↓
Hash Value
 ↓
Bucket Index
 ↓
Store/Search in Bucket

Collision:
Different keys -> Same bucket

Handled using:
✔ Chaining
✔ Open Addressing

Main Goal:
Keep operations near O(1)

=======================================================================
39. HOW NUMBER OF BUCKETS IS DECIDED
=======================================================================

Hash tables dynamically decide bucket count based on:

1. Number of elements
2. Load factor
3. Performance requirements
4. STL implementation strategy

IMPORTANT:

Bucket count is NOT equal to number of elements.

Example:

10 elements
31 buckets

perfectly normal.

Main goal:

✔ Reduce collisions
✔ Maintain near O(1) performance
✔ Balance speed and memory


=======================================================================
40. INITIAL BUCKET COUNT
=======================================================================

When we create:

unordered_map<int,int> mp;

STL internally creates:

some initial bucket array.

Maybe:
✔ 8 buckets
✔ 16 buckets
✔ 11 buckets

depending on implementation.

You can check bucket count:

mp.bucket_count();


=======================================================================
41. WHY NOT CREATE HUGE NUMBER OF BUCKETS?
=======================================================================

Because buckets consume memory.

Example:

1000000 empty buckets

would waste huge memory if:

only 5 elements exist.

So hash tables balance:

✔ Memory usage
✔ Collision reduction


=======================================================================
42. LOAD FACTOR
=======================================================================

Formula:

Load Factor = Number of Elements / Number of Buckets

Example:

100 elements
10 buckets

Load Factor = 10

Meaning:

Average 10 elements per bucket.

Higher load factor means:

✔ More collisions
✔ Longer chains
✔ Worse performance


=======================================================================
43. WHAT HAPPENS WHEN LOAD FACTOR INCREASES?
=======================================================================

As load factor grows:

✔ Collisions increase
✔ Chains become longer
✔ Searching slows down

Performance starts degrading from:

O(1)

toward:

O(n)

So hash table increases bucket count.


=======================================================================
44. REHASHING
=======================================================================

When load factor becomes too high:

Hash table:

1. Creates bigger bucket array
2. Recomputes bucket positions
3. Redistributes all elements

This process is called:

# REHASHING

unordered_map performs this automatically.


=======================================================================
45. WHY ELEMENTS MUST BE REDISTRIBUTED
=======================================================================

Bucket formula:

bucket = hash(key) % bucket_count

If bucket_count changes:

bucket index changes.

Example:

Old:
hash(key)%5

New:
hash(key)%11

So ALL bucket positions change.

That is why rehashing must move all elements.


=======================================================================
46. max_load_factor
=======================================================================

unordered_map internally maintains:

max_load_factor

You can check it:

mp.max_load_factor();

Usually near:

1.0

Meaning:

About 1 element per bucket on average.

When exceeded:

rehashing may occur.


=======================================================================
47. reserve() AND rehash()
=======================================================================

reserve(n)
-----------

Prepares enough buckets for approximately n elements.

Example:

mp.reserve(1000);

Advantages:

✔ Reduces repeated rehashing
✔ Improves performance


rehash(n)
----------

Forces at least n buckets.

Example:

mp.rehash(200);

Useful for manual bucket control.


=======================================================================
48. WHY PRIME NUMBERS ARE USED FOR BUCKETS
=======================================================================

Many implementations use:

prime bucket counts.

Examples:

5
11
23
47

instead of:

8
16
32

Reason:

✔ Better distribution
✔ Reduced clustering
✔ Fewer repetitive patterns


=======================================================================
49. EFFECT OF MORE BUCKETS
=======================================================================

More buckets:

✔ Fewer collisions
✔ Shorter chains
✔ Faster lookup

BUT:

❌ More memory usage

Hash tables constantly balance:

speed vs memory


=======================================================================
50. REHASHING COST
=======================================================================

Rehashing is expensive because:

ALL elements must be moved.

Complexity approximately:

O(n)

BUT:

Since rehashing happens occasionally,
average insertion complexity still remains:

O(1) amortized


=======================================================================
51. REAL ANALOGY FOR BUCKET COUNT
=======================================================================

Suppose:

Buckets = classrooms
Elements = students

Case 1:

100 students
5 classrooms

Very crowded.

Case 2:

100 students
100 classrooms

Very wasteful.

Ideal balance:

reasonable distribution.


=======================================================================
52. FINAL BUCKET COUNT INTUITION
=======================================================================

Bucket count is dynamically adjusted based on:

✔ Number of elements
✔ Load factor
✔ Collision rate
✔ STL implementation strategy

using:

# REHASHING

to maintain near O(1) performance.

/*
=======================================================================
37. DOES REHASHING TAKE TIME?
=======================================================================

YES.

Rehashing is expensive.

It is one of the major hidden costs in hash tables.

Rehashing usually occurs when:

✔ Load factor becomes too high
✔ Too many collisions occur
✔ Performance starts degrading

Main goal of rehashing:

✔ Reduce collisions
✔ Maintain near O(1) operations
*/


/*
=======================================================================
38. WHAT HAPPENS DURING REHASHING?
=======================================================================

Suppose:

Old bucket count:
5

New bucket count:
11

Now EVERY existing element must be:

1. Visited
2. Hashed again
3. Assigned new bucket
4. Moved

Because bucket formula depends on:

bucket = hash(key) % bucket_count

If bucket_count changes:

✔ Bucket indices change
✔ Elements must move
*/


/*
=======================================================================
39. WHY ALL ELEMENTS MUST MOVE
=======================================================================

Example:

hash(25) = 47

Old bucket:

47 % 5 = 2

New bucket:

47 % 11 = 3

Bucket position changed.

So element must be relocated.

This happens for ALL existing elements.
*/


/*
=======================================================================
40. TIME COMPLEXITY OF REHASHING
=======================================================================

Suppose:

n elements exist.

During rehashing:

ALL n elements must be processed.

Complexity:

O(n)

because every element is reinserted/repositioned.
*/


/*
=======================================================================
41. THEN WHY IS unordered_map STILL O(1)?
=======================================================================

Because rehashing does NOT happen every insertion.

Most insertions are:

✔ Very cheap
✔ O(1)

Only occasional insertions trigger:

✔ Expensive O(n) rehashing

Average complexity across operations remains:

# O(1) AMORTIZED
*/


/*
=======================================================================
42. AMORTIZED ANALYSIS
=======================================================================

Suppose insertions:

1 2 3 4 5 6 7 ...

Most insertions:

✔ Cheap
✔ Constant time

Occasionally:

✔ Large expensive rehash occurs

Average cost over many operations remains small.

This concept is called:

# AMORTIZED ANALYSIS

Same idea is used in:

✔ vector resizing
✔ dynamic arrays
✔ hash tables
*/


/*
=======================================================================
43. WORST CASE INSERTION
=======================================================================

Normal insertion:

O(1)

BUT:

Insertion that triggers rehashing may become:

O(n)

because ALL existing elements must move.

Very important interview concept.
*/


/*
=======================================================================
44. reserve() HELPS REDUCE REHASHING
=======================================================================

If approximate element count is known beforehand:

Use:

mp.reserve(n);

Example:

mp.reserve(100000);

Advantages:

✔ Fewer rehashes
✔ Faster insertions
✔ Less memory movement
✔ Better performance
*/


/*
=======================================================================
45. REHASHING ALSO INVALIDATES ITERATORS
=======================================================================

Since elements move internally:

✔ Iterators may become invalid
✔ References may become invalid
✔ Pointers may become invalid

Example:

auto it = mp.begin();

mp.rehash(100);

Now:
it may be invalid.

Very important STL behavior.
*/


/*
=======================================================================
46. REAL ANALOGY FOR REHASHING
=======================================================================

Suppose:

Buckets = classrooms
Elements = students

Initially:

5 classrooms

Too crowded.

School creates:

20 classrooms

Now ALL students must:

✔ Leave old rooms
✔ Get reassigned
✔ Move to new rooms

That reassignment process is:

# REHASHING
*/


/*
=======================================================================
47. FINAL REHASHING SUMMARY
=======================================================================

Normal insertion:
O(1)

Insertion triggering rehash:
O(n)

Full rehashing:
O(n)

BUT:

Overall average complexity remains:

# O(1) AMORTIZED

because rehashing happens occasionally,
NOT every operation.
=======================================================================
*/
