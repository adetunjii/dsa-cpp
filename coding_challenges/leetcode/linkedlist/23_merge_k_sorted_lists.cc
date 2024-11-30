#include <iostream>
#include "listutil.h"

using namespace std;

ListNode* merge(ListNode* list1, ListNode* list2) {
	ListNode* res = new ListNode();
	auto current = res;

	while (list1 != nullptr && list2 != nullptr) {
		if (list1->val < list2->val) {
			current->next = list1;
			list1 = list1->next;
		} else {
			current->next = list2;
			list2 = list2->next;
		}

		current = current->next;
	}

	return res->next;
}

// runs in O(n * (p + q)) time, O(n) space.
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()) return nullptr;

	auto head = lists[0];
	for (int i = 1; i < lists.size(); i++) {
		head = merge(head, lists[i]);
	}

	return head;
}

// runs in O(n * k) time and O(n) space.
ListNode* mergeKListsB(vector<ListNode*>& lists) {
	if (lists.empty()) return nullptr;

	vector<int> st;

	for (ListNode* list : lists) {
		while (list != nullptr) {
			st.push_back(list->val);
			list = list->next;
		}
	}

	sort(st.begin(), st.end());

	ListNode* res = nullptr, *current = nullptr;

	for (int x : st) {
		if (res == nullptr) {
			res = new ListNode(x);
			current = res;
		} else {
			current->next = new ListNode(x);
			current = current->next;
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}