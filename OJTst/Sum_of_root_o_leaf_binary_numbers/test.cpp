#include <iostream>
#include <algorithm>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumRoot2Leaf_detail(root, 0); 
    }

    int sumRoot2Leaf_detail(TreeNode* root, int i){
        int tmpRslt     = i;
        int leftRslt    = 0;
        int rightRslt   = 0;

        tmpRslt = (tmpRslt << 1) + root->val;
        if (root->left == NULL && root->left == NULL){
            return tmpRslt;
        }
        if (root->left){
            leftRslt  = sumRoot2Leaf_detail(root->left,  tmpRslt);
        }
        if (root->right){
            rightRslt = sumRoot2Leaf_detail(root->right, tmpRslt);
        }
        return leftRslt + rightRslt;
    }
};