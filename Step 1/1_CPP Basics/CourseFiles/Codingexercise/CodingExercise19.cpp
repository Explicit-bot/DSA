/*
Display Month Name
Display Name of a Month for a given Month number
function MonthName(int m)
1 -- jan
2 -- feb
3 -- mar
4 -- apr
5 -- may
6 -- jun
7 -- jul
8 -- aug
9 -- sep
10 -- oct
11 -- nov
12 -- dec
*/

#include<iostream>

using namespace std;

void MonthName(int m)
{
 
    if(m==1){
        std::cout<<"jan";
    }
    else if(m==2){
        std::cout<<"feb";
    }
    else if(m==3){
        std::cout<<"mar";
    }
    else if(m==4){
        std::cout<<"apr";
    }
    else if(m==5){
        std::cout<<"may";
    }
    else if(m==6){
        std::cout<<"jun";
    }
    else if(m==7){
        std::cout<<"jul";
    }
    else if(m==8){
        std::cout<<"aug";
    }
    else if(m==9){
        std::cout<<"sep";
    }
    else if(m==10){
        std::cout<<"oct";
    }
    else if(m==11){
        std::cout<<"nov";
    }
    else if(m==12){
        std::cout<<"dec";
    }
    else{
        std::cout<<"Invalid month no.";
    } 
}
