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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) fast = fast->next;
        }

        ListNode* left = head; 
        ListNode* right = reverse(slow);
        while (left != right && right != NULL) {
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;

        while (cur != NULL) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};