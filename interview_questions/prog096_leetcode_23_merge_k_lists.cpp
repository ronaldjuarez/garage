#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct PairNode {
	int i;
	ListNode* node;
	PairNode(int x, ListNode* n) : i(x), node(n) {}
};
struct CompareNodes {
	bool operator()(PairNode* const& n1, PairNode* const& n2) {
		return n1->node->val > n2->node->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int size = lists.size();
	if (size == 0) return nullptr;

	ListNode* head = nullptr;
	ListNode* tail = nullptr;


	priority_queue<PairNode*, vector<PairNode*>, CompareNodes> q;

	for (int i = 0; i < size; i++) {
		if (lists[i] != nullptr)
			q.push(new PairNode(i, lists[i]));
	}

	while (!q.empty()) {
		PairNode* node = q.top();
		q.pop();
		PairNode* temp = node;
		lists[node->i] = lists[node->i]->next;

		if (lists[node->i] != nullptr) {
			q.push(new PairNode(node->i, lists[node->i]));
		}
		if (head == nullptr) {
			head = temp->node;
			tail = temp->node;
		}
		else {
			tail->next = temp->node;
			tail = tail->next;
		}
		tail->next = nullptr;

	}

	return head;
}
ListNode* insertNode(ListNode*& node, int value) {
	if (node == nullptr) {
		node = new ListNode(value);
		return node;
	}

	ListNode* tmp = node;

	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	ListNode* n = new ListNode(value);
	tmp->next = n;
	return node;
}

void printList(ListNode*& node) {
	ListNode* temp = node;

	while (temp != nullptr) {
		std::cout << temp->val << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
int main() {
	ListNode* node1 = nullptr;
	ListNode* node2 = nullptr;
	ListNode* node3 = nullptr;
	vector<ListNode*> lists;
	insertNode(node1, 1);
	insertNode(node1, 4);
	insertNode(node1, 5);
	insertNode(node2, 1);
	insertNode(node2, 3);
	insertNode(node2, 4);
	insertNode(node3, 2);
	insertNode(node3, 6);


	lists.push_back(node1);
	lists.push_back(node2);
	lists.push_back(node3);

	ListNode* ans = mergeKLists(lists);
	printList(ans);

	return 0;
}