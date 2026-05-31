#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//Brute
bool linearSearch(vector<int>& a, int num) {
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}

int LongestConsSeqBrute(vector<int>& nums){
    int n=nums.size();
    int longest{1};
    for(int i{};i<n;++i){
        int x{nums[i]};
        int cnt=1;
        while(linearSearch(nums,x+1)==true){
            ++x;
            ++cnt;
        }
        longest=max(longest,cnt);
    }
    return longest;
}

int LongestConsSeqBetter(vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    if(n==0){
        return 0;
    }
    int longest{1};
    int cntCurr{1};
    int lastSmaller{nums[0]};
    for(int i{1};i<n;++i){
        if(lastSmaller+1==nums[i]){
            ++cntCurr;
            lastSmaller=nums[i];
        }
        else if(nums[i]>lastSmaller+1){
            
            lastSmaller=nums[i];
            cntCurr=1;
        }
        else if(nums[i]==lastSmaller){
            continue;
        }
        longest=max(longest,cntCurr);
    }
    return longest;
}

int LongestConsSeqOptimal(vector<int>& nums){

    int n = nums.size();

    if(n == 0){
        return 0;
    }

    unordered_set<int> st;

    for(int num : nums){
        st.insert(num);
    }

    int longest = 1;

    for(int num : st){

        if(st.find(num - 1) == st.end()){

            int currNum = num;

            int cntCurr = 1;

            while(st.find(currNum + 1) != st.end()){

                ++currNum;
                ++cntCurr;
            }

            longest = max(longest, cntCurr);
        }
    }

    return longest;
}
