#include <iostream>
#include <vector>
using namespace std;

//Brute (O(N*N),O(1))
int MissingNumberBrute(vector<int>& nums,int N){
    for(int i{};i<=N;++i){
        int flag=0;
        for(int j{};j<N;++j){ 
            if(nums[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
}

//Better (O(N+N),O(N))
int MissingNumberBetter(vector <int>& nums,int N){
    vector<int> hash(N+1,0);
    for(auto x:nums){
        hash[x]++;
    }

    for(int i{};i<N+1;++i){
        if(hash[i]==0){
            return i;
        }
    }
}

//Optimal (Using Sum)   (O(N),O(1))
int MissingNumberOptimalSum(vector<int>& nums , int N){
    int sum=N*(N+1)/2;
    int numsum{};

    for(auto x:nums){
        numsum+=x;
    }

    return sum-numsum;
}

//Optimal (Using XOR)   (O(N),O(1))
int MissingNumberOptimalXOR(vector<int>& nums , int N){
    /*
    Two important properties of XOR are the following:
    XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
    XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a. ←Property 2
    */
   int xor1{},xor2{};
   for(int i{};i<=N;++i){
    xor1=xor1^i;
   }
   for(auto x:nums){
    xor2=xor2^x;
   }
   return xor1^xor2;
   
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n);
    for(auto &x:nums){
        cin>>x;
    }

    cout<<MissingNumberBrute(nums,n)<<"\n";
    cout<<MissingNumberBetter(nums,n)<<"\n";
    cout<<MissingNumberOptimalSum(nums,n)<<"\n";
    cout<<MissingNumberOptimalXOR(nums,n)<<"\n";
}
