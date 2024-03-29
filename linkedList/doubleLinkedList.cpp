#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node* &head,int val)
{
    node* n = new node(val);
    if(head != NULL){
        head->prev = n;
    }
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val)
{
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    n->prev = temp;
    temp->next = n;
}

void deleteAtHead(node* &head)
{
    if(head == NULL){
        return;
    }
    node* todelete = head;
    head->next->prev = NULL;
    head=head->next;
    delete todelete;
}

void deletion(node* &head,int pos)
{
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    int count = 0;
    node* temp = head;
    while(temp!=NULL && count != pos-1){
        temp=temp->next;
        count++;
    }
    node* todelete = temp;
    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
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
    deleteAtHead(head);
    display(head);
    return 0;
}