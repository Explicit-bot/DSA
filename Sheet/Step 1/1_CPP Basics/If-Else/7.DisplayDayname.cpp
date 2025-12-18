//else if ladder
#include<iostream>

int main(){
    int day_no;

    std::cout<<"Enter day no. :"<<std::endl;
    std::cin>>day_no;

    if(day_no==1){
        std::cout<<"Monday"<<std::endl;
    }
    else if(day_no==2){
        std::cout<<"Tuesday"<<std::endl;
    }
    else if(day_no==3){
        std::cout<<"Wednesday"<<std::endl;
    }
    else if(day_no==4){
        std::cout<<"Thursday"<<std::endl;
    }
    else if(day_no==5){
        std::cout<<"Friday"<<std::endl;
    }
    else if(day_no==6){
        std::cout<<"Saturday"<<std::endl;
    }
    else if(day_no==7){
        std::cout<<"Sunday"<<std::endl;
    }
    else{
        std::cout<<"Invalid day no."<<std::endl;
    }
    
    return 0;

}
