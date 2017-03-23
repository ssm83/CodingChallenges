#include <iostream>
#include <stack>
using namespace std;
    
/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
int minDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right != NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL && root->left != NULL)
        return 1 + minDepth(root->left);
    return min(1 + minDepth(root->left), 1 + minDepth(root->right));
}

int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;
    return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
}


/*    10
     /  \
    20   30 
   / \    \
  40  60   80
       \    \
       100  120
            /
          150
*/

int main() {
	// your code goes here
	TreeNode *t = new TreeNode(10);
	t->left = new TreeNode(20);
	t->left->right = new TreeNode(60);
	t->left->right->right = new TreeNode(100);
	t->right = new TreeNode(30);
	t->right->right = new TreeNode(80);
	t->right->right->right = new TreeNode(120);
	t->right->right->right->left = new TreeNode(150);
	t->left->left = new TreeNode(40);
	cout << "MaxDepth: " << maxDepth(t) << endl;
	cout << "MinDepth: " << minDepth(t) << endl;

	return 0;
}
