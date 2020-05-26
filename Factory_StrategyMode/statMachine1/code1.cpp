class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> rslt;
            bool findflag = false;
            bool findstartflag = false;
    
            if (intervals.size() == 0)
            {
                        return vector<vector<int>>(1, newInterval);
                    }
    
            int i=0;
            for(; i<intervals.size() && !findflag;i++)
            {
                        if (newInterval[0] > intervals[i][1])
                        {
                                        cout <<0<<endl;
                                        rslt.push_back(intervals[i]);
                                        continue;
                                    }
            
            
                        for(int j=0;j<=1;j++)
                        {
                                        if (findstartflag == true)
                                        {
                                                            j=1;
                                                        }
                                        cout<<"i:"<<i<<"j:"<<j<<endl;
                                        cout<<newInterval[j]<<" "<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
                                        if (newInterval[j] < intervals[i][0])
                                        {
                                                            if (j==0)
                                                            {
                                                                                    cout <<1<<endl;
                                                                                    rslt.push_back(newInterval);
                                                                                    findstartflag = true;
                                                                                }
                                                            else
                                                            {
                                                                                    cout <<2<<endl;
                                                                                    rslt[rslt.size()-1][j]=newInterval[j];
                                                                                    rslt.push_back(intervals[i]);
                                                                                    findflag = true;
                                                                                } 
                                                            continue;
                                                        }
                        
                                        if (newInterval[j] <= intervals[i][1] && newInterval[j] >= intervals[i][0])
                                        {
                                                            if (j==0)
                                                            {
                                                                                    cout <<3<<endl;
                                                                                    rslt.push_back(intervals[i]);
                                                                                    findstartflag = true;
                                                                                }
                                                            else
                                                            {
                                                                                    cout <<4<<endl;
                                                                                    rslt[rslt.size()-1][j]=intervals[i][j];
                                                                                    findflag = true;
                                                                                }
                                                            continue;
                                                        }
                                    }
                    }
    
            for(; i<intervals.size() && findflag;i++)
            {
                        rslt.push_back(intervals[i]);
                    }
    
            return rslt;
        }
};
