//program for finding user name from email address
# include<iostream>
using namespace std;
    
int main(){
	string email;
    cout<<"Enter your Email:"<<flush;
    cin>>email;

	int i=(int)email.find('@');
	string uname=email.substr(0,i);
	cout<<"user name is "<<uname<<endl;
	return 0;
}
