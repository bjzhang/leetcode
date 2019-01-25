
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* output;
    struct ListNode** outputReturn = &output;
    struct ListNode* node;

    while(l1!=NULL && l2!=NULL) {
        output = (struct ListNode*)malloc(sizeof(struct ListNode));
        if(l1->val > l2->val) {
            output->val = l2->val;
            l2=l2->next;
        } else {
            output->val = l1->val;
            l1=l1->next;
        }
        output = output->next;
    }
    return *outputReturn;
}

struct ListNode *init(int *nums, int len)
{
    struct ListNode *node;
    struct ListNode **head = &node;
    struct ListNode *prev = NULL;

    int i;
    for(i = 0; i < len; i++) {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (prev != NULL) {
            prev->next = node;
        }
        node->val = nums[i];
        prev = node;
    }
    return *head;
}

void printList(struct ListNode *list)
{
    int i = 0;
    while(list!=NULL) {
        printf("%d: %d\n", i, list->val);
        list = list->next;
        i++;
    }
}

int main(int argc, char *argv[])
{
    int l1Array[] = {1,2,3};
    struct ListNode *l1 = init(l1Array, sizeof(l1Array)/sizeof(l1Array[0]));
    printList(l1);
}

