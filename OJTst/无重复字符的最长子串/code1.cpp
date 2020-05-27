class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0;
        int pos[129];
        int start=0;

        for(int i=0; i<129; i++)
        {
            pos[i]=-1;
        }

        for(int i=0; i<s.size(); i++)
        {
            int tmp=s[i];
            if(pos[tmp]>=start && pos[tmp]<=i)
            {
                start=pos[tmp]+1;
                pos[tmp]=i;
                continue;
            }
            int cot=(i-start+1);
            max = max>cot?max:cot;
            pos[tmp]=i;
        }
        return max;
    }
};
