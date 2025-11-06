#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int data;         // Data of the node
    Node* next; 
    Node* back;   
   // Pointer to the next node in the list
    // Constructor for a node with both data and next node provided
    Node(int data1, Node* next1,Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
        back  = nullptr;
    }};

     Node* convertArr2DLL(vector<int> arr) {
        Node* head = new Node(arr[0]);
        Node* prev = head;

        for(int i = 1;i<arr.size();i++) {
            Node* temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = temp;
        }
        return head;
     }

     void print(Node* head) {
        while(head != NULL) {
            cout<< head->data <<" ";
            head = head->next;
        }
     }


     Node* deleteHead(Node* head) {
        if(head == NULL || head->next==NULL) {
            return NULL;
        }

        Node*prev = head;
        head= head->next;


        prev->back = nullptr;
        prev->next = nullptr;
        

        delete prev;
        return head;
     }


      Node* deleteTail(Node* head) {
        if(head == NULL || head->next==NULL) {
            return NULL;
        }
        Node* tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }

        Node* newTail = tail->back;
        newTail->next = nullptr;
        tail->back = nullptr;

        delete tail;
        return head;

    }

    Node* removeKthElement(Node* head, int k) {
        if(head == NULL) {
            return NULL;
        }
        int cnt = 0;
        Node* kNode = head;
        while(kNode != NULL) {
            cnt++;
            if(cnt == k) break;
            kNode = kNode->next;
        }
        Node* prev = kNode->back;
        Node* front = kNode->next;

        if(prev == NULL && front == NULL) {
            return NULL;
        }
        else if(prev == NULL) {
            return deleteHead(head);
        }
        else if(front == NULL) {
            return deleteTail(head);
        }
        prev->next =front;
        front->back = prev;

        kNode->next = nullptr;
        kNode->back = nullptr;
        delete kNode;
        return head;
    }

    void DeleteNode(Node* temp) {
        Node* prev = temp->back;
        Node* front = temp->next;
        
        if(front == NULL) {
            prev->next = nullptr;
            temp->back = nullptr;
            free(temp);
            return;
        }
        prev->next = front;
        front->back = prev;

        temp->next = temp->back = nullptr;
        free(temp);
    
    }


    Node* insertBeforeHead(Node* head, int val) {
        Node* newHead = new Node(val, head, nullptr);
        head->back = newHead;

        return newHead;
    } 


     Node* insertBeforeTail(Node* head, int val) {
        if(head->next == NULL) {
            return insertBeforeHead(head, val);
        }

        Node* tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }

        Node* prev = tail->back;
        Node* newNode = new Node(val, tail, prev);
        prev->next = newNode;
        tail->back = newNode;

        return head;
     }


     Node* insertBeforeKthElement(Node* head, int k, int val) {
        if(k == 1){
            return insertBeforeHead(head, val);
        }

        Node* temp = head;
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            if(cnt == k) break;
            temp = temp->next;
        }

        Node* prev = temp->back;
        Node* newNode = new Node(val, temp, prev);
        prev->next = newNode;
        temp->back = newNode;

        return head;
     }

     void insertBeforeNode(Node* node, int val) {
        Node* prev = node->back;
        Node*newNode = new Node(val, node, prev);
        prev->next = newNode;
        node->back = newNode;
     }

     Node* insertAtTail(Node* head, int k) {
        if(head == NULL) {
            return new Node(k);
        }
        Node* tail = head;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        Node* newNode = new Node(k, nullptr, tail);
        tail->next = newNode;

        return head;
     }
    
    
    int main() {
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = removeKthElement(head,2);
    // DeleteNode(head->next->next);

    // head = insertBeforeHead(head, 10);
    // head = insertBeforeTail(head, 10);
    // head = insertBeforeKthElement(head, 3, 10);
    // insertBeforeNode(head->next->next, 10);
    head = insertAtTail(head, 10);
    print(head);




    return 0;

}
