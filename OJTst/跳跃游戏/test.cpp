class Solution {
  public:
    bool canJump(vector<int>& nums) {
            int max=0;
    
            for(int i=0; i<nums.size()-1 && max >= i ;i++)
            {
                        int nextpos = nums[i]+i;
            
                        if (nums[i] ==0 && max == nextpos)
                        {
                                        return false;
                                    }
            
                        max = max>nextpos?max:nextpos;
            
                        if (max >= nums.size()-1)
                        {
                                        return true;
                                    }
                    }
    
            return max >= nums.size()-1;
        }

};
/*
 *贪心算法
 *跳跃中每个元素，包含两部分
 * 1、要求当前元素是否可被到达
 * 2、当前元素可跳跃多远
 *
 *因此，对于1条件，我们要计算出当前元素前可跳远的最大值，对于
 *2条件，我们提供计算最大值的跳远数
 *所以，max = max>nextpos?max:nextpos;为关键语句
 *
 *
 */
