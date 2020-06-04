/**
Definition for a binary tree node.
 * struct TreeNode {
   *  *     int val;
   *   *     TreeNode *left;
   *    *     TreeNode *right;
   *     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   *      * };
*       */
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
            vector<int> rslts;
            if(root)
            {
                        inorderDetail(root, rslts);
                    }
            return rslts;
        }

    void inorderDetail(TreeNode* root, vector<int>& rslts)
    {
            if(root)
            {
                        inorderDetail(root->left, rslts);
                        rslts.push_back(root->val);
                        inorderDetail(root->right, rslts);
                    }
            return;
        }
};
