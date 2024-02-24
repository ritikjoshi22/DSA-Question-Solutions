#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

#define n 20

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int val)
    {
        if (back == n - 1)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        back++;
        arr[back] = val;
        if (front == -1)
        {
            front++;
        }
    }
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue empty" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (back == -1 || front > back)
        {
            cout << "Queue Empty" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (back == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    q.pop();
    cout << q.empty() << endl;
    return 0;
}
