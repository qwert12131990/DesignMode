class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int status=0;
        //0 起始点
        //1 结束点
        vector<vector<int>> rslt;

        if (intervals.size()==0)
        {
            return vector<vector<int>>(1, newInterval);
        }

        int i=0;
        while(i<intervals.size())
        {
            if (status == 0)
            {
                int start = newInterval[0];
                if (start<intervals[i][0])
                {
                    rslt.push_back(newInterval);
                    status = 1;
                    continue;
                }
                if (start>=intervals[i][0] && start<=intervals[i][1])
                {
                    rslt.push_back(intervals[i]);
                    status = 1;
                    continue;
                }
                if (start > intervals[i][1])
                {
                    rslt.push_back(intervals[i]);
                    i++;
                }
            }
            else if (status == 1)
            {
                int end = newInterval[1];
                if (end<intervals[i][0])
                {
                    rslt[rslt.size()-1][1]=end;
                    rslt.push_back(intervals[i]);
                    status=-1;
                    i++;
                    continue;
                }
                if (end>=intervals[i][0] && end<=intervals[i][1])
                {
                    rslt[rslt.size()-1][1]=intervals[i][1];
                    i++;
                    status=-1;
                    continue;
                }
                if (end>intervals[i][1])
                {
                    rslt[rslt.size()-1][1]=end;
                    i++;
                    continue;
                }
            }
            else
            {
                rslt.push_back(intervals[i]);
                i++;
            }
        }

        if (status == 0)
        {
            rslt.push_back(newInterval);
        }
        
        return rslt;
    }
};
