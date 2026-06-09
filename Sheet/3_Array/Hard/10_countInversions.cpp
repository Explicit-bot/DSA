#include<iostream>
#include<vector>
using namespace std;

int CountInversionBrute(const vector<int>& nums){
    int n=nums.size();
    int cnt{};
    for(int i{};i<n;++i){
        for(int j{i};j<n;++j){
            if(nums[j]<nums[i]){
                ++cnt;
            }
        }
    }
    return cnt;
}

//Optimal
int merge(vector<int>& nums,int l,int mid ,int h){
    int cnt{};
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
            cnt+=mid-left+1;    //*****
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

    return cnt;
}

int mergesort(vector<int>& nums,int l,int h){
    int cnt{};
    if(l>=h){
        return cnt;
    }

    int mid=(l+h)/2;
    cnt+=mergesort(nums,l,mid);
    cnt+=mergesort(nums,mid+1,h);
    cnt+=merge(nums,l,mid,h);

    return cnt;
}

int CountInversionOptimal(vector<int>& nums){
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

    cout<<CountInversionBrute(nums)<<"\n";
    cout<<CountInversionOptimal(nums)<<"\n";
    
}

/*
COUNT INVERSIONS — OPTIMAL APPROACH (MERGE SORT)

--------------------------------------------------
PROBLEM STATEMENT

Count the number of inversions in an array.

An inversion is defined as:

nums[i] > nums[j]

where:

i < j

--------------------------------------------------
EXAMPLE

Array:

[5, 3, 2, 4, 1]

Inversions:

(5,3)
(5,2)
(5,4)
(5,1)
(3,2)
(3,1)
(2,1)
(4,1)

Total Inversions = 8

--------------------------------------------------
BRUTE FORCE APPROACH

Check every pair:

(i, j)

where:

i < j

If:

nums[i] > nums[j]

increment count.

--------------------------------------------------
BRUTE FORCE COMPLEXITY

Two nested loops:

O(n²)

--------------------------------------------------
OPTIMAL APPROACH

Use:

MERGE SORT

--------------------------------------------------
WHY MERGE SORT?

Merge sort divides the array into:

1. Left Half
2. Right Half

After recursive calls:

Both halves become sorted.

While merging sorted halves,
we can efficiently count inversions.

--------------------------------------------------
MAIN OBSERVATION

Suppose:

Left Half  = [l ... mid]
Right Half = [mid+1 ... h]

Both halves are already sorted.

During merge step:

If:

nums[left] <= nums[right]

No inversion exists.

--------------------------------------------------
WHEN INVERSION OCCURS

If:

nums[left] > nums[right]

then inversion exists.

But since left half is sorted:

All remaining elements from:

left -> mid

will also be greater than:

nums[right]

Therefore:

Number of inversions added:

mid - left + 1

--------------------------------------------------
WHY?

Because:

nums[left]
nums[left+1]
nums[left+2]
...
nums[mid]

are all greater than:

nums[right]

and all indices satisfy:

i < j

--------------------------------------------------
COUNTING LOGIC

Inside merge step:

if(nums[left] > nums[right]){

    inversions += mid - left + 1;
}

--------------------------------------------------
ALGORITHM STEPS

1. Divide array into two halves
2. Recursively sort left half
3. Recursively sort right half
4. Count inversions during merge step
5. Merge both sorted halves

--------------------------------------------------
MERGE STEP

Use standard merge-sort merging:

- Compare elements
- Store smaller element
- Copy merged array back

--------------------------------------------------
IMPORTANT INSIGHT

Counting happens during merge.

Why?

Because:

- left half is sorted
- right half is sorted

This allows counting multiple inversions at once.

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

"Counting relationships using sorted halves"

Key idea:

Sorted subarrays allow efficient counting.

--------------------------------------------------
RELATED PROBLEMS

1. Inversion Count
2. Reverse Pairs
3. Count Smaller After Self
4. Count Range Sum

Common Technique:

Merge Sort + Counting During Merge

--------------------------------------------------
CORE DIFFERENCE FROM REVERSE PAIRS

Inversion Count Condition:

nums[i] > nums[j]

Reverse Pairs Condition:

nums[i] > 2 * nums[j]

In inversion count:

counting is directly integrated
inside merge step.

In reverse pairs:

counting is done BEFORE merge
using two pointers.
*/
