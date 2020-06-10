class Solution {
  public:
    int numTrees(int n) {
            vector<int> G(n+1,0);
            G[0]=G[1]=1;
            for(int i=2;i<=n;i++)
            {
                        for(int j=1;j<=i;j++)
                        {
                                        G[i]+=G[j-1]*G[i-j];
                                    }
                    }
            return G[n];
        }
};

/*
 *https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode/
 *   设：G(n)为n个数的结果
 *   有n个数：1,2,3,4,.....,i,........n
 *   取F(i,n)代表第i个数的可能性
 *   i的左半边G(i-1)个结果，i的右半边有G(n-i)
 *   则：F(i,n)=G(i-1)*G(n-i)，一个笛卡尔积结果
 *   G(n)为i的所有情况的集合，工时如下：
 *          i=1
 *    G(n)=  ∑ F(i,n)(1)
 *           n
 *   G(0)=1,G(1)=1
 *  可参考变种情况：https://baike.baidu.com/item/catalan/7605685?fr=aladdin
 */
