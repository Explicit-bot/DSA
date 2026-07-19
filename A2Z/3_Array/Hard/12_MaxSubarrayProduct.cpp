#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MaxSubarrProductBrute(vector<int>& nums){
    int n=nums.size();
    int maxpd{INT_MIN};
    for(int i{};i<n;++i){
        for(int j{i};j<n;++j){
            int prod{1};
            for(int k{i};k<=j;++k){
                prod*=nums[k];
            }
            maxpd=max(maxpd,prod);
        }
    }
    return maxpd;
}

int MaxSubarrProductBetter(vector<int>& nums){
    int n=nums.size();
    int maxpd{INT_MIN};
    for(int i{};i<n;++i){
        int prod{1};
        for(int j{i};j<n;++j){
            prod*=nums[j];
            maxpd=max(maxpd,prod);
        }
    }
    return maxpd;
}

int MaxSubarrProductOptimal1(vector<int>& nums){
    int n=nums.size();
    int maxpd{INT_MIN};
    int prefix{1};
    int suffix{1};
    
    for(int i{};i<n;++i){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;

        prefix*=nums[i];
        suffix*=nums[n-i-1];
        
        maxpd=max(maxpd,max(prefix,suffix));
    }
    return maxpd;
}

//Kadane's
int MaxSubarrProductOptimal2(vector<int>& nums){
    int currMax{nums[0]};
    int currMin{nums[0]};
    int ans{nums[0]};

    for(int i = 1; i < nums.size(); ++i){
        // If current element is negative,
        // max and min swap roles
        if(nums[i] < 0){
            swap(currMax, currMin);
        }

        // Maximum product ending at current index
        currMax = max(nums[i],currMax * nums[i]);

        // Minimum product ending at current index
        currMin = min(nums[i],currMin * nums[i]);

        // Global maximum product
        ans = max(ans, currMax);
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

    cout<<MaxSubarrProductBrute(nums)<<"\n";
    cout<<MaxSubarrProductBetter(nums)<<"\n";
    cout<<MaxSubarrProductOptimal1(nums)<<"\n";
    cout<<MaxSubarrProductOptimal2(nums)<<"\n";
    
}

/*
CORE INTUITION OF THE OPTIMAL SOLUTION
We traverse the array in two directions:
1. Left -> Right
2. Right -> Left
while continuously maintaining a running product.

--------------------------------------------------
WHY TWO TRAVERSALS?
If the array contains an odd number of negative elements,
one negative element must be excluded to obtain the
maximum positive product.
That excluded negative element could be:
1. The leftmost negative element
OR
2. The rightmost negative element

Therefore:
- Left to Right traversal handles cases where
  prefix negatives are excluded.
- Right to Left traversal handles cases where
  suffix negatives are excluded.

--------------------------------------------------
ALGORITHM STEPS
1. Initialize:
prod = 1
maxProd = INT_MIN

--------------------------------------------------

2. Traverse from Left to Right:
- Multiply current element into prod
- Update maxProd
- If prod becomes 0:
      reset prod = 1

--------------------------------------------------

3. Traverse from Right to Left:
- Repeat the same process

--------------------------------------------------

4. Return maxProd

--------------------------------------------------

MATHEMATICAL IDEA
Running Product:
prod = prod * nums[i]

--------------------------------------------------

Reset Condition:
if(prod == 0)
    prod = 1;

--------------------------------------------------

WHY RESET ON ZERO?
A zero destroys the entire product chain because:
x * 0 = 0
So after encountering zero,
we restart the product calculation.

--------------------------------------------------

TIME COMPLEXITY
O(n)

--------------------------------------------------

SPACE COMPLEXITY
O(1)

--------------------------------------------------

MOST IMPORTANT INSIGHT
For Maximum Product Subarray:
- Sum problems only care about magnitude.
- Product problems care about:
    1. Magnitude
    2. Sign

Negative numbers can completely change
the final result because:

Negative * Negative = Positive
*/
