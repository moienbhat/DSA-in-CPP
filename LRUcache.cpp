class LRUcache {
    public:
    class node {
        public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);


    int cap;
    unoredered_map < int, node * > m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;

    }

    void addNode(node * newnode) {
        node * temp = head -> next;
        newnode ->next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(node * newnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode-> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node * resnode = m[key_];
            int res = resnode -> val;
            m.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            m[key_] = head -> next;
            resturn res;
        }
        return -1;
     }

     void put(int key_ , int value) {
        if (m.find(key_) != m.end()) {
            node * existingnode = m[key_];
            m.erase(key_);
            deleteNode(existingnode);
        }
        if(m.sixe() == cap) {
            m.erase(tail -> prev -> key);
            deleteNode(tail -> prev);
        }

        addNode(new node(key_, value));
        m[key_] = head -> next;
     }


};