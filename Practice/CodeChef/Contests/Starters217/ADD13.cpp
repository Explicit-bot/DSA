#include <iostream>
using namespace std;

int main() {
    int T{};
    cin>>T;
    
    while(T--){
        long long N{},M{};       //used long long coz 3*N 
        cin>>N>>M;
        
        if(M<=3*N && N<=M && (M-N)%2==0){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}

/*
int        →  ~10^9
long long  →  ~10^18
*/
