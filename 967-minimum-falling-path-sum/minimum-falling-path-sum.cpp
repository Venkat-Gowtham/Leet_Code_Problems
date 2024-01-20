class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(i+1>=n){dp[i][j]=matrix[i][j];continue;}
                if(i+1<n and j-1>=0)
                {
                    dp[i][j]=min(dp[i+1][j-1],dp[i][j]);
                }
                if(i+1<n and j+1<n)
                {
                    dp[i][j]=min(dp[i+1][j+1],dp[i][j]);
                }
                if(i+1<n)
                {
                    dp[i][j]=min(dp[i+1][j],dp[i][j]);
                }
                dp[i][j]+=matrix[i][j];
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());

    }
};