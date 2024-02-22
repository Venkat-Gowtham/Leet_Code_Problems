class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degree(n+1,0),out(n+1,0);
        for(auto it : trust)
        {
            degree[it[0]]++;
            out[it[1]]++;
        }

        for(int i = 1 ; i<=n;i++)
        {
            if(degree[i]==0 and out[i]==n-1)return i;
        }
        return -1;
    }
};