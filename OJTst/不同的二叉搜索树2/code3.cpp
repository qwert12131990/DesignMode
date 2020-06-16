/*代码优化版本*/
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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> tmp(n+1, vector<vector<TreeNode*>>(n+1,vector<TreeNode*>(0,NULL)));
        if (!n)
        {
            return vector<TreeNode*>(0);
        }
        return trees(1,n,0,true,tmp);
    }
    vector<TreeNode*> trees(int start, int end, int father, bool isleft, vector<vector<vector<TreeNode*>>>& tmp)
    {
        vector<TreeNode*> currRslt(0,NULL);
        vector<TreeNode*> left;
        vector<TreeNode*> right;

        if (start > end)
        {
            currRslt.push_back(NULL);
            return currRslt;
        }

        if (start == end)
        {
            TreeNode* currNode = new TreeNode(start);
            currRslt.push_back(currNode);
            return currRslt;
        }

        for(int i=start;i<=end;i++)
        {
            if (!isleft&&father&&tmp[father][i].size())
            {
                left=tmp[father][i];
            }
            else
            {
                left = trees(start,i-1,i,true,tmp);
            }

            if (isleft&&father&&tmp[i][father].size())
            {
                right=tmp[i][father];
            }
            else
            {
                right = trees(i+1,end,i,false,tmp);
            }

            for(int m=0;m<left.size();m++)
            {
                for(int n=0;n<right.size();n++)
                {
                    TreeNode* currNode=new TreeNode(i);
                    currNode->left=left[m];
                    currNode->right=right[n];
                    currRslt.push_back(currNode);
                    if (isleft)
                    {
                        tmp[i][father]=right;
                    }
                    else
                    {
                        tmp[father][i]=left;
                    }
                }
            }
        }
        return currRslt;
    }
};
