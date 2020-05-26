class Algo;
class StartAlgo;
class EndAlgo;

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
                    //rslt.push_back(intervals[i]);
                    status = -1;
                    //i++;
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
                status=0;
                i++;
                //找不到还没找完
                //找不到还找完了
                //找到了还找完了
            }
        }

        if (status == 0)
        {
            rslt.push_back(newInterval);
        }
        
        return rslt;
    }
    int getCurrInterval()
    {
        return i;
    }
    void setCurrInterval(int i)
    {
        this->i=i;
    }

    void changeStatus(int status)
    {
        switch(status)
        {
            case 0:
                //algo=strAlgo;
                break;
            case 1:
                //algo=endAlgo;
            case -1:
                //algo=&addAlgo;
            default:
                break;
        }
    }
private:
    Algo *algo;
    //StartAlgo *strAlgo;
    //EndAlgo   *endAlgo;
    //AddAlgo   addAlgo;
    int i;
};

class Algo
{
private:
    Solution *psolver;
public:
    Algo(Solution *psolver)
    {
        this->psolver = psolver;
    }

    virtual void insert(vector<vector<int>>& intervals, vector<int>& newInterval, vector<vector<int>>& rslt) =0;

    Solution* getSolution()
    {
        return psolver;
    }
};

class StartAlgo : public Algo
{
public:
    StartAlgo(Solution *psolver):Algo(psolver) {}
    
    void insert(vector<vector<int>>& intervals, vector<int>& newInterval, vector<vector<int>>& rslt)
    {
        Solution* psolver = getSolution();
        
        int i = psolver->getCurrInterval();
        int start = newInterval[0];

        if (start<intervals[i][0])
        {
            rslt.push_back(newInterval);
            psolver->changeStatus(1);
            return;
        }
        if (start>=intervals[i][0] && start<=intervals[i][1])
        {
            rslt.push_back(intervals[i]);
            psolver->changeStatus(1);
            return;
        }
        if (start > intervals[i][1])
        {
            rslt.push_back(intervals[i]);
            psolver->setCurrInterval(i+1);
            return;
        }
        return;
    }
};

class EndtAlgo : public Algo
{
public:
    EndtAlgo(Solution *psolver):Algo(psolver) {}
    
    void insert(vector<vector<int>>& intervals, vector<int>& newInterval, vector<vector<int>>& rslt)
    {
        Solution* psolver = getSolution();
        
        int i = psolver->getCurrInterval();
        int end = newInterval[1];

        if (end<intervals[i][0])
        {
            rslt[rslt.size()-1][1]=end;
            rslt.push_back(intervals[i]);

            psolver->changeStatus(-1);
            psolver->setCurrInterval(i+1);

            return;
        }
        if (end>=intervals[i][0] && end<=intervals[i][1])
        {
            rslt[rslt.size()-1][1]=intervals[i][1];

            psolver->setCurrInterval(i+1);
            psolver->changeStatus(-1);

            return;
        }
        if (end>intervals[i][1])
        {
            rslt[rslt.size()-1][1]=end;

            psolver->setCurrInterval(i+1);

            return;
        }
    }
};

class AddAlgo : public Algo
{
public:
    AddAlgo(Solution *psolver):Algo(psolver) {}
    
    void insert(vector<vector<int>>& intervals, vector<int>& newInterval, vector<vector<int>>& rslt)
    {
        Solution* psolver = getSolution();
        
        int i = psolver->getCurrInterval();

        rslt.push_back(intervals[i]);
        psolver->setCurrInterval(i+1);
        psolver->changeStatus(0);
    }
};
