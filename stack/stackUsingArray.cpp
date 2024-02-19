#include<iostream>

using namespace std;

#define n 100

class stack{
    int* arr;
    int top;

    public:

    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int num){
        if(top == n-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top] = num;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack underflow."<<endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top == -1){
            cout<<"Stack underflow."<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
}