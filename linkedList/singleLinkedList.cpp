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
void insertAtIndex(node* &head,int val,int k){
    int count = 0;
    node* n=new node(val);
    if(k==0){
        head=n;
        return;
    }
    if(head==NULL){
        return;
    }
    node* temp=head;
    while(temp->next!=NULL && count<k){
        temp=temp->next;
        count++;
    }
    if(temp->next!=NULL){
        n->next=temp->next;
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
node* reverse1(node* &head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverse2(node* &head)
{
    if(head == NULL || head->next==NULL)
    {
        return head;
    }
    node* newhead=reverse2(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* kreverse(node* &head,int k){
   node* prevptr = NULL;
   node* currptr = head;
   node* nextptr;

   int count = 0;
   while(currptr!=NULL && count<k){
    nextptr=currptr->next;
    currptr->next=prevptr;
    prevptr=currptr;
    currptr=nextptr;
    count++;
   }
   if(nextptr!=NULL){
    head->next=kreverse(nextptr,k);
   }
   return prevptr;
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
    insertAtTail(head,6);
    display(head);
    insertAtHead(head,1);
    display(head);
    insertAtIndex(head,7,2);
    display(head);
    node* newHead = kreverse(head,2);
    display(newHead);
    return 0;
}