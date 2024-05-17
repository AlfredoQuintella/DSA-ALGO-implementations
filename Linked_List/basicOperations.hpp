#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

void insertFront(ListNode *head, int element) {
    ListNode* node = new ListNode(element);
    node->val = element;
    
    node->next = head;
    head = node;
}

void insertBack(ListNode *head, int element) {
    ListNode* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    ListNode* node = new ListNode(element);
    curr->next = node;
}

ListNode* removeFront(ListNode *head) {
    if(head == NULL){
        return head;
    }

    head = head->next;
    return head;
}

ListNode* removeBack(ListNode *head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    return head;
}

ListNode* removeElement(ListNode *head, int val) {
    if (head == NULL){
        return head;
    }

    ListNode *prev = head;
    ListNode *curr = head->next;

    while (curr != NULL){
        if (curr->val == val){
            prev->next = curr->next;
            curr = curr->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    if (head->val == val){
        head = head->next;
    }
    return head;
}
