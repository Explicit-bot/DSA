#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cout<<"Enter your string:"<<flush;
    getline(cin,str);

    for (int i{};str[i]!='\0';++i){
        if(str[i]>=65 && str[i]<=97){
            str[i]+=32;
        }
    }
    cout<<str<<"\n";
    
}
