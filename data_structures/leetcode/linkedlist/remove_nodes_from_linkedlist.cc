#include <iostream>
#include "listutil.h"

using namespace std;

ListNode* removeNodes(ListNode* head) {
	if (head == nullptr) return head;

	head->next = removeNodes(head->next);
	return head->next != nullptr && head->next->val > head->val ? head->next : head;
}

void print(ListNode* head) {
	while (head != nullptr) {
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL\n";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		vector<int> inputs;
		int num;

		while(cin.peek() != '\n' && cin.peek() != EOF) {
			cin >> num;
			inputs.push_back(num);
		}
		cin.ignore();

		if (!inputs.empty()) {
			ListNode* head = ListNode::fromArray(inputs);
			auto res = removeNodes(head);
			print(res);
		}
	}

	return 0;
}
