#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
/**
  Definition for a binary tree node.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root){
            insert_detail(root, val);
        }
        else {
            TreeNode *p_tmp = new TreeNode(val);
            root = p_tmp;
        }
        return root;
    }
    
    void insert_detail(TreeNode* root, int val){
        
        if (val < root->val){
            if (root->left){
                insert_detail(root->left,  val);            
            }
            else {
                TreeNode *p_tmp = new TreeNode(val);
                root->left = p_tmp;
            }
        }
        else {
            if (root->right){
                insert_detail(root->right, val);            
            }
            else {
                TreeNode *p_tmp = new TreeNode(val);
                root->right = p_tmp;
            }
        }

    }
};