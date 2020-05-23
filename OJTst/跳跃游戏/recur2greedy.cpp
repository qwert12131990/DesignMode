class Solution {
  public:
    bool canJump(vector<int>& nums) {
            bool rslt = false;
            vector<int> tmp(nums.size(), 0);
    
            rslt = Jump(nums, 0, tmp);
    
            return rslt;
        }
    bool Jump(vector<int>& nums, int currpos, vector<int>& tmp)
    {
            bool rslt = false;
    
            if (currpos >= nums.size()-1)
            {
                        return true;
                    }
    
            int nextMaxpos = std::min(currpos+nums[currpos], static_cast<int>(nums.size())-1);
            if (nextMaxpos == static_cast<int>(nums.size())-1)
            {
                        return true;
                    }
    
            for(int i=nextMaxpos; i>currpos && !rslt; i--)
            {
                        rslt = tmp[i]==-1?false:Jump(nums, i, tmp);
                    }
    
            if (rslt == false)
            {
                        tmp[currpos] = -1;
                    }
    
            return rslt;
        }

};

/*
 *贪心+递归+剪枝
 *
 *
 *
 */
