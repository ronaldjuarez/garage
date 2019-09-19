#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
struct CompareNodes{
    bool operator()(ListNode* const &n1, ListNode* const &n2) {
        return n1->val > n2 -> val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int size = lists.size();

    if (size == 0) return nullptr;
    
    priority_queue<ListNode*, vector<ListNode*>, CompareNodes> q;
    
    for ( int i = 0 ; i < size; i++){
        q.push(lists[i]);
    }   

    while (!q.empty()){
        ListNode* node = q.top(); 
        node 
        q.pop();

    }

    return nullptr;
}


int main(){
    ListNode* node1; 
    ListNode* node2;
    ListNode* node3;
    node1 = new ListNode(4);
    node2 = new ListNode(1);
    node3 = new ListNode(3);
    priority_queue<ListNode*, vector<ListNode*>, CompareNodes> q;
    q.push(node1);
    q.push(node2);
    q.push(node3);

    while (!q.empty()){
        ListNode* node = q.top(); 
        q.pop();
        std::cout << node->val << " ";
    }

    std::cout << std::endl;

    return 0;
}