#include<iostream>
#include<iomanip>
using namespace std;

// REverse a linked list -->
#include <iostream>
using namespace std;

// Node definition
class ListNode {
public:
    int val;           // value of node
    ListNode* next;    // pointer to next node

    // constructor
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Reverse a linked list
ListNode* Find_Mid_List(ListNode* head) {
   ListNode* slow = head ;
   ListNode* fast = head ;
   
   while(fast != NULL && fast->next !=NULL ){
      slow = slow->next ;
      fast = fast->next->next ; 
   }
   return slow ; 

}

// Print a linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
  // Create a sample list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Find middle node
    ListNode* mid = Find_Mid_List(head);
    if (mid != NULL) {
        cout << "Middle node value: " << mid->val << endl;
    }

    return 0;
}
