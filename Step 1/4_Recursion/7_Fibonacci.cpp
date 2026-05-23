/*
***
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 
Constraints:
0 <= n <= 30
*/

#include <iostream>
#include <vector>
using namespace std;

//Brute force approach[TC- O(n)+O(n)  SC- O(n)]
vector<int> fibBrute(int n){
    vector<int> fib(n+1);
    fib[0]=0;
    if(n >= 1){
        fib[1] = 1;
    }

    for(int i{2};i<=n;++i){
        fib[i]=fib[i-1]+fib[i-2];
    }

    return fib;
}

//Better approach[TC- O(n)  SC- O(1)]
int fibBetter(int n){
    if(n<=1){
        return n;
    }
    int last{1};
    int slast{};
    int curr{};
    for(int i{2};i<=n;++i){
        curr=last+slast;
        slast=last;
        last=curr;
    }
    return curr;
}

//Optimal approach[TC- O(2^n)  SC- O(n)]
int fibrec(int n){
    if(n<=1){
        return n;
    }

    return fibrec(n-1)+fibrec(n-2);
}

int main(){
    int n{};
    cout<<"Enter your no.:";
    cin>>n;

    //Optimal approach using recursion
    cout<<"F[n]="<<fibrec(n)<<"\n";

    //Better approach
    cout<<"F[n]="<<fibBetter(n)<<"\n";

    //Brute approach 
    vector<int> fib=fibBrute(n);
    int i{};
    for(int x:fib){
        cout<<"fib["<<i<<"]="<<x<<"\n";
        ++i;
    }
}


/*
================ VECTOR =================
❌ WRONG:

vector<int> v;
v[0] = 10;

Reason:
- Vector is empty
- No index exists


✅ CORRECT:

vector<int> v(5);

Now indices:
0 to 4 exist


-----------------------------------------


❌ WRONG:

vector<int> v{5};

Result:
[5]

Size = 1


✅ CORRECT:

vector<int> v(5);

Result:
[0,0,0,0,0]

Size = 5


-----------------------------------------


vector<int> a(3,7);

Result:
[7,7,7]


vector<int> a{3,7};

Result:
[3,7]


-----------------------------------------


push_back() safely creates elements:

vector<int> v;

v.push_back(10);

Result:
[10]


================ FIBONACCI =================

❌ WRONG:

vector<int> fib{};

fib[0] = 0;
fib[1] = 1;

Reason:
- Vector empty


✅ CORRECT:

vector<int> fib(n+1);

fib[0] = 0;

if(n >= 1){
    fib[1] = 1;
}


================ ARRAYS =================

int arr[100];

Valid indices:
0 to 99


-----------------------------------------


❌ WRONG:

for(int i=0; i<=100; i++)


✅ CORRECT:

for(int i=0; i<100; i++)


================ VLA =================

int n;
cin >> n;

int arr[n];

This is Variable Length Array (VLA)

- Runtime-sized
- Not standard C++
- GCC may allow it


-----------------------------------------


❌ INVALID / NON-STANDARD:

int n = 5;

int arr[n] = {1,2,3,4,5};


✅ BETTER:

vector<int> arr(n);


-----------------------------------------


✅ VALID:

const int n = 5;

int arr[n];

Reason:
- compile-time constant


================ STATIC ARRAY =================

static int arr[5];

Meaning:
- Initialized once
- Survives function calls


-----------------------------------------


Normal local array:

int arr[5];

- Recreated every function call
- Destroyed after function ends


-----------------------------------------


static int arr[5];

Automatically:

{0,0,0,0,0}


================ RETURNING ARRAYS =================

❌ INVALID:

int[] fun()


-----------------------------------------


✅ RETURN POINTER:

int* fun(){

    static int arr[5] = {1,2,3,4,5};

    return arr;
}


-----------------------------------------


❌ DANGEROUS:

int* fun(){

    int arr[5];

    return arr;
}

Reason:
- Local array destroyed
- Dangling pointer


-----------------------------------------


✅ BEST MODERN WAY:

vector<int> fun(){

    vector<int> v = {1,2,3};

    return v;
}


================ ARRAY DECAY =================

void fun(int arr[])

Actually becomes:

void fun(int* arr)

Arrays decay into pointers.

*/
