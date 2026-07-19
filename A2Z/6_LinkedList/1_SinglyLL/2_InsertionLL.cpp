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

//Insertion at head
Node* insertNodeAtHead(Node* head, int val){
    Node* temp=new Node(val,head);
    return temp;
}

//Insertion at tail
Node* insertNodeAtTail(Node* head, int val){
    if(head==nullptr){
        return new Node(val);
    }
    Node* temp=new Node(val);
    Node* end=head;
    while(end->next!=nullptr){
        end=end->next;
    }
    end->next=temp;
    return head;
}

//Insertion at kth position
Node* insertNodeAtKthPosition(Node* head, int val , int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return NULL;
        }
    }
    if(k==1){
        return new Node(val,head);
    }
    int cnt{};
    Node* temp=head;
    while(temp!=nullptr){
        ++cnt;
        if(k-1==cnt){
            Node* x=new Node(val,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Insert before value k
Node* insertNodeBeforeValue(Node* head, int val , int k){
    if(head==NULL){
        return NULL;
    }
    if(head->data==k){
        return new Node(val,head);
    }
    Node* temp=head;
    while(temp->next!=nullptr && temp!=nullptr){
        if(temp->next->data==k){
            Node* x=new Node(val,temp->next);
            temp->next=x;
            break;
        }
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
    cout<<"\n";

}

/*
Returning Directly
Node* insertNode(Node* head, int val){
    return new Node(val, head);
}

This is equivalent to:
Node* temp = new Node(val, head);
return temp;

Since the pointer is only being returned, there is no need to create a separate variable.
What Does new Return?
new always returns a pointer to the newly allocated object.

Example:
new Node(5, head);
returns a value of type
Node*

Therefore,
return new Node(val, head);

means
Create a new node and immediately return its address.
Does new Automatically Add the Node to the Linked List?
No.
new only creates a node in heap memory.
The node becomes connected to the linked list because its next pointer is initialized to the current head.

For example:
Initial list:
head
 ↓
10 → 20 → 30 → NULL

Executing
new Node(5, head);

creates
          +-----------+
          | data = 5  |
          | next -----|------+
          +-----------+      |
                             |
head                         |
 ↓                           |
10 → 20 → 30 → NULL

The new node points to the old head.
When Does the List Actually Change?
The list changes only when the returned pointer is assigned to head.
head = insertNode(head, 5);

Result:
head
 ↓
5 → 10 → 20 → 30 → NULL

Now the new node becomes the first node of the linked list.
What Happens If We Ignore the Return Value?
insertNode(head, 5);
A new node is created, but head is not updated.
New Node
5 → 10 → 20 → 30

head
 ↓
10 → 20 → 30

The newly created node still exists in memory, but there is no pointer that can access it.
This is called a Memory Leak.

Why Must We Write?
head = insertNode(head, val);
instead of
insertNode(head, val);
Because:
head is passed by value.
The function returns the address of the new first node.
The caller must update head to point to this new node.
Otherwise, the new node becomes unreachable.
*/
