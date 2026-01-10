#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        auto a = headA;
        while (a != nullptr) {
            auto b = headB;
            while(b != nullptr) {
                if (a == b) {
                    return a;
                }
                b = b->next;
            }
            a = a->next;
        }
        return nullptr;
    }

    ListNode* getIntersectionNodeHashmap(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*, bool> m;
        auto a = headA, b = headB;
        while (a != nullptr) {
            m[a] = true;
            a = a->next;
        }

        while (b != nullptr) { 
            if(m[b]) {
                return b;
            }
            b = b->next;
        }
        return nullptr;
    }


    // The trick here is to get both pointers to travel the same distance. 
    // If they both do, there will be an intersection node or nullptr.
    // Here's why it works:
    // 1. If nodeA is the same length as nodeB, then we traverse both list at the same time.
    // 2. If nodeA has a shorter length to nodeB or vice versa, for ex: nodeA has 3 nodes and nodeB has 5.
    //    nodeA = [4,1,8,4,5]
    //    nodeB = [5,6,1,8,4,5]
    //    By the time both pointers traverse the list by exactly (m+n) times, we will find the intersection, and 
    //    if it doesn't exist, we will return a nullptr;
    ListNode* getIntersectionNodeAlt(ListNode* headA, ListNode* headB) {
        auto a = headA, b = headB;

        while (a != b) {
            if (a == nullptr) {
                a = headB;
            } else if (b == nullptr) {
                b = headA;
            }

            a = a->next;
            b = b->next;
        }

        return a;
    }
};