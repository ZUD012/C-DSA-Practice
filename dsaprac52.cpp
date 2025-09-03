// Find the posiiton where the cycle starts from the starting side -->
#include <iostream>
using namespace std;

// Node definition
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to detect cycle using Floyd’s Tortoise-Hare algorithm
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next;     // move 2 steps
        if (fast == slow) {
            return true;             // cycle detected
        }
    }
    return false;                    // no cycle
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // create a cycle

    if (hasCycle(head))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle." << endl;

    return 0;
}
