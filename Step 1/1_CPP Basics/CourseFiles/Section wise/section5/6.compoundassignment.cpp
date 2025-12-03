#include <iostream>

int main() {
    int a{10};
    int b{20};
    int c{30};
    int sum{};
    
    sum += a+b+c;

    std::cout << "Sum is " << sum<< "." <<std::endl;
    return 0;
}
/*
    so instead of doing sum=sum+a+b+c we can use sum+=a=b=c
    Compound assignment
    +=
    -=
    *=
    /=
    %=
    sum+= a+b+c;
*/
