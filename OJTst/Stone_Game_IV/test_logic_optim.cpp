class Solution {
public:
    bool winnerSquareGame(int n) {
        int dp[n+6];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 0;
        dp[3] = 1;
        dp[4] = 1;
        dp[5] = 0;
        return bfs(n, 1, dp);
    }
    
    bool bfs(int n, int level, int dp[]){
        bool rslt0 = false;
        bool rslt1 = true;
        
        if (dp[n] != -1){
            if (level == dp[n]){
                return dp[n];
            }
            return dp[n];
        }
        
        for(int i=1; i*i<=n; i++){
            bool tmpRslt = bfs(n-i*i, level ^ 0x1, dp);
            rslt1 &= tmpRslt;
            rslt0 |= tmpRslt;
            if (level == 0x1 && rslt1 == false){
                dp[n] = 1;
                return true;
            }
            else if (level == 0x0){
                if (rslt1 != rslt0 ){
                    return true;
                }
            }
        }
        if (rslt1 == false){
            return true;
        }
        dp[n] = 0;
        return false;
    }

};