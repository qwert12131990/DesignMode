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
    bool isSymmetric(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        return isSymmetricDetail(root->left, root->right);
    }

    bool isSymmetricDetail(TreeNode *left, TreeNode * right)
    {
        bool condition = true;

        if (left == right)
        {
            return true;
        } 
        
        if (!left || !right )
        {
            return false;
        }

        if (left->val != right->val)
        {
            return false;
        }

        return isSymmetricDetail(left->right, right->left) && isSymmetricDetail(left->left, right->right);
    }
};
