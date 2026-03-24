#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class MyQueue
{
private:
    stack<int> stkIn, stkOut;
    void transferInToOut();
    void transferOutToIn();

public:
    void push(int x);
    void pop();
    bool empty();
    int front();
    int back();
};

void MyQueue::transferInToOut()
{
    if (stkOut.empty())
    {
        while (!stkIn.empty())
        {
            stkOut.push(stkIn.top());
            stkIn.pop();
        }
    }
}

void MyQueue::transferOutToIn()
{
    if (stkIn.empty())
    {
        while (!stkOut.empty())
        {
            stkIn.push(stkOut.top());
            stkOut.pop();
        }
    }
}

bool MyQueue::empty()
{
    return stkIn.empty() && stkOut.empty();
}

void MyQueue::push(int x)
{
    stkIn.push(x);
}

void MyQueue::pop()
{
    transferInToOut();
    if (empty())
        throw invalid_argument("error");
    stkOut.pop();
}

int MyQueue::front()
{
    if (empty())
        throw invalid_argument("error");
    transferInToOut();
    return stkOut.top();
}

int MyQueue::back()
{
    if (empty())
        throw invalid_argument("error");
    transferOutToIn();
    return stkIn.top();
}

int main()
{
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);
    cout << mq.front() << " " << mq.back() << endl;
    mq.pop();
    cout << mq.front() << " " << mq.back() << endl;
    return 0;
}