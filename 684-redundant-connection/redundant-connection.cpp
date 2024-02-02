class Solution {
public:
    vector<int>rank;
    vector<int>par;
    int findd(int u)
    {
        if(par[u]==u)return u;
        return par[u]=findd(par[u]);
    }
    void unionn(int u, int v)
    {
        int up=findd(u);
        int vp=findd(v);
        // if(up==vp)
        if(rank[up]>=rank[vp])
        {
            par[vp]=up;
            rank[up]+=rank[vp];
        }
        else
         {
            par[up]=vp;
            rank[vp]+=rank[up];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // intializing
        rank.resize(edges.size()+1);
        par.resize(edges.size()+1);
        for(int i=1;i<=edges.size();i++)
        {
            rank[i] = 1;
            par[i] = i;
        }
        int l = -1;
        for(int i=0;i<edges.size();i++)
        {
           int u=edges[i][0];
           int v=edges[i][1];
           int up=findd(u);
           int vp=findd(v);
        //    if(up!=vp)unionn(u,v);
           if(up!=vp)unionn(up,vp);
           else l=i;
        }
        return edges[l];
    }
};