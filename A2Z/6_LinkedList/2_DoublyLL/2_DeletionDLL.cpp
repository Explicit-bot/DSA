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

//Delete Head
Node* deleteHead(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==nullptr){
        delete head;
        return NULL;
    }

    Node* back=head;
    head=head->next;

    head->prev=nullptr;
    back->next=nullptr;
    delete back;

    return head;
}

//Delete tail
Node* deleteTail(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(head->next==nullptr){
        delete head;
        return NULL;
    }

    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node* last=temp->next;
    
    last->prev=nullptr;
    temp->next=nullptr;
    delete last;

    return head;
}

//Delete Kth element
Node* deleteKthNode(Node* head,int k){
    if(head==nullptr){
        return NULL;
    }

    int cnt{};
    Node* temp=head;
    while(temp!=nullptr){
        ++cnt;
        if(k==cnt){
            break;
        }
        temp=temp->next;
    }
    if(temp==nullptr){
        return head;
    }
    
    Node* Realnext=temp->next;
    Node* Realprev=temp->prev;

    if(Realnext==nullptr && Realprev==nullptr){
        delete temp;
        return NULL;
    }
    else if(Realprev==nullptr){
        return deleteHead(head);
    }
    else if(Realnext==nullptr){
       return deleteTail(head);
    }
    else{
        Realprev->next=Realnext;
        Realnext->prev=Realprev;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
    return head;
} 

//Delete value k
Node* deleteKthValue(Node* head,int k){
    if(head==nullptr){
        return NULL;
    }

    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==k){
            break;
        }
        temp=temp->next;
    }
    if(temp==nullptr){
        return head;
    }
    
    Node* Realnext=temp->next;
    Node* Realprev=temp->prev;

    if(Realnext==nullptr && Realprev==nullptr){
        delete temp;
        return NULL;
    }
    else if(Realprev==nullptr){
        return deleteHead(head);
    }
    else if(Realnext==nullptr){
        return deleteTail(head);
    }
    else{
        Realprev->next=Realnext;
        Realnext->prev=Realprev;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
    return head;
} 

int main(){
    vector<int> nums={12,2,3,4,5,6,7};
    Node* head=ConvertArr2DLL(nums);

    //Traversal
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
