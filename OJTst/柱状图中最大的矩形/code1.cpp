class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
            int len=heights.size();
            int max=0;
            int min=2147483647;
    
            for(int i=1; i<=len; i++)
            {
                        for(int start=0;start<=len-i;start++)
                        {
                                        for(int j=start;j-start<i;j++)
                                        {
                                                            if (min>heights[j])
                                                            {
                                                                                    min=heights[j];
                                                                                }
                                                        } 
                                        if (max<min*i)
                                        {
                                                            max=min*i;
                                                        }
                                        min=2147483647;
                                    }
                        
                    }
            return max;
        }
};

/*
 *暴力解法
 */
