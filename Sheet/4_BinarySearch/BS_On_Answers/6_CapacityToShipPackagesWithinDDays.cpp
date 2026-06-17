#include<iostream>
#include<vector>
using namespace std;

int daysCalculator(vector<int>& weights, int w){
    int n=weights.size();
    int day{1};
    int load{};

    for(const auto& x:weights){
        if(load+x>w){
            ++day;
            load=x;
        }
        else{
            load+=x;
        }
    }
    return day;
}

int weightCalculator(vector<int>& weights,int days){
    int n=weights.size();
    int minval=*max_element(weights.begin(),weights.end());
    int maxval{};
    for(const auto& x:weights){
        maxval+=x;
    }

    for(int i{minval};i<=maxval;++i){
        int d=daysCalculator(weights,i);
        if(d<=days){
            return i;
        }
    }
    return -1;
}

int weightCalculatorOptimal(vector<int>& weights,int days){
    int n=weights.size();
    int minval=*max_element(weights.begin(),weights.end());
    int maxval{};
    for(const auto& x:weights){
        maxval+=x;
    }

    int l{minval};
    int h{maxval};
    int ans{-1};

    while(l<=h){
        int mid=l+(h-l)/2;
        int d=daysCalculator(weights,mid);
        if(d<=days){
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

    int days{};
    cin>>days;

    cout<<weightCalculator(nums,days)<<"\n";
    cout<<weightCalculatorOptimal(nums,days)<<"\n";
}
