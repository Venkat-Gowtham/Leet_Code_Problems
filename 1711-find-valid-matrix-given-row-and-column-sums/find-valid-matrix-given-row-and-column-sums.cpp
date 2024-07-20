class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        vector<vector<int>>ans(row.size(),vector<int>(col.size(),0));
        int m = row.size() , n = col.size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans[i][j]=min(row[i],col[j]);
                col[j]-=ans[i][j];
                row[i]-=ans[i][j]; 
            }
        }
        return ans;
    }
};