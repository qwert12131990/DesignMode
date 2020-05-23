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
