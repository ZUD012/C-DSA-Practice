// flatten a doubly linked list 

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        flattenDFS(head);
        return head;
    }

private:
    Node* flattenDFS(Node* node) {
        Node* curr = node;
        Node* last = node; // tail of the flattened list

        while (curr) {
            Node* next = curr->next;
            if (curr->child) {
                Node* childTail = flattenDFS(curr->child);
           
                // Connect curr with child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;

                // Connect childTail with next
                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }
                last = childTail;
            } else {
                last = curr;
            }
            curr = next;
        }
        return last;
    }
};

// Utility: print the list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    // Link main level: 1-2-3-4-5-6
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    // Child of 3: 7-8-9-10
    n3->child = n7;
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    // Child of 8: 11-12
    n8->child = n11;
    n11->next = n12; n12->prev = n11;

    // Flatten
    Solution sol;
    Node* head = sol.flatten(n1);

    // Print flattened list
    cout << "Flattened list: ";
    printList(head);

    return 0;
}
