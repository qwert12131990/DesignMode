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
/* 逻辑证明如下：
.............
.


.............
 .

.............
            .


.............
               .

--------------------------------------

.............
    .

.............
            .

.............
              .


11\12 d
13 u

21\22 d
23 u

33 u

43 no

排序后递进关系
*/






