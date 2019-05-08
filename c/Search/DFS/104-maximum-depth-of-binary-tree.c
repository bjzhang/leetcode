#include <stdio.h>
#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void countTree(struct TreeNode *root, int *cnt) {
	if (!root)
		return;
	(*cnt)++;

	printf("%d, 0x%p\n", *cnt, root);
	if (root->left) {
		countTree(root->left, cnt);
	}
	if (root->right) {
		countTree(root->right, cnt);
	}
}

void maxDepthCur(struct TreeNode *root)
{
	int curCnt;
	if (!root) {
		return;
	}

	root->val = 1;

	if (root->left) {
		maxDepthCur(root->left);
	}
	if (root->right) {
		maxDepthCur(root->right);
	}
	if (root->left && root->right)
		root->val = ((root->left->val > root->right->val) ? root->left->val : root->right->val) + 1;
	else if (root->left)
		root->val = root->left->val + 1;
	else if (root->right)
		root->val = root->right->val + 1;
}

void visitTree(struct TreeNode *root) {
	if (!root)
		return;

	printf("%p, %d\n", root, root->val);

	if (root->left) {
		visitTree(root->left);
	}
	if (root->right) {
		visitTree(root->right);
	}
}

int maxDepth(struct TreeNode* root){
	int cnt= 0;
	int *depth;
	int i;

	if (!root)
		return 0;

	maxDepthCur(root);
	return root->val;
}

//3, 9, 20, -1, -1, 15, 7
int main(int argc, char *argv[])
{
	int i;
	struct TreeNode *root;
	struct TreeNode *origin;

	root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	memset(root, 0, sizeof(struct TreeNode));
	origin = root;
	root->val = 1;
	root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	memset(root->left, 0, sizeof(struct TreeNode));
	root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	memset(root->right, 0, sizeof(struct TreeNode));
	root->left->val = 2;
	root->right->val = 3;
	root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	memset(root->left->left, 0, sizeof(struct TreeNode));
	root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	memset(root->left->right, 0, sizeof(struct TreeNode));
	root->left->left->val = 4;
	root->left->right->val = 5;

	maxDepth(root);
	visitTree(root);
}
