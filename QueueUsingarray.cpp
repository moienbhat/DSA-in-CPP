#include<iostream>
using namespace std;

class Queue 
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue() {
        maxSize = 16;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int newElement) {
        if(currSize == maxSize) {
            cout<< "Queue is Full"<< endl;
            exit(1);
        }
        if(end == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxSize;
        }
        arr[end] = newElement;
        currSize++;
    }

    int pop() {
        if (start == -1) {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        int popped = arr[start];
        if(currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }

    int top() {
        if(start == -1) {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    int size() {
        return currSize;
    }
};

int main() {
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    cout << "Queue peek before deleting element: " << q.top() << endl;
    cout << "Size before deletion: " << q.size() << endl;
    cout << "First element deleted: " << q.pop() << endl;

    cout << "Queue peek after deleting element: " << q.top() << endl;
    cout << "Size after deletion: " << q.size() << endl;

    return 0;
}
