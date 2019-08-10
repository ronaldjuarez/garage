#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* insert(ListNode* &l1, int value){

    ListNode* n = new ListNode(value);

    if (l1 == NULL) {
        l1 = n;
        return l1;
    }

    ListNode* temp = l1;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    return l1;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = NULL;

    int carry = 0; 
    int digit;
    while (l1 != NULL && l2 != NULL){
        digit = l1->val + l2->val + carry;
        carry = digit / 10;
        digit = digit % 10;
        insert(result, digit);
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL){
        digit = l1->val + carry;
        carry = digit / 10;
        digit = digit % 10;
        insert(result, digit);
        l1 = l1->next;
    }
    
    while (l2 != NULL){
        digit = l2->val + carry;
        carry = digit / 10;
        digit = digit % 10;
        insert(result, digit);
        l2 = l2->next;
    }

    if (carry != 0){
        insert(result, carry);
    }
    return result;
}

void print(ListNode* node){
    while(node != NULL){
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}


int main(){
    ListNode* n = new ListNode(2);
    insert(n, 4);
    insert(n, 3);
    print(n);

    ListNode* m = NULL; 
    insert(m, 5);
    insert(m, 6);
    insert(m, 4);
    print(m);

    ListNode* s = addTwoNumbers(n,m);
    print(s);

    return 0;
}