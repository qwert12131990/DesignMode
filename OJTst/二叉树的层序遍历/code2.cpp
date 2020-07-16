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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> unvisited;
        unvisited.push(root);
        vector<int> ivec; 
        for (TreeNode *p = root; unvisited.size();) {        
            int sz = unvisited.size();
            ivec.resize(sz);
            for (int idx = 0; idx != sz; ++idx) {
                p = unvisited.front();
                ivec[idx] = p->val;
                if (p->left) {
                    unvisited.push(p->left);
                }
                if (p->right) {
                    unvisited.push(p->right);
                }
                unvisited.pop();
            }
            result.push_back(move(ivec));
        }

        return result;
    }
};

/*
 * 好处显而易见，可以有效消除标志变量，比如下一行的数量，当前行的数量，减少判断数量，减少内存占用和时间消耗
 */
