class Solution {
public:
int res=0;
    int findmax(vector<vector<int>>& piles, int k,int ind,int inner, vector<vector<vector<int>>>&dp)
    {
        if(ind>=piles.size())return 0;
        if(k<=0)return 0;
        if(dp[ind][inner][k]!=-1)return dp[ind][inner][k];
        int x=k,p=0,l=0;
        if(inner<piles[ind].size())p=findmax(piles,k-1,ind,inner+1,dp)+piles[ind][inner];
      int np= findmax(piles,x,ind+1,0,dp);     
        return dp[ind][inner][k]=max(np,p);
        return max(np,p);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
       int ind=0,inner=0,cur=0,n=piles.size(),y=0;
        for(auto it : piles)
        {
            int x=it.size();
             y=max(y,x);
        }
         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(y+1, vector<int>(k+1, -1)));
         return findmax(piles,k,ind,inner,dp);
    }
};