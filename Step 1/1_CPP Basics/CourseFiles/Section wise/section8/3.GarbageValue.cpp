#include <iostream>

int main(){
        int arr[10];
        
        for(int i = 0; i < 10; ++i){
                std::cout << arr[i] << " ";
        //This array will contain garbage value as it is not initialized
        }
        std::cout<<std::endl;
}
/*
What is a garbage value?
If you declare any variable then definitely it will have some value.
that value is a garbage value. 
*/
