class Solution {
public:
    int dfs(vector<vector<int>>&adj , int node , vector<int>&vis,vector<int>&dp){
        if(adj[node].size()==0){
            return dp[node]=1;
        }
        vis[node] = 1;
        int cnt = 1;
        for(auto it : adj[node]){
           if(!vis[it]){
                dp[it]=dfs(adj,it,vis,dp);
                if(!dp[it])return 0;
           }
           else{
             if(!dp[it]) return 0;
           }
        }
        return dp[node]=cnt;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>ans;
        vector<int>vis(n,0),dp(n,0);
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int res = dfs(adj,i,vis,dp);
            }
        }
        for(int i = 0;i<n;i++)if(dp[i])ans.push_back(i);
        return ans;
    }
};