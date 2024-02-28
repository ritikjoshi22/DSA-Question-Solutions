#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

class stack
{
    int n;
    queue<int>s1;
    queue<int>s2;
public:
    stack()
    {
        n = 0;
    }
    void push(int val)
    {
        s1.push(val);
        n++;
    }
    void pop()
    {
        if(s1.empty()){
            return;
        }
        while(s1.size() != 1){
            s2.push(s1.front());
            s1.pop();
        }
        s1.pop();
        queue<int>temp;
        temp = s1;
        s1 = s2;
        s2 = temp;
        n--;
    }
    int Top()
    {
        if(s1.empty()){
            return -1;
        }
        while(s1.size() != 1){
            s2.push(s1.front());
            s1.pop();
        }
        int topvalue = s1.front();
        s2.push(s1.front());
        queue<int>temp;
        temp = s1;
        s1 = s2;
        s2 = temp;
        return topvalue;
    }
    int size()
    {
        return n;
    }
};

int  main()
{
    stack s;
    s.push(1);
    s.push(8);
    s.push(4);
    cout<<s.Top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    cout<<s.size()<<endl;
    return 0;
}
