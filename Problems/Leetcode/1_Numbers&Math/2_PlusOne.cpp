#include<iostream>
#include<vector>
using namespace std;

vector<int> PlusOneBrute(vector<int> nums){
    int n=nums.size();
    vector<int> digits{};

    int num{};
    for(auto x:nums){
        num=num*10 + x;
    }
    ++num;

    while(num>0){
        digits.push_back(num%10);
        num/=10;
    }
    reverse(digits.begin(),digits.end());

    return digits;
}

void PlusOneOptimal(vector<int>& nums){
    int n=nums.size();
    
    for(int i{n-1};i>=0;--i){
        if(nums[i]<9){
            ++nums[i];
            return ;
        }

        nums[i]=0;
    }

    nums.insert(nums.begin(),1);
}

int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    vector<int> digits=PlusOneBrute(nums);
    for(auto x:digits){
        cout<<x<<" ";
    }
    cout<<"\n";
    
    PlusOneOptimal(nums);
    for(auto x:nums){
        cout<<x<<" ";
    }
}
