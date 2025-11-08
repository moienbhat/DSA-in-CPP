#include <iostream>


using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to return the lenght
// of loop when slow and fast are
// on the same node
int findLength(Node* slow, Node* fast){
    
    // count to keep track of 
    // nodes encountered in loop
    int cnt = 1;
    
    // move fast by one step
    fast = fast->next;
    
    // traverse fast till it 
    // reaches back to slow
    while(slow!=fast){
        
        // at each node increase
        // count by 1 and move fast
        // forward by one step
        cnt++;
        fast = fast->next;
    }
    
    // loop terminates when fast reaches
    // slow again and the count is returned
    return cnt;
}
// Function to find the length
// of the loop in a linked list
int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;     
        // Move fast two steps
        fast = fast->next->next;

        // Step 2: If the slow and fast pointers
        // meet, there is a loop
        if (slow == fast) {
            // return the number of nodes
            // in the loop
            return findLength(slow, fast);
        }
    }
    return 0;
}




int main() {
    // Create nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a loop for testing: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    // Call function
    int loopLength = lengthOfLoop(head);

    if (loopLength > 0)
        cout << "Loop detected. Length = " << loopLength << "\n";
    else
        cout << "No loop detected.\n";

    return 0;
}
