#include <iostream>
using namespace std;

int main(){
    int i{};
    int A[7]{};
    
    for(int &x:A){
        cout<<"Enter element for index "<<i<<":";
        cin>>x;
        ++i;
    }
    
    int max{A[0]};

    for(int x:A){
        if(max<x){
            max=x;
        }
    }

    cout<<"Max element of the given Array [";
    for(int y{};y<7;++y){
        cout<<A[y]<<" ";
    }
    cout<<"]"<<" is "<< max<<".\n";
}

/*
        #include <iostream>
        using namespace std;

        int main(){
            int A[10]={2,4,6,8,12,3,5,7,9,11};
            int max=INT_MIN;
            
            for(int i=0;i<=10;i++){
                if(A[i]>max){
                max=A[i];
                }
            }
            cout<<max<<endl;
        }

Is it necessary to use INT_MIN?
Can we use 0 instead?

✅ Answer:
It depends on your data.

✅ 1. When 0 is safe:
If you know all values in the array are non-negative, like:

    int A[10] = {2,4,6,8,12,3,5,7,9,11};

Then:
    int max = 0;
✔️ is safe and works fine.

❌ 2. When 0 is dangerous:
If the array can contain negative numbers, e.g.:

int A[5] = {-9, -3, -15, -1, -7};
Then initializing with 0 is incorrect:

    int max = 0;
→ Output will be 0, which isn’t in the array!

✅ Correct way here:

        int max = INT_MIN;

Because INT_MIN is the lowest possible int value, any real value in the array will be higher.

🔁 Alternative (Cleaner):
You can initialize max with the first element of the array:

int max = A[0];
for(int i = 1; i < 10; ++i) {
    if(A[i] > max)
        max = A[i];
}
✅ This works for any values, even all negative or mixed arrays.


*/

















