#include<iostream>
using namespace std;

int numberOfSteps(int num) {
    int cnt{};
    while(num){
        if(num%2==0){
            num/=2;
        }
        else{
            --num;
        }
        ++cnt;
    }
    return cnt;
}

int numberOfStepsOptimal(int num){
    if (num == 0){
        return 0;
    }
    int setBits = __builtin_popcount(num);
    int bitLength = 32 - __builtin_clz(num);    //clz(0) UB.
    return setBits + bitLength - 1;
}

int main(){
    int n{};
    cin>>n;

    cout<<numberOfSteps(n)<<"\n";
    cout<<numberOfStepsOptimal(n)<<"\n";    
}

/*
Total operations= Number of divisions + Number of subtractions
                 = (Number of bits - 1) + (Number of set bits)

==========================================================
 GCC BUILT-IN FUNCTIONS
==========================================================
__builtin_popcount(num) - Returns number of set bits.
E.g:
1110₂
__builtin_popcount(14)
= 3

__builtin_clz(num) - Returns number of leading zeros.
E.g:
For a 32-bit integer:
num = 14
Binary: 00000000 00000000 00000000 00001110
Leading zeros = 28
Therefore:
Bit Length = 32 - __builtin_clz(num)

==========================================================
FOR OPTIMAL SOLUTION
==========================================================
TIME COMPLEXITY - O(1) (Built-in operations are constant time.)
SPACE COMPLEXITY - O(1)

for a number with b bits:
popcount() : O(b)
clz()      : O(b)
For int, b = 32 (constant), hence O(1).


Why?
Modern CPUs often have dedicated instructions for these operations:
POPCNT (Population Count): counts the number of 1's in a word.
LZCNT (Leading Zero Count) or BSR (Bit Scan Reverse): used to determine the number of leading zeros or the position of the highest set bit.

So a compiler may translate
    __builtin_popcount(num);   ->     POPCNT eax, edi
Similarly,
    __builtin_clz(num);     ->      LZCNT eax, edi
Because these instructions execute in a fixed number of CPU cycles,we treat them as O(1)
*/
