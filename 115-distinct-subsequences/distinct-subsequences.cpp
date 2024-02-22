class Solution {
public:
 int dp[1001][1001];
    int mod = 1e9+7;
 int findways(int i , int j, string&s , string&t)
    {
        if(i>=s.length() or j>=t.length())
        {
            if(j==t.length())return 1;
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int l = 0 ,  r = 0;
        if(s[i]==t[j])l+=findways(i+1,j+1,s,t);
        r+=findways(i+1,j,s,t);
        return dp[i][j]=(l+r)%mod;
    }
    int numDistinct(string s, string t) {

        memset(dp,-1,sizeof(dp));
        return findways(0,0,s,t);
        
    }
};