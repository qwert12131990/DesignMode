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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> unvisited;
        unvisited.push(root);
        vector<int> ivec; 
        bool odd=true;

        for (TreeNode *p = root; unvisited.size();) {        
            int sz = unvisited.size();
            ivec.resize(sz);
            for (int idx = 0; idx != sz; ++idx) {
                p = unvisited.front();
                if (odd)
                {
                    ivec[idx] = p->val;
                }
                else
                {
                    ivec[sz-idx-1] = p->val;
                }
                

                if (p->left) {
                    unvisited.push(p->left);
                }
                if (p->right) {
                    unvisited.push(p->right);
                }

                unvisited.pop();
            }

            odd = !odd;

            result.push_back(move(ivec));
        }

        return result;
    }
};
