class Solution {
public:
    void dfs(vector<int>adj[],int cnt , vector<int>&vis , map<int,vector<int>>&mp, int node){
        vis[node]++;
        mp[cnt].push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj,cnt,vis,mp,it);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        map<int,vector<int>>mp;
        int cnt = 0,res=0;
        for(int i = 0 ; i< n;i++){
            if(!vis[i]){
                int f = 0;
                dfs(adj,cnt,vis,mp,i);
                int x = mp[cnt].size();
                for(auto it : mp[cnt]){
                    if(adj[it].size() != x-1){f=1;break;}
                }
                if(!f)res++;
                cnt++;

            }
        }
        return res;
    }
};