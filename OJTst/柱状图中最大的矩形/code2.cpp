class Solution {
  public:
    int largestRectangleArea(vector<int>& heights) {
            int max=0;
    
            for(int i=0;i<heights.size();i++)
            {
                        int min=heights[i];
                        
                        for(int j=i;j<heights.size();j++)
                        {
                                        min=min<heights[j]?min:heights[j];
                                        int tmp=min*(j-i+1);
                                        max=max>tmp?max:tmp;
                                    }
                    }
            return max;
        }
};

/*
 * 如果我们枚举「宽」，我们可以使用两重循环枚举矩形的左右边界以固定宽度 ww，
 * 此时矩形的高度 hh，就是所有包含在内的柱子的「最小高度」，对应的面积为 w * hw∗h。
 * 下面给出了这种方法的 C++ 代码。
 */
