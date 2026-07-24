#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1,Node* next1){
            data=data1;
            next=next1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
        }
};

//Convert Array to Linked List
Node* ConvertArr2LL(vector<int> nums){
    Node* head=new Node(nums[0]);
    Node* mover=head;
    for(int i{1};i<nums.size();++i){
        Node* temp = new Node(nums[i]);
        mover->next=temp;
        mover=mover->next;
    }

    return head;
}

//Brute
bool detectCycle(Node* head){
    unordered_map<Node* ,int> mpp;
    Node* temp=head;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return true;
        }
        mpp[temp]=1;
        temp=temp->next;
    }
    return false;
}

//Optimal
bool detectCycleOptimal(Node* head){
    Node* slow=head;
    Node* fast=head;
    
    while(fast->next!=nullptr && fast!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}


int main(){
    int n{};
    cin>>n;

    vector<int> nums(n,0);

    for(int i{};i<n;++i){
        cin>>nums[i];
    }

    cout<<"Input Array:";
    for(auto x:nums){
        cout<<x<<" ";
    }
    cout<<"\n";
    Node* head=ConvertArr2LL(nums);

    //Traversal
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";


}
