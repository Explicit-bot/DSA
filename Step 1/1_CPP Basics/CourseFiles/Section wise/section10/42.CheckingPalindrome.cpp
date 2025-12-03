//program for reverse a string and check a string is a palidrome
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cout<<"Enter your word():"<<flush;
    cin>>str;

    //Touppercase
    for (int i{};str[i]!='\0';++i){
            if(str[i]>=97 && str[i]<=122){
                str[i]-=32;
            }
    }

    int len=str.length();

    string rev;
    rev.resize(len);
    int j{};
    auto it=str.rbegin();
    for (int i{};i<len;++i){
        rev[j]=str.rbegin()[i];
        ++it;
        ++j;
    }
    
    if(rev==str){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }

}
/*
When you write:
    rev[j] = str.rbegin()[i];

You're using a special kind of iterator called a reverse iterator, and rbegin() gives you an iterator pointing to the last character of the string. You can access characters in reverse order using the bracket [] operator just like an array.

🧠 So how does this work?
str.rbegin() returns:
An iterator pointing to the last character of the string (i.e., str[str.length() - 1]).

str.rbegin()[i] means:
Access the character at i steps after the end, which is essentially:
str[str.length() - 1 - i].

✅ Equivalent manual expression:
    char c = str[str.length() - 1 - i];  // same as str.rbegin()[i]


You can also use:
    string rev(str.rbegin(), str.rend());  // shortest and most idiomatic
This creates a new reversed string directly, without writing a loop.


another method
# include<iostream>
using namespace std;

int main()
{
	string str="MADAM";
	string rev="";
	int len=(int)str.length();
	rev.resize(len);
	for(int i=0,j=len-1;i<len;i++,j--)
	{
		rev[i]=str[j];
	}
	rev[len]='\0';	
	if(str.compare(rev)==0)
		cout<<"palindrome"<<endl;
	else
		cout<<"not a pallindrome"<<endl;
	return 0;
}
*/
