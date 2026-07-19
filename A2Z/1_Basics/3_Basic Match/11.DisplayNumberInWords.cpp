//***Display a numbers in words.
#include <iostream>
using namespace std;

vector<int> displaynum(int n){
    vector<int> num{};
    if(n==0){
        num.push_back(0);
    }
    else if(n<0){
        cout<<"Minus ";
        n=-n;
    }

    while(n>0){
        int rem=n%10;
        num.push_back(rem);
        n/=10;
    }

   return num;
}

int main(){
    int n{};

    cout<<"Enter your no.:";
    cin>>n;
    
    vector<int> disp=displaynum(n);
    
    for(int x:disp){
        switch(x){           //Arithmetic on char converts them to int automatically.
                             //switch() needs an integral type(int, char, enum).
            case 0: 
                cout<<"Zero ";
                break;
            case 1: 
                cout<<"One ";
                break;
            case 2: 
                cout<<"Two ";
                break;
            case 3: 
                cout<<"Three ";
                break;
            case 4: 
                cout<<"Four ";
                break;
            case 5: 
                cout<<"Five ";
                break;
            case 6: 
                cout<<"Six ";
                break;
            case 7: 
                cout<<"Seven ";
                break;
            case 8: 
                cout<<"Eight ";
                break;
            case 9: 
                cout<<"Nine ";
                break;
            default:
                cout<<"invalid";
            break;
        }
    }
}
