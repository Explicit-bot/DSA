
#include <iostream>

int main(){
        int arr[10]={1 ,2 ,3 ,4 ,5 ,6 ,7 };
        
        for(int i = 0; i < 10; ++i){
                std::cout << arr[i] << " ";
        }
        std::cout<<std::endl;
}
//Here u can see it is partially initialized and so all uninitialized elements are set to zero
