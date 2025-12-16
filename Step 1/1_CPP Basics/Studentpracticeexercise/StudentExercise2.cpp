//Program to Calculate Net Salary
//netSalary=basic+basic*percentAllow/100-basic*percentDeduct/100;
#include<iostream>

int main(){

 float basic;
 float percentAllow;
 float percentDeduct;
 float netSalary;

 std::cout<<"Enter Basic Salary:";
 std::cin>>basic;
 std::cout<<"Enter percent of Allowences:";
 std::cin>>percentAllow;
 std::cout<<"Enter percent of Deductions:";
 std::cin>>percentDeduct;

 netSalary=basic+basic*percentAllow/100-basic*percentDeduct/100;

 std::cout<<"Net Salary is:"<<netSalary<<std::endl;

}
