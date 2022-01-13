#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
区间对比，用于确认区间的相交、包含、无关关系，并在此基础上比较区间的大小，相等
1、包含
（1）                   （2）                        (3)                         (4)                       (5)
---------------------       ---------------------       ----------------------      --------------------      --------------------   
--------                            -------------           --------------            ---------                        ---------
2、相交
（1）                   （2）                        (3)                         (4)
    -----------------       -------------               --------------                    --------------
--------                             -----------           -------------                --------------
3、无关、互斥
（1）                   （2）                        (3)                         (4)
----------                  -------                             --------                        ----------
          ----------                   ---------         -------                    -------
*/

/*
代码处理策略未sort排序
先根据其右边界有小到大排序队列，在遍历队列左边界，
1）如果左边界比排序后的右边界大，则该区间为无关
2）如果左边界比排序后的右边界等，则该区间为互斥
3）如果左边界比排序后的右边界小，则该区间为相交
*/

//代码如下

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for (const vector<int>& balloon: points) {
            if (balloon[0] > pos) {
                //todo 无关   
            }
            else if (balloon[0] == pos){
                //todo 互斥
            }
            else if (balloon[0] < pos){
                //todo 相交或包含
                if(balloon[1] < pos){
                    //todo 包含
                }
                else if (balloon[1] > pos){
                    //todo 相交
                }
                else if (balloon[1] == pos){
                    //todo 包含
                }
            }
        }
        return ans;
    }
};