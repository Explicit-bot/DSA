# include<iostream>

int main()
{
	int n{};
    int i{1};
    unsigned long long int fact{1};
	std::cout<<"enter the number:";
	std::cin>>n;
	while(i<=n)
	{
	     fact*=i;
	     ++i; 
	}
	std::cout<<n<<"!="<<fact<<std::endl;
	return 0;
}
