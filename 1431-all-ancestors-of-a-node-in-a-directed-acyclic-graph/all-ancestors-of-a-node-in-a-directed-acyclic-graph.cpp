class Solution {
public:
    void dfs(vector<int>&vis,vector<int>adj[],int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it])dfs(vis,adj,it);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       vector<vector<int>>ans(n);
       vector<int>adj[n];
       for(int i = 0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
       }
       for(int i = 0;i<n;i++){
            vector<int>vis(n,0);
            vis[i]=1;
            dfs(vis,adj,i);
            for(int j=0;j<n;j++){
                if(j!=i and vis[j])ans[i].push_back(j);
            }
       }
       return ans;

    }
};