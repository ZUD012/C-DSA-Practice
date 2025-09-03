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
ListNode*  detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool iscycle = false ; 
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move 1 step
        fast = fast->next->next; 
          // move 2 steps
        if (fast == slow) {
          iscycle = true ;
          break ;  
        }
    }
    if(!iscycle) {
        return NULL ; 
    }
    slow = head ;
    while(slow!=fast){
        slow=slow->next ;
        fast=fast->next ;
    }
    return slow ; 

            
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // create a cycle
   
    ListNode* getval = detectCycle( head);
    cout<<getval->val ; 
    return 0;
}
