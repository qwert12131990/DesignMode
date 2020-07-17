/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return maxDepth_detail(root, 1);
    }

    int maxDepth_detail(TreeNode *root, int i)
    {
        int left = i;
        int right = i;

        if (root->left)
            left = maxDepth_detail(root->left, i+1);

        if (root->right)
            right = maxDepth_detail(root->right, i+1);
        
        return left>right?left:right;
    }
};
