#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public: 
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> hashmap;

        auto temp = head;
        while (temp != nullptr) {
            hashmap[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp != nullptr) {
            auto clone = hashmap[temp];
            clone->next = hashmap[temp->next];
            clone->random = hashmap[temp->random];
            temp = temp->next;
        }

        return hashmap[head];
    }

    // optimal solution: keep original nodes and copy nodes side by side, then extract them after;    
    Node* copyRandomListOptimal(Node* head) {
        if (head == nullptr) return nullptr;

        auto temp = head;
        while(temp != nullptr) {
            auto newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next->next;
        }

        // copy random pointers to cloned nodes.
        temp = head;
        while(temp != nullptr) {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // extract copy nodes from original nodes;
        temp = head;
        auto cur = head->next; 
        auto clone = head->next;

        while(temp != nullptr) {
            temp->next = temp->next->next;
            if (cur->next) cur->next = cur->next->next;
            temp = temp->next;
            cur = cur->next;
        }

        return clone;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}