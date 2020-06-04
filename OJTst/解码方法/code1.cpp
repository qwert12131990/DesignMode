class Solution {
  public:
    int numDecodings(string s) {
            vector<int> vcont(s.size(), -1);
            return numDecode(s,0,vcont);
        }

    int numDecode(string& s, int start, vector<int>& vcont)
    {
            if (start==s.size())
            {
                        return 1;
                    }
    
            if (vcont[start]!=-1)
            {
                        return vcont[start];
                    }
    
            if (s[start]=='0')
            {
                        return 0;
                    }
    
            int sum=0;
            string stmp="";
    
            for(int i=start;i-start<2 && i<s.size();i++)
            {
                        stmp+=s[i];
                        int itmp=atoi(stmp.c_str());
            
                        if (itmp<=26 && itmp>0)
                        {
                                        sum+=numDecode(s,i+1,vcont);
                                    }
                    }
            vcont[start]=sum;
            return sum;
        }
};
/*
 *道理：递归+辅助矩阵
 *递归实现对所有情况的遍历
 *辅助矩阵记录当前已经遍历并确认有几种解码的个数
 *  若是再次访问当前节点，直接读取辅助矩阵中记录个数即可。
 *
 *
 *
