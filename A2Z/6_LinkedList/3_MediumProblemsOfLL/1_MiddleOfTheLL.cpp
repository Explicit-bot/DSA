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
Node *findMiddle(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int mid = count / 2 + 1;
    temp = head;

    while (temp != NULL) {
        mid = mid - 1;
        if (mid == 0){
            break;
        }
        temp = temp->next;
    }
    return temp;
}

//Optimal
Node* middleNode(Node* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    
    Node* fast=head;
    Node* slow=head;
    
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
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

    Node* middle=middleNode(head);
    if(middle==nullptr){
        cout<<"No middle element found"<<"\n";
    }
    else{
        cout<<middleNode(head)->data<<"\n";
    }
}
