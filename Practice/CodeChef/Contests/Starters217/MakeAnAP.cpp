/*
====================================================
                MAKE AN AP
====================================================
Chef has a strictly increasing sequence A of length N.
He wants to convert it into an Arithmetic Progression (AP).

In one operation, Chef can choose any integer and insert it
anywhere in the array.

Your task is to find the minimum number of operations required
to convert the given array into an Arithmetic Progression.

It is guaranteed that the conversion is always possible
under the given constraints.

----------------------------------------------------
DEFINITION
----------------------------------------------------
A sequence A of length N is called an Arithmetic Progression
if the difference A[i] - A[i-1] is the same for all
1 ≤ i < N.

Examples:
[1, 3, 5, 7, 9]  → Arithmetic Progression
[3]             → Arithmetic Progression
[1, 5, 7, 9]    → Not an Arithmetic Progression

----------------------------------------------------
INPUT FORMAT
----------------------------------------------------
• The first line contains an integer T — number of test cases.
• For each test case:
  - The first line contains an integer N — size of the array.
  - The second line contains N integers A1, A2, ..., AN.

----------------------------------------------------
OUTPUT FORMAT
----------------------------------------------------
For each test case, output a single integer —
the minimum number of operations required.

----------------------------------------------------
CONSTRAINTS
----------------------------------------------------
1 ≤ T ≤ 100
2 ≤ N ≤ 100
1 ≤ Ai ≤ 10^9
A[i] < A[i+1]

====================================================

*/
