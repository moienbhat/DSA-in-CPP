#include<iostream>
#include<queue>
using namespace std;

class Stack {
    queue<int> q;
    public:
      void Push(int x) {
        int s = q.size();
        q.push(x);

        for(int i=0; i<s; i++) {
            q.push(q.front());
            q.pop();
        }
      }

      int Pop() {
        int n = q.front();
        q.pop();
        return n;
      }

      int Top() {
        return q.front();
      }

      int Size() {
        return  q.size();
      }


};

int main() {
     Stack s;
    s.Push(6);
    s.Push(3);
    s.Push(7);


    cout << "Top of stack before deleting: " << s.Top() << endl;
    cout << "Size of stack before deleting: " << s.Size() << endl;
    cout << "The element deleted is: " << s.Pop() << endl;

    cout << "Top of stack after deleting: " << s.Top() << endl;
    cout << "Size of stack after deleting: " << s.Size() << endl;


    return 0;
}