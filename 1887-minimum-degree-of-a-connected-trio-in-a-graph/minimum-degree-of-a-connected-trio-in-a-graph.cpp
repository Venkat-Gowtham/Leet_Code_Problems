class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n+1,vector<int>(n+1,0));
        vector<int>degree(n+1,0);
        for(int i = 0 ; i<edges.size();i++){
            adj[edges[i][0]][(edges[i][1])]=1;
            adj[edges[i][1]][(edges[i][0])]=1;
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        int ans = INT_MAX;
        for(int u = 1 ; u<=n;u++){
            for(int v = 1 ;v<=n;v++){
                if(u!=v and adj[u][v] == 1){
                    for(int w = 1;w<=n;w++){
                        if(u!=w and adj[w][u]==1 and adj[w][v]==1){
                            ans = min(ans,degree[u]+degree[v]+degree[w]-6);
                        }
                    }
                }
                
            }
        }
        return ans==INT_MAX?-1:ans;

    }
};