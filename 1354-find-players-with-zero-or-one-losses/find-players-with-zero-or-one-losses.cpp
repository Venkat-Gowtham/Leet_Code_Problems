class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>w,l,vis;
        vector<int>wi,lo;
        vector<vector<int>>res;
        for(auto it : matches)
        {
            w[it[0]]++;
            l[it[1]]++;
        }
        for(auto it : w)
        {
            if(l.find(it.first)==l.end())wi.push_back(it.first);
            else
            {
                if(l[it.first]==1)
                {
                    lo.push_back(it.first);
                    vis[it.first]=1;
                }
            }
        }
        for(auto it : l)
        {
            if(it.second==1 and vis[it.first]==0)lo.push_back(it.first);
        }
        res.push_back(wi);
        sort(lo.begin(),lo.end());
        res.push_back(lo);
        return res;
    }
};