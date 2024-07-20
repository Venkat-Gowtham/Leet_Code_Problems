class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        vector<vector<int>>ans(row.size(),vector<int>(col.size(),0));
        int m = row.size() , n = col.size();
        for(int i = 0;i<m;i++){
            int rem = row[i]%n;
            int cut = row[i]/n;
            for(int j = 0;j<n;j++){
                int y = min(row[i],col[j]);
                ans[i][j]+=y;col[j]-=y; row[i]-=y; 
            }
        }
        return ans;
        // 5 0 5
        // 0 2 8

        // 5 0 0
        // 3 4 0
        // 0 2 8


        // 5 0 0 
        // 3 4 0 
        // 0 1 3
    }
};