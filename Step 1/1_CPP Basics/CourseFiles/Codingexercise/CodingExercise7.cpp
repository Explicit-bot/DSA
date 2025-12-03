// Calculate Distance between 2 point
// Write an Expression for finding Distance between 2 point
// parameters
// x1,y1 -- first point
// x2,y2 -- second point
// just write formula at line
// dist=

#include<cmath>


float distance(int x1,int y1,int x2,int y2)
{
    float dist;
    
    dist= std::sqrt(std::pow((x2-x1),2)+std::pow((y2-y1),2));

    return dist;
}
