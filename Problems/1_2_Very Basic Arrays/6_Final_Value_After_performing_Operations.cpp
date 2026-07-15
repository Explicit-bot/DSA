#include<iostream>
#include<vector>
using namespace std;

int FinValOper(vector<string>& operations){
    int i{};
    for(auto x:operations){
        if(x[1]== '+'){     //As the middle is always '+' whether "++X" or "X++"
            ++i;
        }
        else{
            --i;
        }
    }
    return i;
}

int main(){
    int n{};
    cin>>n;

    vector<string> operations(n);

    for(int i{};i<n;++i){
        cin>>operations[i];
    }

    cout<<FinValOper(operations);
}
