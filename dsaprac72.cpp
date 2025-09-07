#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class LruCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    int limit = 2;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;

    // Constructor
    LruCache(int capacity) {
        limit = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // Add new node right after head
    void addnode(Node* newNode) {
      Node* oldNext = head->next ; 
      head->next = newNode ;
       oldNext->prev = newNode ;
    }

    // Delete node from the list
    void delNode(Node* oldNode) {
        Node* oldprev = oldNode->prev;
        Node* oldnext = oldNode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    // Insert or update key-value pair
    void put(int key, int val) {
        if(m.find(key) != m.end()) {
            // Key exists, remove old node
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }
        if(m.size() == limit) {
            // Cache is full, remove least recently used node
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        // Insert new node
        Node* newNode = new Node(key, val);
        addnode(newNode);
        m[key] = newNode;
    }

    // Retrieve value and update node to most recently used
    int get(int key) {
        if(m.find(key) == m.end()) {
            return -1;
        }
        Node* ansNode = m[key];
        int ans = ansNode->val;
        delNode(ansNode);
        addnode(ansNode);
        return ans;
    }
};

int main() {
    LruCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << "Get 1: " << cache.get(1) << endl; // returns 1
    cache.put(3, 3);                           // evicts key 2
    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);                           // evicts key 1
    cout << "Get 1: " << cache.get(1) << endl; // returns -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // returns 3
    cout << "Get 4: " << cache.get(4) << endl; // returns 4

    return 0;
}
