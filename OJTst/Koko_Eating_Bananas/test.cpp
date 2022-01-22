#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        double step = 1;
        int n = piles.size();
        int cnt = 0;
        bool flag = 0;
        while(cnt != h){
            cnt = 0;
            for(int i=0; i<n; i++){
                int tmpcnt = ceil((double)(piles[i])/step); 
                cnt += tmpcnt;
            }
            if (cnt < h && flag == 0){
                flag = 1;
                step /= 2;
            }
            
            if (cnt != h){
                if (flag == 0){
                    step *= 2;
                }
                else {
                    step++;
                }
            }
        }

        return step;
    }
};