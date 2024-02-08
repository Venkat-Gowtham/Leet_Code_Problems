class Solution {
public:
unordered_set<int>res;
    void dfs(int n, int k, int prev)
    {
        if(n==0)
        {
            res.insert(prev);
            return ;
        }
        if(prev%10-k>=0)
        {
            dfs(n-1,k,prev*10+(prev%10-k));
        }
        if(prev%10+k<=9)
        {
            dfs(n-1,k,prev*10+(prev%10+k));
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++)
        {
            dfs(n-1,k,i);
        }
        return vector<int>(res.begin(),res.end());
    }
};