// Write an expression for calculating Distance
// parameters are
// u -- initial velocity
// v -- final velocity
// a -- acceleration
// just write an expression at line
// Distance=

int CalculateDistance(int u,int v,int a)
{
    float distance;
    
    distance=(v*v-u*u)/(2*a);
    return distance;

}
