#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

class queue
{
    stack<int>s1;
public:
    void enqueue(int val)
    {
        s1.push(val);
    }
    int dequeue()
    {
        if(s1.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item = dequeue();
        s1.push(x);
        return item;
    }
    bool empty()
    {
        return s1.empty();
    }
};

int  main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.dequeue()<<endl;
    q.enqueue(5);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    return 0;
}
