#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* first = head;
    ListNode* second = head->next;
    ListNode* prev = NULL;

    // Update head to new first node after swap
    head = second;

    while (first != NULL && second != NULL) {
        ListNode* third = second->next;  // node after the pair
        second->next = first;
        first->next = third;

        if (prev != NULL) {
            prev->next = second;
        }

        // Move prev and first pointers forward
        prev = first;
        first = third;

        if (first != NULL) {
            second = first->next;
        } else {
            second = NULL;
        }
    }

    return head;
}

// Helper functions to build and print list
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new ListNode(arr[i]);
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    head = swapPairs(head);

    cout << "After swapping pairs: ";
    printList(head);

    return 0;
}
