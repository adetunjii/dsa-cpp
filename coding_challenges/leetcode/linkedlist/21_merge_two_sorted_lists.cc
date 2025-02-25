#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* n = new ListNode();
        auto cur = n;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else if (list2->val < list1->val) {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        
        if (list1 != nullptr) {
            cur->next = list1;
        } else if (list2 != nullptr) {
            cur->next = list2;
        }

        return n->next;
    }
};