#include <iostream>
#include <stack>
using namespace std;

struct Queue
{
    stack<int> input, output;

    void Push(int data)
    {
        cout << "The element pushed is: " << data << endl;
        input.push(data);
    }

    int Pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty())
        {
            cout << "Queue is empty!" << endl;
            exit(0);
        }
        int val = output.top();
        output.pop();
        return val;
    }

    int Top()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        if (output.empty())
        {
            cout << "Queue is empty!" << endl;
            exit(0);
        }
        return output.top();
    }

    int Size()
    {
        return input.size() + output.size();
    }
};

int main()
{

    Queue q;
    q.Push(4);
    q.Push(14);
    q.Push(24);
    q.Push(34);

    cout << "Queue peek before deleting element: " << q.Top() << endl;
    cout << "Size before deletion: " << q.Size() << endl;
    cout << "First element deleted: " << q.Pop() << endl;

    cout << "Queue peek after deleting element: " << q.Top() << endl;
    cout << "Size after deletion: " << q.Size() << endl;
    return 0;
}