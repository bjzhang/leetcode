
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *init(int *nums, int len)
{
    struct ListNode *node;
    struct ListNode *head;
    struct ListNode *prev = NULL;

    int i;
    for(i = 0; i < len; i++) {
        node = (struct ListNode*)malloc(sizeof(struct ListNode));
	if (prev == NULL) { 
		head = node;
	}
        if (prev != NULL) {
            prev->next = node;
        }
        node->val = nums[i];
        prev = node;
    }
    return head;
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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l1Orig = l1;
    struct ListNode* cur = NULL;
    struct ListNode* temp;

    printf("mergeTwoLists:\n");
    while(l1 != NULL && l2 != NULL) {
        if(l1->val > l2->val) {
            if(cur==NULL) {
                cur = l2;
                l2 = l2->next;
            } else {
                temp = cur->next;
                cur->next=l2;
                l2 = l2->next;
                cur = cur->next;
            }
        } else {
            if(cur==NULL) {
                cur = l1;
                l1 = l1->next;
            } else {
                temp = cur->next;
                cur->next=l1;
                l1 = l1->next;
                cur = cur->next;
            }
        }
    }
    if (l2 != NULL)  {
        cur->next = l2;
    }
    return l1Orig;
}

int main(int argc, char *argv[])
{
    int l1Array[] = {1,2,4};
    int l2Array[] = {1,3,4};
    struct ListNode *l1 = init(l1Array, sizeof(l1Array)/sizeof(l1Array[0]));
    struct ListNode *l2 = init(l2Array, sizeof(l2Array)/sizeof(l2Array[0]));
    printList(l1);
    printList(l2);
    printList(mergeTwoLists(l1, l2));

    return 0;
}

