/*
Display Name of a Day
Display Day name for a given Day number
function DayName(int day)
1 -- sun
2 -- mon
3 -- tue
4 -- wed
5 -- thu
6 --fri
7 -- sat
*/
#include<iostream>


void DayName(int day){
    switch(day){
        case 1: 
            std::cout<<"sun";
            break;
	    case 2: 
            std::cout<<"mon";
	        break;
        case 3: 
            std::cout<<"tue";
  		    break;
	    case 4:
            std::cout<<"wed";
		    break;
	    case 5:
            std::cout<<"thu";
		    break;
	    case 6:
            std::cout<<"fri";
		    break;
	    case 7:
            std::cout<<"sat";
		    break;
	    default:
            std::cout<<"invalid day no";
	}
    
}
