
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
    struct ListNode* node;
    struct ListNode* head = NULL;

    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    head = node;
    printf("mergeTwoLists:\n");
    while(l1!=NULL && l2!=NULL) {
        if(l1->val > l2->val) {
            node->val = l2->val;
            l2=l2->next;
        } else {
            node->val = l1->val;
            l1=l1->next;
        }
        if(l1!=NULL || l2 != NULL) { 
            node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            node = node->next;
        }
    }
    while(l1!=NULL) {
        node->val = l1->val;
        l1=l1->next;
        if(l1 != NULL) {
            node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            node = node->next;
        }
    }
    while(l2!=NULL) {
        node->val = l2->val;
        l2=l2->next;
         if(l2 != NULL) {
            node->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            node = node->next;
        }
    }
    return head;
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

