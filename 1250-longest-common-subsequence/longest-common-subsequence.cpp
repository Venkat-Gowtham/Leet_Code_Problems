class Solution {
public:
int dp[10001][1001];
int lcs(string &text1, string &text2, int i, int j)
{
    if(i>=text1.length() or j>=text2.length())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int pick=0,np1=0,np2=0;
    if(text1[i]==text2[j])
    {
       pick+=lcs(text1,text2,i+1,j+1)+1;
    }
    np1=lcs(text1,text2,i+1,j);
    np2=lcs(text1,text2,i,j+1);
    return dp[i][j]=max(pick,(max(np1,np2)));

}
    int longestCommonSubsequence(string text1, string text2) {
        int m=text2.length();
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text2,0,0);
    }
};