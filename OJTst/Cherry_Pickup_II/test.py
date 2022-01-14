class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        rslt = 0;
        m = len(grid);
        n = len(grid[0]);
        path = [[[0]*n for _ in grid[0]] for _ in grid];
        path[0][0][n-1] = grid[0][0] + grid[0][n-1];

        for i in range(1,m):
            lasti = i-1;
            startk = max(n-i-1, 0);
            endj   = min(1, n-1);
            for j in range(0,n):
                for k in range(startk, n):
                    if j == k :
                        continue;
                    maxval = 0;
                    currij = grid[i][j] + grid[i][k];
                    starta = max(j-1, 0);
                    enda   = min(j+1, n-1, lasti);
                    while starta<=enda:
                        startb = max(k-1,0,n-lasti-1);
                        endb   = min(k+1, n-1);
                        while startb <= endb:
                            if starta != startb:
                                maxval = max(path[lasti][starta][startb]+currij, maxval);
                            startb+=1
                        starta+=1;
                    path[i][j][k] = maxval;
                    rslt = max(maxval, rslt);

        return rslt;