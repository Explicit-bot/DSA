//program for finding length of a string using for loop
# include<iostream>
using namespace std;
    
int main(){
    string str;
    cout<<"Enter your string:";
    getline(cin,str);
    
    int count=0;
	for(int i=0;str[i]!='\0';i++){
        ++count;
	}

    cout<<"length is"<<count<<endl;
	
}
