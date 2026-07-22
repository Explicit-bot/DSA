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
    if(nums.empty()){
        return NULL;
    }
    Node* head=new Node(nums[0]);
    Node* last=head;

    for(int i{1};i<nums.size();++i){
        Node* temp=new Node(nums[i],nullptr,last);
        last->next=temp;
        last=temp;
    }
    return head;
}

//Insertion before head
Node* insertAtHead(Node* head,int val){
    if(head==nullptr){
        return new Node(val);
    }

    Node* temp=new Node(val,head,nullptr);
    head->prev=temp;

    return temp;
}

//Insertion before tail
Node* insertBeforeTail(Node* head,int val){
    if(head==nullptr){
        return new Node(val);
    }
    if(head->next==nullptr){
        Node* newNode=new Node(val,head,nullptr);
        head->prev=newNode;
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prevNode=temp->prev;
    Node* last=new Node(val,temp,prevNode);
    prevNode->next=last;
    temp->prev=last;
    return head;
}

//Insert before Kth position
Node* insertBeforeKth(Node* head,int val,int k){
    if(k<=0){
        return head;
    }
    if(head==nullptr){
        if(k==1){
            return new Node(val);
        }
        return NULL;
    }
    if(k==1){
        Node* first=new Node(val,head,nullptr);
        head->prev=first;
        return first;
    }

    Node* temp=head;
    int cnt{1};
    while(temp!=nullptr && cnt<k){
        temp=temp->next;
        ++cnt;
    }
    if(temp==nullptr){
        return head;
    }

    Node* prevNode=temp->prev;
    Node* newNode=new Node(val,temp,prevNode);
    prevNode->next=newNode;
    temp->prev=newNode;

    return head;
}

//Insertion before value k


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
