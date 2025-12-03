#include<iostream>
#include<cmath>

int main(){
    float a,b,c,d,r1,r2;
    std::cout<<"enter a,b,c respectively:"<<std::endl;
    std::cin>>a>>b>>c;
    
    d= std::pow(b,2)-4*a*c;
    if(d==0){
        r1=-b/(2*a);
        std::cout<<"real and equal " << r1;
    }
    else{
        if(d>0){
            r1=(-b+std::sqrt(std::pow(b,2)-4*a*c))/(2*a);
            r2=(-b-std::sqrt(std::pow(b,2)-4*a*c))/(2*a);
            std::cout<<"real and unequal "<< r1<<" "<<r2;
        }
        else{
            std::cout<<"imaginary";
        }
    }
    return 0;
}
