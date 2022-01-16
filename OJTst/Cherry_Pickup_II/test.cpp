#include <iostream>
#include <algorithm>
#include <vector>

/*
原理其实很见到，动态规划，
三维数组，[i][j][k], robot0从00到ij，和robot1从0n-1到ik
状态转移 总共9个。3*3，其中robot0状态跳转由3种，robot1同理，因此总共9种。


*/

using namespace std;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int rslt = 0;
        int path[m][n][n];
        memset(path, 0, sizeof(path));
        path[0][0][n-1] = grid[0][0] + grid[0][n-1];
        for(int i=1;i<m;i++){
            int lasti = i-1;
            //cout<<"i:"<<i<<" lasti:"<<lasti<<endl;
            int startk = max(n-i-1, 0);
            int endj   = min(i,n-1);
            for(int j=0;j<=n-1;j++){            
                //cout<<"j:"<<j<<endl;
                for(int k=n-1; k>=startk ;k--){
                    //cout<<"k:"<<k<<endl;
                    if (j==k){
                        continue;
                    }
                    int maxval = 0;
                    int currij = grid[i][j]+grid[i][k];
                    int starta = max(j-1, 0);
                    int enda   = min(j+1, n-1);
                    enda = min(enda, lasti);      
                    //cout<<"starta:"<<starta<<" enda"<<enda<<endl;
                    while(starta<=enda){
                        //cout<<"0<="<<starta<<"<="<<lasti<<endl;  
                        int startb = max(k-1, 0);
                        int endb   = min(k+1,   n-1);
                        startb = max(startb, n-lasti-1);
                        //cout<<"startb:"<<startb<<" endb"<<endb<<endl;                            
                        while(startb<=endb){
                            //cout<<n<<">"<<startb<<">="<<n-lasti-1<<endl;
                            if (starta != startb){
                                maxval = max(path[lasti][starta][startb] + currij, maxval);
                                //cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<":"<<maxval<<endl;
                            }
                            startb++;
                        }
                        starta++;
                    }
                    path[i][j][k] = maxval;                 
                    rslt = max(path[i][j][k], rslt);
                }
            }
        }

        return rslt;
    }
};