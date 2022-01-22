class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        return bfs(n, 1, dp);
    }
    
    bool bfs(int n, int level, int dp[]){
        bool rslt0 = false;
        bool rslt1 = true;
        
        //cout<<"n:"<<n<<" level:"<<level<<endl;
        
        if (n == 0){
            return false;
        }
        
        //cout<<"dp["<<n<<"]:"<<dp[n]<<endl;
        if (level == 1 && dp[n] == 1){
            return true;                
        }
        else if (level == 0 && dp[n] == 0){
            return false;
        }
        
        for(int i=1; i*i<=n; i++){
            bool tmpRslt = bfs(n-i*i, level ^ 0x1, dp);
            rslt1 &= tmpRslt;
            rslt0 |= tmpRslt;
            //cout<<"i:"<<i*i<<" n:"<<n<<" level:"<<level<<" oper:"<<tmpRslt<<endl;
            //cout<<"rslt1:"<<rslt1<<" rslt0:"<<rslt0<<endl;
            if (level == 0x1){
                if (rslt1 == false){
                    //cout<<"dp["<<n<<"]=1"<<endl;
                    dp[n] = 1;
                    return true;
                }
            }
            else if (level == 0x0){
                if (rslt1 != rslt0 ){
                    return true;
                }
            }
        }
        if ((level == 0x1) && rslt1 == true){
            //cout<<"dp["<<n<<"]=0"<<endl;
            dp[n] = 0;
            return false;
        }
        if (level == 0x0){
            if (rslt1 == true){
                //cout<<"dp["<<n<<"]=0"<<endl;
                dp[n] = 0;
                return false;
            }
            else if (rslt0 == false){
                //cout<<"dp["<<n<<"]=0"<<endl;
                //dp[n] = 0;
                return true;
            }
        }
        
        
        return false;
    }

};