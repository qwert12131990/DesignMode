class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
            string rslt;
            vector<string> rslts;
            test(s, 0, rslt, rslts, 0);
            return rslts;
        }

    void test(string& s, int start, string& rslt, vector<string>& rslts, int ncount)
    {
            if (ncount==4)
            {
                        if (start==s.size())
                        {
                                        rslt.erase(rslt.end()-1);
                                        rslts.push_back(rslt);
                                    }
                        return;
                    }
    
            string tt="";
            int sum=0;
            for(int i=start; i-start<3 && i<s.size(); i++)
            {
                        tt+=s[i];
                        if (tt.size()>=2 &&  tt[0]=='0')
                        {
                                       return;
                                    }
                        sum=atoi(tt.c_str());
                        if (sum<=255)
                        {
                                        string tmp=rslt;
                                        rslt+=tt;
                                        rslt+='.';
                                        test(s, i+1, rslt, rslts, ncount+1);
                                        rslt=tmp;
                                    }
                    }
    
            return;
    
        }
};

/*
 *递归处理+状态重置
 *可以考虑剪枝
 *
 *
 *
 *
 */
