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
        vector<vector<int>> rslts;
        list<TreeNode*> tmp;
        int numPerline = 1;
        int posCurline = 0;
        int numPernextline = 0;
        if (!root)
        {
            return rslts;
        }

        tmp.push_back(root);
        rslts.push_back(vector<int>());

        while(!tmp.empty())
        {
            
            TreeNode* ptmp = tmp.front();
            tmp.pop_front();

            rslts[posCurline].push_back(ptmp->val);
            numPerline--;
            
            if(ptmp->left)
            {
                tmp.push_back(ptmp->left);
                numPernextline++;
            }

            if (ptmp->right)
            {
                tmp.push_back(ptmp->right);
                numPernextline++;
            }

            if (numPerline == 0)
            {
                if (numPernextline)
                {
                    rslts.push_back(vector<int>());
                }

                numPerline = numPernextline;
                posCurline++;
                numPernextline = 0;
            }
        }

        return rslts;
    }

};
