class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

            int m = s.length();
            vector<int>dp(m,0);
            for(int i = 0;i<m;i++)
            {
                for(auto it : wordDict)
                {
                    int x = it.size();
                    if(i+x-1 < m and s.substr(i,x)==it)
                    {
                       if(i==0)dp[i+x-1] = x;
                       else {
                           dp[i+x-1] = max( dp[i-1]+x , dp[i+x-1]);
                            if(dp[m-1] == m) return 1;
                       }
                    }
                }
            }
          return dp[m-1]==m; 
    }
};