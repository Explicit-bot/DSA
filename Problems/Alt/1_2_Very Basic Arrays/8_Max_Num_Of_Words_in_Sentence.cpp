#include<iostream>
#include<vector>
#include<string>
using namespace std;

int mostWordsFound(const vector<string>& sentences) {
    int maxi{};
    for(const auto& x:sentences){
        int cnt{1};
        for(auto y : x){
            if(y==' '){
                ++cnt;
            }
        }
        maxi=max(maxi,cnt);
    }
    return maxi;
}


int main(){
    int n{};
    cin>>n;
    cin.ignore();

    vector<string> sentences(n);
    for(int i{};i<n;++i){
        getline(cin,sentences[i]);
    }

    cout<<mostWordsFound(sentences)<<"\n";
}

