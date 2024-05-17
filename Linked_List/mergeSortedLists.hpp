#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *mergedList = NULL;
    ListNode **tail = &mergedList;

    while (list1 != NULL && list2 != NULL){
        if (list1->val < list2->val){
            *tail = list1;
            list1 = list1->next;
        }
        else{
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }

    if (list1 != NULL){
        *tail = list1;
    }
    else{
        *tail = list2;
    }

    return mergedList;
}
