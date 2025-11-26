#include <iostream>
#include<stack>
using namespace std;

struct stackNode
{
    int data;
    stackNode *next;
    int size;
    stackNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Mystack
{
    stackNode *top;
    int size;
    Mystack()
    {
        top = NULL;
        size = 0;
    }

    void stackPush(int x)
    {
        stackNode *element = new stackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed: " << "\n";
        size++;
    }

    int stackPop()
    {
        if (top == NULL)
            return -1;

        int topData = top->data;
        stackNode *temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    int stackSize()
    {
        return size;
    }

    bool isStackEmpty()
    {
        return top == NULL;
    }

    int stackPeek()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }

    void printStack()
    {
        stackNode *current = top;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    Mystack s;
    s.stackPush(10);
    cout << "Element popped: " << s.stackPop() << endl;
    cout << "Stack Size : " << s.stackSize() << endl;
    cout << "Stack empty or not " << s.isStackEmpty() << endl;
    cout << "Stack's Top element: " << s.stackPeek() << endl;

    return 0;
}