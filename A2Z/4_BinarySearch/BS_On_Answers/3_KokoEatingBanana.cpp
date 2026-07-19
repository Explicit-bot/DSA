#include<iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;

int totalHours(vector<int>& piles,int n){
    int totalhrs{};
    for(auto x:piles){
        totalhrs+=ceil(double(x)/n);
    }
    return totalhrs;
}

int BananasHrlyBrute(vector<int>& piles,int hrs){
    int maxval=*max_element(piles.begin(),piles.end());
    for(int i{1};i<maxval;++i){
        int k=totalHours(piles,i);
        if(k<=hrs){
            return i;
        }
    }
    return maxval;
}

int BananasHrlyOptimal(vector<int>& piles,int hrs){
    int maxval=*max_element(piles.begin(),piles.end());
    int l{1};
    int h{maxval};
    int ans{maxval};
    while(l<=h){
        int mid=l+(h-l)/2;
        int k=totalHours(piles,mid);
        if(k<=hrs){
            ans=mid;
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);
    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    int h{};
    cin>>h;

    cout<<BananasHrlyBrute(nums,h)<<"\n";
    cout<<BananasHrlyOptimal(nums,h)<<"\n";
}

/*
========================================================
KOKO EATING BANANAS (LeetCode 875)
BINARY SEARCH ON ANSWER
========================================================

PROBLEM
-------
Given piles of bananas and h hours,
find the minimum eating speed k such that
all bananas are eaten within h hours.

--------------------------------------------------------
OBSERVATION
--------------------------------------------------------

If speed = k works,
then every speed > k will also work.

Example:

Speed = 4 -> 10 hours ❌
Speed = 5 -> 8 hours ❌
Speed = 6 -> 6 hours ✅
Speed = 7 -> 5 hours ✅
Speed = 8 -> 5 hours ✅

Pattern:

FFFFTTTTT

This monotonic nature allows Binary Search.

--------------------------------------------------------
SEARCH SPACE
--------------------------------------------------------

Minimum possible speed = 1

Maximum possible speed = max(piles)

Therefore:

low  = 1
high = max(piles)

--------------------------------------------------------
CALCULATING HOURS
--------------------------------------------------------

For a pile of size x and speed k:

hours = ceil(x / k)

Example:

x = 10
k = 3

hours = ceil(10/3)
      = 4

--------------------------------------------------------
AVOID USING CEIL()
--------------------------------------------------------

Instead of:

ceil((double)x / k)

Use:

(x + k - 1) / k

Proof:

ceil(a/b) = (a+b-1)/b

Example:

10/3

(10+3-1)/3
= 12/3
= 4

--------------------------------------------------------
TOTAL HOURS FUNCTION
--------------------------------------------------------

long long totalHours(const vector<int>& piles,
                     int speed)
{
    long long hrs = 0;

    for(int x : piles)
    {
        hrs += (x + speed - 1) / speed;
    }

    return hrs;
}

--------------------------------------------------------
BINARY SEARCH LOGIC
--------------------------------------------------------

while(low <= high)
{
    mid = low + (high-low)/2;

    if(totalHours(piles, mid) <= h)
    {
        answer found
        try smaller speed

        high = mid - 1;
    }
    else
    {
        speed too slow
        need larger speed

        low = mid + 1;
    }
}

--------------------------------------------------------
WHY RETURN LOW?
--------------------------------------------------------

At the end:

high = last invalid speed

low  = first valid speed

Example:

Speed: 1 2 3 4 5 6 7
State: F F F F T T T

After binary search:

high -> 4
low  -> 5

Answer = 5

Therefore:

return low;

--------------------------------------------------------
COMPLETE OPTIMAL CODE
--------------------------------------------------------

class Solution {
public:

    long long totalHours(
        const vector<int>& piles,
        int speed)
    {
        long long hrs = 0;

        for(int x : piles)
        {
            hrs += (x + speed - 1) / speed;
        }

        return hrs;
    }

    int minEatingSpeed(
        vector<int>& piles,
        int h)
    {
        int low = 1;

        int high =
            *max_element(
                piles.begin(),
                piles.end());

        while(low <= high)
        {
            int mid =
                low + (high - low) / 2;

            if(totalHours(piles, mid) <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

Finding max element:
O(n)

Binary Search:
O(log(max(piles)))

Hours calculation:
O(n)

Total:

O(n * log(max(piles)))

--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(1)

--------------------------------------------------------
INTERVIEW PATTERN
--------------------------------------------------------

This exact Binary Search on Answer pattern is used in:

1. Koko Eating Bananas
2. Minimum Days to Make M Bouquets
3. Capacity To Ship Packages Within D Days
4. Allocate Books
5. Aggressive Cows
6. Painter's Partition Problem

Whenever you see:

"Find minimum/maximum value satisfying a condition"

Think:

✓ Binary Search on Answer

========================================================
TEMPLATE FOR MINIMUM VALID ANSWER
========================================================

int low = minimumPossibleAnswer;
int high = maximumPossibleAnswer;

while(low <= high)
{
    int mid = low + (high - low)/2;

    if(isValid(mid))
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }
}

return low;

========================================================
*/
