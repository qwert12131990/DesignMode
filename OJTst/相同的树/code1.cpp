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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q)
        {
            bool condition = true;
            condition = condition && isSameTree(p->left,q->left);
            condition = condition && (p->val == q->val);
            condition = condition && isSameTree(p->right,q->right);
            return condition;
        }
        if (!p && !q)
        {
            return true;
        }
        return false;
    }
};
