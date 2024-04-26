#include <iostream>
#include "listutil.h"

using namespace std;

ListNode* swapPairs(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return head;

	ListNode* temp = head->next;
	head->next = swapPairs(temp->next);
	temp->next = head;
	return temp;
}

void print(ListNode* head) {
	while (head != nullptr) {
		cout << head->val << "-";
		head = head->next;
	}
	cout << "NULL\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i <= N; i++) {
		vector<int> inputs;
		 
		int num;
    while (cin.peek() != '\n' && cin.peek() != EOF) {
    	cin >> num;
    	inputs.push_back(num);
    }
    cin.ignore();

		if (!inputs.empty()) {
			auto list = ListNode::fromArray(inputs);

			cout << "Testcase # " << i << ": " << "\n";
			auto res = swapPairs(list);
			print(res);
		}
	}

	return 0;
}