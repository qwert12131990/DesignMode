class Solution {
  public:
    int uniquePaths(int m, int n) {
            vector<vector<int>> tmp(m,vector<int>(n,0));
            return test(0,0,m-1,n-1,tmp);
        }
    int test(int i,int j,int m, int n, vector<vector<int>>& tmp)
    {
            int a,b;
            a=b=0;
    
            if (tmp[i][j]!=0)
            {
                        return tmp[i][j];
                    }
    
            if(i==m && j==n)
            {
                        return 1;
                    }
    
            if(i<m)
            {
                        a=test(i+1,j,m,n,tmp);
                    }
    
            if(j<n)
            {
                        b=test(i,j+1,m,n,tmp);
                    }
    
            tmp[i][j]=a+b;
    
            return tmp[i][j];
        }

};


/*
 * 原理：递归+剪枝
 * 递归算出当前位置到目标位置的路径个数
 * 剪枝除掉被遍历过得位置
 * /
