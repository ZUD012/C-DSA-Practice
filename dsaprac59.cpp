#include <iostream>
using namespace std;

// Define the ListNode structure
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int cnt = 0;

    // Check if k nodes exist
    while (cnt < k) {
        if (temp == NULL) {
            return head; // Not enough nodes, return as is
        }
        temp = temp->next;  // ✅ added missing semicolon
        cnt++;
    }

    // Recursively reverse the rest of the list
    ListNode* prevNode = reverseKGroup(temp, k);

    // Reverse current group of k nodes
    temp = head;
    cnt = 0;
    while (cnt < k) {
        ListNode* next = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = next;
        cnt++;
    }

    return prevNode; // ✅ return new head of reversed group
}

int main() {
    // Example: build list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;
    ListNode* newHead = reverseKGroup(head, k);

    // Print the reversed list
    ListNode* temp = newHead;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}
