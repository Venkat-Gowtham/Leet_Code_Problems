class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
       for(int i = 0;i<roads.size();i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
       }
       sort(begin(degree),end(degree));
       long long   res = 0;
       for(int i = 0 ; i < n;i++){
            res += 1LL*degree[i]*(i+1);
       }
       return res;
    }
};