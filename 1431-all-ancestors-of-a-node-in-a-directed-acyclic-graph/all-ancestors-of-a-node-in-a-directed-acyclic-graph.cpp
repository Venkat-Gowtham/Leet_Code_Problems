class Solution {
public:
    void dfs(vector<vector<int>>&ans,vector<int>adj[],int node ,int ances){
        for(auto it : adj[node]){
            if(ans[it].size()==0 or ans[it].back()!=ances){
                ans[it].push_back(ances);
                dfs(ans,adj,it,ances);
            }
            
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
       vector<vector<int>>ans(n);
       vector<int>adj[n];
       for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
       }
       for(int i = 0;i<n;i++){
            dfs(ans,adj,i,i);
       }
       return ans;

    }
};