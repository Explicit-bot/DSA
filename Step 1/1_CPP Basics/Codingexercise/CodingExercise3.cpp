// Finding roots of a Quadratic Equation
// Write an expression for finding a positive root of Quadratic equation
// write only one positive formula at line
// root1=
#include<cmath>

float root(int a,int b,int c)
{
    float root1;
    //Write expression here, remove this comment
    root1=(-b+sqrt(b*b-4*a*c))/(2*a);

    return root1;
}
