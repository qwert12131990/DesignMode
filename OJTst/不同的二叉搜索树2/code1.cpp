/*Definition for a binary tree node.
 * struct TreeNode {
 *      int val;
 *      TreeNode *left;
 *      TreeNode *right;
 *      TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
**/
class Solution {
  public:
    vector<TreeNode*> generateTrees(int n) {
    
            return trees(1,n);
        }
    vector<TreeNode*> trees(int start, int end)
    {
            vector<TreeNode*> currRslt(0,NULL);
            vector<TreeNode*> left;
            vector<TreeNode*> right;
    
            if (start == -1)
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
                        if (start == i)
                        {
                                        left = trees(-1,-1);
                                    }
                        else
                        {
                                        left = trees(start,i-1);
                                    }
            
                        if (end == i)
                        {
                                        right = trees(-1,-1);
                                    }
                        else
                        {
                                        right = trees(i+1,end);
                                    }
                        
                        for(int m=0;m<left.size();m++)
                        {
                                        for(int n=0;n<right.size();n++)
                                        {
                                                            TreeNode* currNode=new TreeNode(i);
                                                            currNode->left=left[m];
                                                            currNode->right=right[n];
                                                            currRslt.push_back(currNode);
                                                        }
                                    }
                    }
    
            return currRslt;
        }


};


/*
 * 原理：递归处理
 * 假设当前i位置上，则左边有i-start个元素构成left个情况
 * 右边有end-i个元素构成right个情况
 * 以当前i位置的节点作为根节点，则有left*right中情况
 *
 *
