#include <iostream>
using namespace std;

int main(){
    int A[5]{}, i{}, sum{};

    for (int& x : A) {
    std::cout << "Enter value for index " << i << ": ";
    std::cin >> x;
    ++i;
    }

    for(int x:A){
        sum+=x;
    }
    cout<<"Sum of all the elements of Array is "<<sum<<".";


}

//This all can be easily done using for loop too.

/*
using for loop
# include<iostream>
using namespace std;
    
//program for adding all elements of array


int main()
{
	int a[7]={4,8,6,9,5,2,7};
	int n=7,sum=0;
	for(int i=0;i<7;i++)
	{
		sum=sum=+a[i];
	}
	cout<<"sum is"<<sum;
	return 0;
}

*/
