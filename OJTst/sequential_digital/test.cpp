#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //vector<int> rslt;
        int pStart = 0;
        int pEnd   = dp.size()-1;
        while(dp[pStart]<low && dp[pEnd]>high){
            pStart++;
            pEnd--;
        }
        while(pStart<= dp.size()-1 && dp[pStart]<low){
            pStart++;
        }
        while(pEnd >=0 && dp[pEnd]>high){
            pEnd--;
           }

        return vector<int>(dp.begin()+pStart, dp.begin()+pEnd+1);    
            
        /*for(int i=0; i< dp.size(); i++){
            if (dp[i]>=low && dp[i]<=high){
                rslt.push_back(dp[i]);
            }
        }
        return rslt;*/
    }
private:
    vector<int> dp = { 12,23,34,45,56,67,78,89,
                       123,234,345,456,567,678,789,
                       1234,2345,3456,4567,5678,6789,
                       12345,23456,34567,45678,56789,
                       123456,234567,345678,456789,
                       1234567,2345678,3456789,
                       12345678,23456789,
                       123456789};
};