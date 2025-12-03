/*Nature of Quadratic Roots
Write nested if statements for printing Nature of Roots of Quadratic equation and also root
find discriminant
d=b^2-4ac
if d=0 then roots are real and equal
if d>0 roots are real but unequal
if d<0 then riots are imaginary
function Roots(float a ,float b, float c)
output
cout<<"real and equal "<<r1;
cout<<"real and unequal "<<r1<<" "<<r2;
cout<<"imaginary";
*/

#include<iostream>
#include<cmath>

void Roots(float a,float b,float c)
{
    float d,r1,r2;
    
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
}
