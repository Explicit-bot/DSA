//program for finding length of a string using string iterator
# include<iostream>
#include<string>
using namespace std;
    
int main(){

	string str;
    cout<<"Enter your string:";
    getline(cin,str);


	string::iterator it;
	int count=0;
	for(it=str.begin();it!=str.end();it++)
	{
        ++count;
	}
    cout<<"length is"<<count<<endl;
	return 0;
}
