#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class stack{
    node* top;
    public:
    stack(){
        top = NULL;
    }
    void push(int val){
        node* temp = new node(val);
        if(!temp){
            cout<<"Stack overflow"<<endl;
            exit(1);
        }
        temp->data = val;
        temp->next = top;
        top = temp;
    }
    bool empty(){
        return top == NULL;
    }
    int Top(){
        if(!empty()){
            return top->data;
        }
        else{
            exit(1);
        }
    }
    void pop(){
        node* temp;
        if(top == NULL){
            cout<<"stack underflow."<<endl;
            exit(1);
        }
        else{
            temp=top;
            top = top->next;
            delete temp;
        }
    }
    void display(){
        node* temp;
        if(top == NULL){
            cout<<"No element to display"<<endl;
            exit(1);
        }
        else{
            temp = top;
            while(temp!=NULL){
                cout<<temp->data;
                temp=temp->next;
                if(temp!=NULL){
                    cout<<"->";
                }
            }
        }
        cout<<endl;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    s.push(4);
    s.push(5);
    s.display();
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
}