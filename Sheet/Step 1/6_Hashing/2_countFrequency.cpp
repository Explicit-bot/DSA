/*
Given an array nums of size n which may contain duplicate elements.
return a list of pairs where each pair contains a unique element from the array and its frequency in the array.

You may return the result in any order, but each element must appear exactly once in the output.
*/

#include<iostream>
#include<unordered_map>
using namespace std;

vector<vector<int>> countFrequencies(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }

        vector<vector<int>> vec;
        for(auto &x:mp){   
            vec.push_back({x.first,x.second});
        }
        return vec;
    }

int main(){
    int n{};
    cout<<"Enter no. of elements in array:";
    cin>>n;

    int arr[n];
    for(int i{};i<n;++i){
        cin>>arr[i];
    }

    unordered_map<int,int> mp;
    for(int i{};i<n;++i){
        mp[arr[i]]++;
    }


    for(auto x:mp){
        cout<<x.first<<" "<<x.second<<"\n";
    }
}
