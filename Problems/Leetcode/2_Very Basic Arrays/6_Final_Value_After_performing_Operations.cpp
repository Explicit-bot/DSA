#include<iostream>
#include<vector>
using namespace std;

vector<int> FinValOperBrute(vector<string>& operations){
    int n=operations.size();


}

int main(){
    int n{};
    cin>>n;

    vector<string> operations(n,0);

    for(int i{};i<n;++i){
        cin>>operations[i];
    }

    for(auto x:operations){
        cout<<x<<" ";
    }

}
