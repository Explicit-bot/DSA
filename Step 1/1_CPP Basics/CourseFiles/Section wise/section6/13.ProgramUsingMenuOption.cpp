//switch case program using menu driven options 
# include<iostream>
using namespace std;
    

int main(){
	std::cout<<"menu\n";
	std::cout<< "1. add\n"<<
                "2. sub\n"<<
                "3. multi\n"<<
                "4. div\n";
    int option;
	    std::cout<<"enter your choice:";
		std::cin>>option;
	int a,b,c; 
		std::cout<<"enter 2 numbers:";
		std::cin>>a>>b;
	switch(option)
          {
		case 1:c=a+b;
      		   break;
		case 2:c=a-b;
		   break;
		case 3:c=a*b;
		   break;
		case 4:c=a/b;
		   break;
	  }
		std::cout<<"result is "<<c<<std::endl;
		return 0;
}
