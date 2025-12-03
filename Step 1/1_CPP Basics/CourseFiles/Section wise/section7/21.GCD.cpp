#include <iostream>

int main(){
    int m{};
    int n{};

    std::cout<<"Enter two no.:"<<std::flush;
    std::cin>>m>>n;
    int tempm{m};
    int tempn{n};
    while(tempm!=tempn){
        if(tempm>tempn){
            tempm=tempm-tempn;
        }
        else if(tempn>tempm){
            tempn=tempn-tempm;
        }
    }
    std::cout<<"GCD of "<<m<<" and "<<n<<" is "<< tempm<<"\n";
    return 0;
}
