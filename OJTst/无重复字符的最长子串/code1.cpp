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

/*
 * 原理：滑动窗口，start和i表示窗口范围
 *  每次判断当前是否重复，若是重复则更新窗口大小，由于一定不大于
 *  上次窗口大小，所以不需要更新最大值，
 *
 *  每次更新最大值的条件为当前元素不重复或者重复但不在窗口范围内
 *
 */ 
