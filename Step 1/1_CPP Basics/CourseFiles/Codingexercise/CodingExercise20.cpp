/*
Display Digit in words
Display given Digit in Words
function DigitToWord(int d)
1 -- one
2 -- two
3 -- three
4 -- four
5 -- five
6 -- six
7 -- seven
8 -- eight
9 -- nine
0 -- zero
*/
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

void DigitToWord(int d)
{
    if(d==1){
        std::cout<<"one";
    }
    else if(d==2){
        std::cout<<"two";
    }
    else if(d==3){
        std::cout<<"three";
    }
    else if(d==4){
        std::cout<<"four";
    }
    else if(d==5){
        std::cout<<"five";
    }
    else if(d==6){
        std::cout<<"six";
    }
    else if(d==7){
        std::cout<<"seven";
    }
    else if(d==8){
        std::cout<<"eight";
    }
    else if(d==9){
        std::cout<<"nine";
    }
    else if(d==0){
        std::cout<<"zero";
    }
    else{
        std::cout<<"greater than 9 not programmed.";
    } 
    
}

