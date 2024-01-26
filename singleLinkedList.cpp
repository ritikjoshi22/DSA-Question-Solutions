#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val)
{
    node* n = new node(val);
    if(head == NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void deletion(node* &head,int val)
{
    node* todelete;
    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            todelete = temp->next;
            break;
        }
        temp=temp->next;
    }
    temp->next=temp->next->next;
    delete todelete;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,1);
    display(head);
    deletion(head,3);
    display(head);
    return 0;
}