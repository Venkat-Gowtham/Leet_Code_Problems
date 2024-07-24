class Solution {
public:
vector<int>vis;
int dp[50001];
    bool findways(vector<int>&arr, int ind){
        if(ind<0 or ind>=arr.size())return 0;
        if(arr[ind] == 0)return 1;
        if(dp[ind]!=-1)return dp[ind];
        if(vis[ind])return 0;
        vis[ind] = 1;
        return dp[ind] = findways(arr,ind+arr[ind]) || findways(arr,ind-arr[ind]);
    }
    bool canReach(vector<int>& arr, int start) {
        memset(dp,-1,sizeof(dp));
        vis.resize(arr.size(),0);
        return findways(arr,start);
    }
};