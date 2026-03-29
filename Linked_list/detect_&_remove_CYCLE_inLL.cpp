#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
///////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        bool isCycle = false;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        // No cycle
        if (!isCycle) {
            return NULL;
        }

        // Step 2: Find start of cycle
        slow = head;

        // SPECIAL CASE: cycle starts at head
        if (slow == fast) {
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
            return slow;
        }

        // Normal case
        ListNode* prev = NULL;

        while (slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }

        // Remove cycle
        prev->next = NULL;

        return slow;
    }
};