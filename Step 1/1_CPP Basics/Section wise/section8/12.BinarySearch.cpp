/*
🧠 What is Binary Search?
Binary Search is an efficient search algorithm used to find the position of a target value in a sorted array by repeatedly dividing the search space in half.

📌 Conditions for Binary Search to Work
 - Data must be sorted (in increasing or decreasing order)
 - You must have random access (works on arrays, vectors)

🔁 How It Works
Let’s say you want to search for x in a sorted array:
 1.Find the middle element.
 2.If it matches x → done ✅
 3.If x is less, search the left half.
 4.If x is greater, search the right half.
 5.Repeat until found or search space is empty.
*/

# include<iostream>
using namespace std;
    
int main(){
    int a[10]={6,8,13,17,20,22,25,28,30,35};
 	int l=0,h=9,key,mid;

	cout<<"enter the key";
	cin>>key;

	while(l<=h){
		mid=(l+h)/2;
		if(key==a[mid])
		{
			cout<<"found at"<<mid;
			return 0;
		}
		else if(key<a[mid])
			h=mid-l;
		else
			l=mid+l;
	}
	cout<<"not found";
	return 0;
}
