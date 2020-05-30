class Solution {
public:
    string& trim(string &s) 
    {
        if (s.empty()) 
        {
            return s;
        }
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }

    bool isNumber(string s) {
        string str=s;
        str=trim(str);

        if (str.size()==0)
        {
            return false;
        }
        return test(str);
    }

    bool test(string& str)
    {
        int len=str.size();
        bool sflag=false;
        bool decflag=false;
        bool eflag=false;
        bool nflag=false;
        int status=1;
        /*
            0: +-
            1: cmp
            2: .
            3: e
         */
        
        for(int i=0;i<len;)
        {
            switch(status)
            {
                case 0:
                {
                    if ((eflag==true && sflag==false)  || i==0)
                    {
                        i++;
                        sflag=true;
                        status=1;
                        break;
                    }
                    return false;
                }
                case 2:
                {
                    if (decflag == false && eflag == false)
                    {
                        status=1;
                        i++;
                        decflag=true;
                        break;      
                    }
                    return false;
                }
                case 3:
                {
                    if (eflag == false && nflag==true)
                    {
                        status=1;
                        i++;
                        eflag=true;
                        nflag=false;
                        sflag=false;
                        break;
                    }
                    return false;
                }
                case 1:
                {
                    if (((unsigned int)(str.at(i)-'0'))<=9)
                    {
                        i++;
                        nflag=true;
                        sflag=true;
                        break;
                    }
                    if (str.at(i)=='+' || str.at(i)=='-')
                    {
                        status=0;
                        break;
                    }
                    if (str.at(i)=='.')
                    {
                        status=2;
                        break;
                    }
                    if (str.at(i)=='e')
                    {
                        status=3;
                        break;
                    }
                    return false;                        
                }
            }
        }

        if (eflag==true && nflag==false)
        {
            return false;
        }
        if (decflag==true && nflag==false)
        {
            return false;
        }

        return true;
    }
};

/*
 *状态机
 *将状态分为
 *    0: +-
 *    1: cmp
 *    2: .
 *    3: e
 * 状态转移图：
 * ->1---------0
 *   |    \    
 *   2         3
 *  
 */
