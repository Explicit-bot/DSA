#include<iostream>

int main(){
    float m1, m2, m3;
    float Total,Avg;

    std::cout<<"Enter m1,m2 & m3:"<<std::endl;
    std::cin>>m1>>m2>>m3;
    
    Total=m1 + m2 + m3;
    Avg=(float)Total/3;
    if(Avg>=60){
        std::cout <<'A'<<std::endl; 
    }
    else{
        if(Avg>=35 && Avg<60){
          std::cout <<'B'<<std::endl;  
        }
        else{
            std::cout<<'C'<<std::endl;
        }
    }
    return 0;
}
