#include<iostream>
#include<vector>
using namespace std;

void reverseString(vector<char>& s) {
    int n=s.size();
    int l{};
    int r{n-1}; 
    while(l<r){
        swap(s[l],s[r]);
        ++l;
        --r;
    }
}
