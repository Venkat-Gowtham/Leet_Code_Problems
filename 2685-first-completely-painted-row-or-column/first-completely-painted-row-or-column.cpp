class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int>rc,cc;
        map<int,pair<int,int>>mp;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        for(int i = 0;i<arr.size();i++){
            auto it = mp[arr[i]];
            rc[it.first]++;
            cc[it.second]++;
            if(rc[it.first]==n or cc[it.second]==m) return i;
        }
      
        return 0;
    }
};