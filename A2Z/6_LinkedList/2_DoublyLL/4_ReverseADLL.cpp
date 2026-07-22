#include<iostream>
#include<vector>
#include<stack>
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
        return nullptr;
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

//Brute
Node* reverseDLL(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    stack<int> st;

    Node* temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=nullptr){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
}

//Optimal
Node* reverseDLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* curr=head;
    while(curr!=nullptr){
        Node* temp=curr->next;
        curr->next=curr->prev;
        curr->prev=temp;

        head=curr;
        curr=temp;
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
