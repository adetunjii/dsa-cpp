#include <iostream>
#include "listutil.h"

using namespace std;

class Solution {
public:
    int Init = []{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        return 0;
    }();

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        auto slow = head, fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto mid = slow->next;

        // reverse right side of the list
        ListNode* half = nullptr;
        while(mid != nullptr) {
            auto next = mid->next;
            mid->next = half;
            half = mid;
            mid = next;
        }

        // detach the right half of the list;
        slow->next = nullptr;

        auto start = head;
        while(start != nullptr && half != nullptr) {
            auto next = start->next;
            auto prev = half;

            start->next = half;
            half = half->next;

            prev->next = next;
            start = next;
        }
    }
};

