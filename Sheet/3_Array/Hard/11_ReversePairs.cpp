#include<iostream>
#include<vector>
using namespace std;

int ReversePairsBrute(vector<int>& nums){
    int n=nums.size();
    int cnt{};
    for(int i{};i<n;++i){
        for(int j{i+1};j<n;++j){
            if(2ll*(nums[j])<nums[i]){
                ++cnt;
            }
        }
    }
    return cnt;

}

//Optimal
int CountPairs(vector<int>& nums,int l,int mid,int h){
    int right{mid+1};
    int cnt{};
    for(int i{l};i<=mid;++i){
        while(right<=h && nums[i]>2ll*nums[right]){
            ++right;
        }
        cnt+=right-(mid+1);
    }

    return cnt;
}

void merge(vector<int>& nums,int l,int mid ,int h){
    int left{l};
    int right{mid+1};
    vector<int> ans;
    while(left<=mid && right<=h){
        if(nums[left]<=nums[right]){
            ans.push_back(nums[left]);
            ++left;
        }
        else{
            ans.push_back(nums[right]);
            ++right;
        }
    }

    while(left<=mid){
        ans.push_back(nums[left]);
        ++left;
    }

    while(right<=h){
        ans.push_back(nums[right]);
        ++right;
    }

    for(int i = l; i <= h; ++i){
        nums[i] = ans[i - l];
    }

}

int mergesort(vector<int>& nums,int l,int h){
    int cnt{};
    if(l>=h){
        return cnt;
    }

    int mid=(l+h)/2;
    cnt+=mergesort(nums,l,mid);
    cnt+=mergesort(nums,mid+1,h);
    cnt+=CountPairs(nums,l,mid,h);
    merge(nums,l,mid,h);

    return cnt;
}

int ReversePairsOptimal(vector<int>& nums){
    int n=nums.size();
    return mergesort(nums,0,n-1);
}


int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    cout<<ReversePairsBrute(nums)<<"\n";
    cout<<ReversePairsOptimal(nums)<<"\n";

}

/*
REVERSE PAIRS — OPTIMAL APPROACH (MERGE SORT)

--------------------------------------------------
PROBLEM STATEMENT

Count the number of reverse pairs in an array.

A reverse pair is defined as:

nums[i] > 2 * nums[j]

where:

i < j

--------------------------------------------------
CORE IDEA

Brute force checks every pair:

(i, j)

which takes:

O(n²)

To optimize, we use:

MERGE SORT + TWO POINTERS

--------------------------------------------------
WHY MERGE SORT?

Merge sort divides the array into:

1. Left Half
2. Right Half

After recursive calls:

Both halves become sorted.

Sorted halves allow efficient pair counting.

--------------------------------------------------
MAIN OBSERVATION

Suppose:

Left Half  = [l ... mid]
Right Half = [mid+1 ... h]

Both are already sorted.

For every element in left half:

nums[i]

we need to count elements in right half satisfying:

nums[i] > 2 * nums[right]

--------------------------------------------------
TWO POINTER TECHNIQUE

Initialize:

right = mid + 1

For every left element:

while(right <= h &&
      nums[i] > 2LL * nums[right]){

    right++;
}

All elements before 'right'
satisfy the condition.

Count added:

right - (mid + 1)

--------------------------------------------------
WHY RIGHT POINTER IS NEVER RESET

Both halves are sorted.

If current left element fails for some 'right',
future left elements will be:

greater or equal

Therefore:

right pointer only moves forward.

This makes counting linear.

--------------------------------------------------
ALGORITHM STEPS

1. Divide array into two halves
2. Recursively sort left half
3. Recursively sort right half
4. Count reverse pairs between halves
5. Merge both sorted halves

--------------------------------------------------
COUNTING MUST HAPPEN BEFORE MERGING

Why?

Because counting requires:

- left half sorted
- right half sorted
- halves still separate

After merging,
this structure disappears.

--------------------------------------------------
MERGE STEP

Use standard merge-sort merging:

- Compare elements
- Store in temporary array
- Copy back to original array

--------------------------------------------------
OVERFLOW HANDLING

Use:

2LL * nums[right]

instead of:

2 * nums[right]

Why?

Because multiplication may overflow int range.

2LL forces long long arithmetic.

--------------------------------------------------
TIME COMPLEXITY

Merge Sort Recurrence:

T(n) = 2T(n/2) + O(n)

Therefore:

O(n log n)

--------------------------------------------------
SPACE COMPLEXITY

Temporary merge array:

O(n)

Recursion stack:

O(log n)

Total Auxiliary Space:

O(n)

--------------------------------------------------
MOST IMPORTANT INSIGHT

This problem belongs to the pattern:

"Counting pairs using sorted halves"

Important related problems:

1. Inversion Count
2. Reverse Pairs
3. Count Smaller After Self
4. Count Range Sum

Common Technique:

Merge Sort + Two Pointers
*/
