#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxBuilding(int n,vector<vector<int>>& restrictions){
    restrictions.push_back({1,0});
    restrictions.push_back({n,n-1});
    
}
