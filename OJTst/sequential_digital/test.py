#!/usr/bin/python
# -*- coding: UTF-8 -*-
class Solution:
    dp = [12,23,34,45,56,67,78,89,
          123,234,345,456,567,678,789,
          1234,2345,3456,4567,5678,6789,
          12345,23456,34567,45678,56789,
          123456,234567,345678,456789,
          1234567,2345678,3456789,
          12345678,23456789,
          123456789];
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        pStart = 0;
        pEnd = len(self.dp)-1;
        rslt = [];
        while(self.dp[pStart]<low and  self.dp[pEnd]>high):
            pStart += 1;
            pEnd -= 1;
        while(pStart<= len(self.dp)-1 and self.dp[pStart]<low):
            pStart += 1;
        
        while(pEnd >=0 and self.dp[pEnd]>high):
            pEnd -= 1;
        while (pStart<=pEnd) :
            rslt.append(self.dp[pStart]);
            pStart += 1;
        return rslt;
