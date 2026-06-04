#include<iostream>
#include<vector>
using namespace std;

vector<int> BuildArrayFromPermutationBrute(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n,0);
    for(int i{};i<n;++i){
        ans[i]=nums[nums[i]];
    }
    return ans;
}

vector<int> BuildArrayFromPermutationOptimal(vector<int>& nums){
    int n=nums.size();

    for(int i{};i<n;++i){
        nums[i]=nums[i]+n*(nums[nums[i]]%n);    //Why nums[nums[i]]%n explained later
    }

    for(int i{};i<n;++i){
        nums[i]=nums[i]/n;
    }
    return nums;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    vector<int> ansBr=BuildArrayFromPermutationBrute(nums);
    for(auto x:ansBr){
        cout<<x<<" ";
    }

    cout<<"\n";

    vector<int> ansOp=BuildArrayFromPermutationOptimal(nums);
    for(auto x:ansOp){
        cout<<x<<" ";
    }

}

/*
    // Encode old + new values
    for(int i = 0; i < n; ++i){
        nums[i] = nums[i] + n * (nums[nums[i]] % n);
    }

----------------------------------------
WHY nums[nums[i]] % n ?
----------------------------------------
Because nums[nums[i]] may already be encoded.
Example:
encoded = old + new*n
To get original value:
encoded % n
Without % n:
- you may use corrupted/modified value
- logic breaks

*/


/*
========================================
IN-PLACE ENCODING TRICK (IMPORTANT DSA PATTERN)
========================================
PURPOSE
-------
Used when:
1. We need to store BOTH old and new values
2. We want O(1) extra space
3. Array values are bounded:
   0 <= arr[i] < n

----------------------------------------
CORE IDEA
----------------------------------------
Store two values inside one integer.
Formula:
arr[i] = oldValue + newValue * n

Where:
- oldValue = original value
- newValue = value we want to store
- n = array size

----------------------------------------
HOW TO RECOVER VALUES
----------------------------------------
Recover OLD value: oldValue = arr[i] % n

Recover NEW value: newValue = arr[i] / n

----------------------------------------
WHY THIS WORKS
----------------------------------------
Because:
oldValue < n

So:
- remainder (% n) stores old value
- quotient (/ n) stores new value

Example:
n = 6
old = 2
new = 5

Encoded value:
arr[i] = 2 + 5*6
arr[i] = 32

Recover old:                Recover new:
32 % 6 = 2                  32 / 6 = 5

----------------------------------------
MOST IMPORTANT CONCEPT
----------------------------------------
During encoding, some array elements become modified.
So when accessing original values later:
USE: arr[index] % n

NOT: arr[index]
Otherwise you may accidentally use encoded value.
    
----------------------------------------
WHEN TO USE THIS TRICK
----------------------------------------

Use when:
- values are in range [0, n-1]
- need in-place transformation
- need O(1) extra space
- need to preserve old values temporarily

----------------------------------------
COMMON PROBLEMS USING THIS
----------------------------------------

1. Build Array From Permutation
2. Frequency Counting
3. Duplicate Detection
4. Cyclic Array Transformations
5. Hashing Without Extra Space
6. Matrix Encoding Problems
7. Index Mapping Problems

----------------------------------------
TIME & SPACE COMPLEXITY
----------------------------------------
Time:
O(n)

Extra Space:
O(1)

----------------------------------------
RECOGNITION PATTERN
----------------------------------------
If problem says:
- values are from 0 to n-1
- modify array in-place
- preserve old values

Think:
"Can I encode two values in one integer?"

========================================
*/
