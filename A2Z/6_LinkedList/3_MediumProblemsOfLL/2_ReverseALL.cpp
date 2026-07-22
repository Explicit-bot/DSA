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
Node* reverseLL(Node* head){
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
Node* reverseLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* curr=head;
    Node* prev=nullptr;
    while(curr!=nullptr){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

//Recursive
Node* reverseLLRecursive(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* newHead=reverseLLRecursive(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
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
