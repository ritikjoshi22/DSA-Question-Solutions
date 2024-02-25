#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node* front;
    node* back;
public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int val)
    {
        node* temp = new node(val);
        if(front == NULL){
            front = temp;
            back = temp;
            return;
        }
        back->next = temp;
        back = temp;
    }
    void pop()
    {
        if(front == NULL){
            cout<<"Queue empty"<<endl;
            return;
        }
        node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek()
    {
        if(front == NULL){
            cout<<"Queue Empty"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        return front == NULL;
    }
    void display()
    {
        node* temp = front;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
            if(temp!=NULL){
                cout<<"->";
            }
        }
        cout<<endl;
    }
};

int  main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.display();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    cout<<q.empty()<<endl;
    return 0;
}
