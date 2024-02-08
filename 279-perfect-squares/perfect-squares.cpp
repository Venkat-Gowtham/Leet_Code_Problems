class Solution {
public:
    long long dp[10001];
   long long  findways(long long  n)
    {
        if(n<=0)
        {
            // if(n==0)return 1;
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
       long long ans=INT_MAX;
        for(int i=sqrt(n);i>=1;i--)
        {
            ans=min(ans,1+findways(n-(1LL*i*i)));
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return findways(n);
    }
};