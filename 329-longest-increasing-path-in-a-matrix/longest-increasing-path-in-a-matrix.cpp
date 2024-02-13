class Solution {
public:
    int findd(vector<vector<int>>& matrix,int i, int j,vector<vector<int>>&dp, int prev)
    {
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]<0 || matrix[i][j]<=prev)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int val = matrix[i][j];
        matrix[i][j] *= -1;
        int l = 0, r =0 , u = 0 , d = 0;
          d = findd(matrix,i+1,j,dp,val); 
          u = findd(matrix,i-1,j,dp,val); 
          r = findd(matrix,i,j+1,dp,val); 
          l = findd(matrix,i,j-1,dp,val); 
        matrix[i][j]=val;
        
       return dp[i][j]=max({l,r,u,d})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),res=0,prev=-100;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==-1)
                {
                    res=max(res,findd(matrix,i,j,dp,prev));    
                }
                else res=max(res,dp[i][j]);
            }
        }
            return res;
    }
};