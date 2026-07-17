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

//Delete Head
Node* removehead(Node* head){
    if(head==nullptr){
        return head;
    }

    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

//Delete tail
Node* removetail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

//Delete Kth Node
Node* removekth(Node* head , int k){
    if(head==nullptr){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    int cnt{};
    Node* temp=head;
    Node* prev=nullptr;
    while(temp){
        ++cnt;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//Delete element k
Node* removeElmK(Node* head , int k){
    if(head==nullptr){
        return head;
    }
    if(k==head->data){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    Node* temp=head;
    Node* prev=nullptr;
    while(temp){
        if(temp->data==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> nums={12,2,3,4,5,6,7};
    Node* head=ConvertArr2LL(nums);

    //Traversal
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
