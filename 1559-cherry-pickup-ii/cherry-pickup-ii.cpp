class Solution {
public:
    int dp[71][71][71];
    int dfs(vector<vector<int>>& grid, int i, int j, int y)
    {
        if(y<0 || j<0 ||  j>=grid[0].size() || y>=grid[0].size()) return 0;
            if(i==grid.size()-1)
        {
            if(j==y)return grid[i][j];
            return grid[i][j]+grid[i][y];
        }
        if(dp[i][j][y]!=-1)return dp[i][j][y];
        int ans=0,a,b,c,d,e,f,g,l,h,temp=0;
        a = dfs(grid,i+1,j,y);
        d = dfs(grid,i+1,j+1,y);  
        g = dfs(grid,i+1,j-1,y);

        b = dfs(grid,i+1,j,y-1);
        e = dfs(grid,i+1,j+1,y-1);
        h = dfs(grid,i+1,j-1,y-1);

        c = dfs(grid,i+1,j,y+1);
        f = dfs(grid,i+1,j+1,y+1);
        l = dfs(grid,i+1,j-1,y+1);
        
        temp=max({a,b,c,d,e,f,g,l,h});
        if(j==y)return dp[i][j][y]=temp+grid[i][j];
        return dp[i][j][y]=temp+grid[i][j]+grid[i][y];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return dfs(grid,0,0,grid[0].size()-1);
    }
};