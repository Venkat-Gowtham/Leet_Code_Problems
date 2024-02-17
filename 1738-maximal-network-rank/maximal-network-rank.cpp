class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        vector<int>degree(n,0);
        for(auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        int res=0;
        for(int i=0; i< n; i++)
        {
            for ( int j = i+1; j < n; j++ )
            {
                    if(find(adj[i].begin(),adj[i].end(),j)!=adj[i].end())
                    {
                        res=max(res,degree[i]+degree[j]-1);
                    }
                    else
                    {
                        res=max(res,degree[i]+degree[j]);
                    }
            }
        }
        return res;

    }
};