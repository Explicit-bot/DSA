//Display a number in words.
#include <iostream>

int main(){
    int n{};
    char rev[10];
    int i{};
    int r{};

    std::cout<<"Enter your no:"<<std::flush;
    std::cin>>n;

    while(n>0){
        r=n%10;
        rev[i]=r+'0';
        n=n/10;
        ++i;
    }
    rev[i]='\0';
    while(i>0){
        --i;
        switch(rev[i]-'0'){
            case 0: 
                std::cout<<"Zero ";
            break;
            case 1: 
                std::cout<<"One ";
            break;
            case 2: 
                std::cout<<"Two ";
            break;
            case 3: 
                std::cout<<"Three ";
            break;
            case 4: 
                std::cout<<"Four ";
            break;
            case 5: 
                std::cout<<"Five ";
            break;
            case 6: 
                std::cout<<"Six ";
            break;
            case 7: 
                std::cout<<"Seven ";
            break;
            case 8: 
                std::cout<<"Eight ";
            break;
            case 9: 
                std::cout<<"Nine ";
            break;
            default:
                std::cout<<"invalid";
            break;
        }
    }
    
}
