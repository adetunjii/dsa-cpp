#ifndef LISTUTIL_H
#define LISTUTIL_H

#include <vector>;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
    static ListNode* fromArray(std::vector<int> a);
};

ListNode* ListNode::fromArray(std::vector<int> a) {
    ListNode* head = nullptr, *current = nullptr;

    for (int x : a) {
        if (head == nullptr) {
            head = new ListNode(x);
            current = head;
        } else {
            current->next = new ListNode(x);
            current = current->next;
        }
    }

    return head;
}

#endif // LISTUTIL_H