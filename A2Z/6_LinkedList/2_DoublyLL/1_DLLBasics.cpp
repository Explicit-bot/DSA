#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data1){
            data=data1;
            next=nullptr;
            prev=nullptr;
        }

        Node(int data1,Node* next1,Node* prev1){
            data=data1;
            next=next1;
            prev=prev1;
        }
};

Node* ConvertArr2DLL(vector<int> nums){
    Node* head=new Node(nums[0]);
    Node* last=head;

    for(int i{1};i<nums.size();++i){
        Node* temp=new Node(nums[i],nullptr,last);
        last->next=temp;
        last=temp;
    }
    return head;
}


int main(){
    vector<int> nums={12,2,3,4,5,6,7};
    Node* head=ConvertArr2DLL(nums);

    //Traversal
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
