class Solution {
public:
int dp[51][51][51];
int mod=1e9+7;
    int fun(int i, int j, int m, int n, int ma, vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=m || j>=n){
            return 1;
        }
        if(ma<=0){
            return 0;
        }
        if(dp[i][j][ma]!=-1)return dp[i][j][ma];
        int a=fun(i+1,j,m,n,ma-1,grid)%mod;
        int b=fun(i-1,j,m,n,ma-1,grid)%mod;
        int c=fun(i,j+1,m,n,ma-1,grid)%mod;
        int d=fun(i,j-1,m,n,ma-1,grid)%mod;

        return dp[i][j][ma]=(((a+b)%mod+(c+d)%mod)%mod)%mod;
    }
    int findPaths(int m, int n, int ma, int sr, int sc) {

        vector<vector<int>>grid(m,vector<int>(n,0));
        memset(dp,-1,sizeof(dp));
        return fun(sr,sc,m,n,ma,grid);

        
    }
};