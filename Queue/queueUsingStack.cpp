#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

class queue
{
    stack<int>s1;
    stack<int>s2;
public:
    void enqueue(int val)
    {
        s1.push(val);
    }
    void dequeue()
    {
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
    int Top()
    {
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    bool empty()
    {
        return (s1.empty() && s2.empty());
    }
};

int  main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.Top()<<endl;
    q.dequeue();
    cout<<q.Top()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.empty()<<endl;
    return 0;
}
