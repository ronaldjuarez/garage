#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next (nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode* ptr1 = headA;
    ListNode* ptr2 = headB;

    while (ptr1 && ptr2 && ptr1 != ptr2)
    {
        ptr1 = ptr1 == nullptr? headB : ptr1->next;
        ptr2 = ptr2 == nullptr? headA : ptr2->next;
    }

    return ptr1;
}

int main()
{
    ListNode* node5c = new ListNode(5);
    ListNode* node4c = new ListNode(4);
    ListNode* node8c = new ListNode(8);
    ListNode* node1a = new ListNode(1);
    ListNode* node4a = new ListNode(4);
    ListNode* node1b = new ListNode(1);
    ListNode* node6b = new ListNode(6);
    ListNode* node5b = new ListNode(5);

    node4a->next = node1a;
    node1a->next = node8c;
    
    node5b->next = node6b;
    node6b->next = node1b;
    node1b->next = node8c;

    node8c->next = node4c;
    node4c->next = node5c;
    
    ListNode* result = getIntersectionNode(node4a, node5b);

    std::cout << result->val << std::endl;

    return 0;
}