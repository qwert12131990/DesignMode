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
 * 状态解释：
 *  0：符号判断，在2种场景下，e之后的第一个元素和字符串的最开始
 *  2：小数判断，在小数和e之后不可行
 *  3：e判断，在e之后或者之前没有数字不可行
 * 特殊条件：
 *  3. .3  3.e1  .3e1都是支撑的形式，这种条件下对于e的状态情况，需判断nflag，即是否有数字
 *  对于小数在状态机内无法判断，因为存在“.”情况，所以需要在for条件后，处理为判断nflag是否false
 */
