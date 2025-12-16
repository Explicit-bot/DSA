/*
Display Day name
Display name of the Day from given Day Number
day number -- day name(3 letters)
1 -- sun
2 -- mon
3 -- tue
4 -- wed
5 -- thu
6 -- fri
7 -- sat
function DayName(int day)
day -- Day number
output
*/
#include<iostream>

using namespace std;

void DayName(int day)
{
   if(day==1){
        std::cout<<"sun";
    }
    else if(day==2){
        std::cout<<"mon";
    }
    else if(day==3){
        std::cout<<"tue";
    }
    else if(day==4){
        std::cout<<"wed";
    }
    else if(day==5){
        std::cout<<"thu";
    }
    else if(day==6){
        std::cout<<"fri";
    }
    else if(day==7){
        std::cout<<"sat";
    }
    else{
        std::cout<<"Invalid day no.";
    } 
}
