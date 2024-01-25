class Solution {
public:
int dp[10001][1001];
int lcs(string &s,int i, int j)
{
    if(i>=s.length() or j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int pick=0,np1=0,np2=0;
    if(s[i]==s[j])
    {
       pick+=lcs(s,i+1,j-1)+1;
    }
    np1=lcs(s,i+1,j);
    np2=lcs(s,i,j-1);
    return dp[i][j]=max(pick,(max(np1,np2)));

}
    int longestPalindromeSubseq(string s) {
         int m=s.length();
        memset(dp,-1,sizeof(dp));
        return lcs(s,0,m-1);
    }
};