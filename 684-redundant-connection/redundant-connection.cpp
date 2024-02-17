class Solution {
public:
    vector<int>rank;
    vector<int>par;
    int findd(int u)
    {
        if(par[u] == u ) return u;
        return par[u] = findd(par[u]);
    }
    void unionn(int u, int v)
    {
        int up = findd(u);
        int vp = findd(v);

        if(rank[up]>=rank[vp])
        {
            par[vp] = up;
            rank[vp] += rank[up];
        }
        else
        {
            par[up] = vp;
            rank[up] += rank[vp];
        }

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        rank.resize(n+1);
        par.resize(n+1);
        for( int i = 1 ; i<=n; i++)
        {
            par[i] = i;
            rank[i] = 1;
        }
        int last_index = -1;
        for( int i = 0 ;i < n ; i++ )
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int up = findd(u);
            int vp = findd(v);
            if(up!=vp) unionn(u,v);
            else last_index = i;
        }
        return edges[last_index];
    }
};