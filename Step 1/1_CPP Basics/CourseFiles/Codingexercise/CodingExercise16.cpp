/*
Display Grades for Students Marks
Write nested conditions to check average marks and display grades
*this coding exercise is based on previous video*
Calculate Average (Avg)
if Avg >=60 print Grade 'A'
if 35<=Avg<60 print Grade 'B'
if Avg<35 print Grade 'C'
function Grades(int m1,int m2,int m3)
parameters are marks in 3 subjects
output
cout<<'A'
cout<<'B'
cout<<'C'
*/
#include<iostream>

void Grades(int m1,int m2,int m3)
{
    float Total,Avg;
    
    Total=m1 + m2 + m3;
    Avg=(float)Total/3;
    if(Avg>60){
        std::cout <<'A'; 
    }
    else{
        if(Avg>=35 && Avg<60){
          std::cout <<'B';  
        }
        else{
            std::cout<<'C';
        }
    }
}
