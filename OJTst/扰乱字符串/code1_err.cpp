class Solution {
public:
    bool isScramble(string s1, string s2) {
        vector<list<int>> dicts;
        vector<int> poss;
        dicts.resize(256);

        for(int i=0;i<s1.size(); i++)
        {
            dicts[s1[i]].push_back(i);
        }

        return isScrambleDetail(s2, 0,s2.size()-1, 512, poss, dicts);
    }


    bool isScrambleDetail(string& s, int start, int end, int max, vector<int>& spos, vector<list<int>>& dicts)
    {
        char c= s[start];
        bool rslts=false;
        list<int>& tmp=dicts[c];

        cout<<"start: "<<start<<" max: "<<max<<endl; 

        for(list<int>::iterator it=tmp.begin(); it!=tmp.end();it++)
        {
            cout<<"it: "<<*it<<endl;
            if (*it == -1)
            {
                continue;
            }
            cout<<"spos.size(): "<<spos.size()<<endl;
            vector<int> bkpos=spos;
            int maxbk=max;
            if (spos.size())
            {
                
                int sPosBack=spos.back();
                cout<<"sPosBack: "<<sPosBack<<endl;
                if (*it <sPosBack)
                {
                    if (max<=sPosBack)
                    {
                        return false;
                    }
                    else
                    {
                        max=sPosBack;
                        spos.clear();
                    }
                }
            }
            spos.push_back(*it);
            if (start<end)
            {
                int bk=*it;
                *it=-1;
                rslts= rslts || isScrambleDetail(s, start+1, end, max, spos, dicts);
                *it=bk;
                spos=bkpos;
                max=maxbk;
            }
            else
            {
                rslts= rslts || true;
            }

        }

        return rslts;
    }

    
};
/*
            
            
            


*/
