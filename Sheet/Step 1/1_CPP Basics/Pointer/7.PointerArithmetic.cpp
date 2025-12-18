/*
Pointer Arithmetic :
Int A[5]={2,4,6,8,10}; 

Int *p=A;
Array and pointer is declared.
Pointer ‘*p’ is also assigned to Array ‘A’

    0   1   2   3   4
A   2   4   6   8   10

P 	 	 200
 

operations :
1.p++; //pointer will move forward to next index or location
2.p--; // pointer will move backward to previous index or location
3.p=p+2; //This will move pointer by 2 elements forward
4.p=p-2; // This will move pointer by 2 elements backward
5.d=q-p; //Assume it is another pointer lets q=206 and p=200
206-200=6/2=3 it will give index 3 value.

p + n means p + n × sizeof(datatype) →
 so it moves n × sizeof(datatype) bytes ahead in memory.
 Similarly for p-n also

 If p and q are pointers to elements in the same array, then:
p - q
gives the number of elements (not bytes) between the two pointers.

📌 Example:
#include <iostream>
int main() {
    int A[] = {10, 20, 30, 40, 50};

    int* p = &A[4]; // points to A[4] (50)
    int* q = &A[1]; // points to A[1] (20)

    std::cout << "p - q = " << (p - q) << '\n'; // Output: 3
    std::cout << "q - p = " << (q - p) << '\n'; // Output: -3

    return 0;
}
🧠 How it works:
p and q point to elements in the same array.
p - q returns the difference in element positions, not bytes.
So A[4] - A[1] = 4 - 1 = 3.

⚠️ Important:
- You can only safely subtract pointers that belong to the same array.
- Result is of type ptrdiff_t (a signed integral type).
- It’s undefined behavior if the pointers are not from the same array.

🔍 Real Use Case: Distance Between Elements

    int A[] = {5, 10, 15, 20};
    int* start = A;
    int* middle = &A[2];

    int distance = middle - start;  // ➝ 2 (elements between A[0] and A[2])



    int A[5] = {2, 4, 6, 8, 10};
    int* p = A;
    std::cout << p;



🔍 Explanation:
✅ int A[5] = {2, 4, 6, 8, 10};
This declares a static array of 5 integers.

✅ int* p = A;
This sets pointer p to point to the first element of array A.

Why does this work?
In C++, the name of an array (like A) decays into a pointer to its first element when used in expressions.
So p = A is equivalent to p = &A[0].

🖨️ What happens when you std::cout << p;?
It will not print the value at A[0].
It prints the memory address where the first element of the array is stored (because p is a pointer).

Example Output:
    0x61fe14
(Note: This value will differ every time you run the program, based on memory allocation.)

✅ To print actual array elements using p:

    std::cout << *p;       // prints 2
    std::cout << *(p + 1); // prints 4
    std::cout << p[2];     // prints 6

✅ Summary:
Expression	    Meaning         	        Output
p	            address of A[0]	            0x...
*p	            value at A[0]	            2
p[2]	        value at A[2]	            6
*(p + 3)	    value at A[3]	            8



int A[5] = {2, 4, 6, 8, 10};
int* p = A;
Here, p points to the first element of the array A.

🔢 Pointer Arithmetic — Explained Step-by-Step
🧠 What is pointer arithmetic?
Pointer arithmetic means performing operations like +, -, ++, -- on a pointer to move it through memory, especially arrays.

✅ Key Rule:
When you add 1 to an int* pointer, it doesn't increase by 1 byte, it moves forward by sizeof(int) bytes (usually 4 bytes).

🔍 Examples:

    std::cout << *p;       // prints 2 (value at A[0])
    std::cout << *(p + 1); // prints 4 (value at A[1])
    std::cout << *(p + 2); // prints 6 (value at A[2])
    std::cout << *(p + 3); // prints 8 (value at A[3])
    std::cout << *(p + 4); // prints 10 (value at A[4])
✅ Here, p + i moves the pointer to the i-th index, and *(p + i) gives the value there.

📈 Memory Visualization:
Index	Address	    A[i]	p + i	    *(p + i)
0	    0x1000	    2	    p	2
1	    0x1004	    4	    p + 1	        4
2	    0x1008	    6	    p + 2	        6
3	    0x100C	    8	    p + 3	        8
4	    0x1010	    10	    p + 4	        10

🧠 (Addresses are examples. Actual memory addresses may differ)

🔄 Loop with Pointer Arithmetic:

    for (int i = 0; i < 5; ++i) {
        std::cout << *(p + i) << " ";
    }
✅ This behaves the same as: std::cout << A[i];

🧠 Incrementing Pointer Itself:
    p++; // Now p points to A[1]
    std::cout << *p; // prints 4
✅ You are now directly modifying where p points to!

But remember:
 - Don't go out of bounds (p + i must stay within the array).
 - If you move p, you lose its original position unless you save it.

✅ Summary:
Operation	Meaning
p + i	    Move pointer i elements forward
*(p + i)	Get value at i-th position
p++ / ++p	Move to next element (like A[1], A[2], etc.)
p-- / --p	Move to previous element
*/
//Program to Demonstrate Pointer Arithmetic

#include <iostream>
using namespace std;
int main(){
    int A[5]={2,4,6,8,10};
    int *p=A,*q=&A[4];
    
    cout<<*p<<endl;
    cout<<endl;
    
    p++;
    cout<<*p<<endl;
    cout<<endl;
    
    p--;
    cout<<*p<<endl;
    cout<<endl;
    
    cout<<p<<endl;
    cout<<p+2<<endl;
    cout<<endl;
    
    cout<<*p<<endl;
    cout<<*(p+2)<<endl;
    cout<<endl;

    cout<<q<<endl;
    cout<<p<<endl;
    
    cout<<q-p<<endl;
    cout<<p-q<<endl;
    return 0;
}
/*
🔍 Example: Difference in Return Value
int A[] = {2, 4, 6};
int* p = A;

cout << *p++ << endl; // prints 2, then moves p to next element (4)
cout << *++p << endl; // moves p to 6, then prints 6
So:
*p++ → fetch value at p, then increment p
*++p → increment p, then fetch value
*/
