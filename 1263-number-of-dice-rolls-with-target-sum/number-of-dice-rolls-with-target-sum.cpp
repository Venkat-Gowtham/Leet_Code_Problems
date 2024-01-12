class Solution {
public:
const int mod = 1e9 + 7;
int dp[1001][1001];
int findall(int n, int k, int tar)
{
    if(n==0 and tar==0)return 1;
    if (n <0)return 0;
    if (dp[n][tar] != -1)
        return dp[n][tar];
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        if (tar-i>=0)
        {
            ans = (ans + findall(n - 1, k, tar-i)) % mod;
        }
    }
    return dp[n][tar] = ans;
}

int numRollsToTarget(int n, int k, int target)
{
    memset(dp,-1,sizeof(dp));
    // vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    int cur = 0;
    return findall(n, k, target);
}


};