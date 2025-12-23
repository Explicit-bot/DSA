#include <iostream>
using namespace std;

int main() {
    int N{},M{};
    
    cin>>N>>M;
    
    if(N>M){
        cout<<N-M;
    }

    else{
        cout<<0;
    }
    
    return 0;
}
