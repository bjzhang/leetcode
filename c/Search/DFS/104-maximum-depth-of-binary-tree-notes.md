
eventually finish it after 260 minuts.

try to count the tree in the beginning. I found that it is useless. And after 180 minutes trying.

I try to modify the value of leaf to the depth of child plus one. it works. but I miss the 'else' in the first submission which lead to fail in [1, 2, 3, 4, 5].

```
	if (root->left && root->right)
		root->val = ((root->left->val > root->right->val) ? root->left->val : root->right->val) + 1;
	else if (root->left)
		root->val = root->left->val + 1;
	else if (root->right)
		root->val = root->right->val + 1;
```
