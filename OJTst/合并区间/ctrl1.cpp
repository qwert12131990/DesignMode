class Solution {
  public:
    static bool mycmp(vector<int>& a, vector<int>& b)
    {
            int i=a[0],j=b[0];
            return i<j;
        }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            std::sort(intervals.begin(), intervals.end(), Solution::mycmp);
            vector<vector<int>> rslt;
    
            if (intervals.size() <= 1)
            {
                        return intervals;
                    }
    
            rslt.push_back(intervals[0]);
    
            for(int i=1; i< intervals.size(); i++)
            {
                        vector<int>& tmp = rslt[rslt.size()-1];
                        if (intervals[i][1]<=tmp[1])
                        {
                                        continue;
                                    }
            
                        if (intervals[i][0]>tmp[1])
                        {
                                        rslt.push_back(intervals[i]);
                                        continue;
                                    }
            
                        tmp[1]=intervals[i][1];
                    }
    
            return rslt;
        }
};


