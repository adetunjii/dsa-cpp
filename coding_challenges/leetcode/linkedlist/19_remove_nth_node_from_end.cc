#include <iostream>
#include "listutil.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        int count = 0;

        while (fast != nullptr) {
            count += 1;
            fast = fast->next;
        }

        if (count == n) {
            return head->next;
        }

        int cursor = 0;
        while (slow != nullptr) {
            if (cursor == count-n-1) {
                slow->next = slow->next->next;
            }

            slow = slow->next;
            cursor += 1;
        }

        return head;
    }
};