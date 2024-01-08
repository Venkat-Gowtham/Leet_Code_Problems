class Solution {
public:
int dp[100][10001];
int findall(vector<int>&coins, int tar,int ind)
{
    if(ind>=coins.size() or tar==0)
    {
      return   tar==0?0:1e9;
    }
    if(dp[ind][tar]!=-1)return dp[ind][tar];
    int x=1e9,y=1e9,res=1e9;
    if(tar-coins[ind]>=0)
    {
        x=findall(coins,tar-coins[ind],ind);
        y=findall(coins,tar-coins[ind],ind+1);
        x=min(x,y)+1;
    }
    y=findall(coins,tar,ind+1);
    res=min(x,y);
    return dp[ind][tar]=res;
}
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
       int res= findall(coins,amount,0);
      return  res==1e9?-1:res;
    }
};