class Solution {
public:
    bool find_possible(string &s1, string &s2, string &s3, int i, int j ,int k,vector<vector<int>>&dp)
    {
        if(k>=s3.length())return 1;
        if(i>=s1.length() and j>=s2.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int  a=0,b=0;
        if(s3[k]==s1[i])
        {
            a=find_possible(s1,s2,s3,i+1,j,k+1,dp);
        }
        if(s3[k]==s2[j])b=find_possible(s1,s2,s3,i,j+1,k+1,dp);
        return dp[i][j]=a or b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        map<char,int>mp1,mp2,mp3;
        int a=s1.length(),b=s2.length(),c=s3.length(),i=0,j=0,k=0;
        if(c!=a+b)return 0;
        vector<vector<int>>dp(a+1,vector<int>(b+1,-1));
        for(auto it : s1)mp1[it]++;
        for(auto it : s2)mp2[it]++;
        for(auto it : s3)
        {
            if(mp1[it]==0 and mp2[it]==0)return 0;
            mp3[it]++;
        }
       return find_possible(s1,s2,s3,i,j,k,dp);



    }
};