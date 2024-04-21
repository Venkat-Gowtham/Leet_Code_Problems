class Solution {
public:
    void dfs(vector<int>&vis, vector<int>adj[], int node){
        vis[node] =1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(vis,adj,it);
            }
        }
     }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(vis,adj,source);
        if(vis[destination])return 1;
        return 0;
    }
};