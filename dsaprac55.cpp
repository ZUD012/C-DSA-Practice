// Copy List -->
#include <iostream>
#include <unordered_map>
using namespace std;

// Node definition
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int x) {
        val = x;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;

    unordered_map<Node*, Node*> m;

    // Create new head
    Node* newHead = new Node(head->val);
    m[head] = newHead;

    Node* oldTemp = head->next;
    Node* newTemp = newHead;

    // Step 1: Copy all nodes (next pointers only)
    while (oldTemp != NULL) {
        Node* copyNode = new Node(oldTemp->val);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    // Step 2: Fix random pointers
    oldTemp = head;
    newTemp = newHead;
    while (oldTemp != NULL) {
        if (oldTemp->random != NULL) {
            newTemp->random = m[oldTemp->random];
        }
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newHead;
}

int main() {
    // Example usage
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->next = n2;
    n1->random = n2;
    n2->next = n3;
    n2->random = n3;

    Node* copied = copyRandomList(n1);

    cout << "Original head value: " << n1->val << endl;
    cout << "Copied head value: " << copied->val << endl;
    cout << "Copied head random points to: " << copied->random->val << endl;

    return 0;
}
