//program for sum of natural numbers using while loops

# include<iostream>

int main()
{
	int n{},i=1,sum=0;
	std::cout<<"enter the number:";
	std::cin>>n;
	while(i<=n)
	{
	     sum=sum+i;
	     ++i;  //++i is faster than i++
	}
	std::cout<<"sum of natural no is"<<sum<<std::endl;
	return 0;
}
