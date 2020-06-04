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
