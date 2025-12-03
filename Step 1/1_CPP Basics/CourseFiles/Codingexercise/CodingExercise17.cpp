/*
Calculate Discounted Bill Amount
Calculate Discounted Bill Amount
function Discount(float amount)
if amount>=5000 offer 20% discount
if 2000<=amount<5000 offer 10% discount
if amount<2000 offer 5% discount
output
print discounted amount ie. bill amount after discount
*/

#include<iostream>

void Discount(int amount)
{
    float disAmount;
    if(amount>=5000){
        disAmount= amount - (float)(20 * amount)/100;
        std::cout<<disAmount;
    }
    else{
        if(amount>=2000 && amount<5000){
            disAmount= amount - (float)(10 * amount)/100;
            std::cout<<disAmount;
        }
        else{
            disAmount= amount - (float)(5 * amount)/100;
            std::cout<<disAmount;
        }
    }
    
}
