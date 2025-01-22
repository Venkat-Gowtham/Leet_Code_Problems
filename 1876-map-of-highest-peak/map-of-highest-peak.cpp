class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        queue<pair<int,int>>q;
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(isWater[i][j] == 1){
                    q.push({i,j});
                    isWater[i][j] =0;
                     vis[i][j] = 1;
                    }
               
            }
        }
        if(q.empty()) return isWater;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
                if(i+1<m && vis[i+1][j]==0){
                    vis[i+1][j] = 1;
                    isWater[i+1][j] = isWater[i][j]+1;
                    q.push({i+1,j});
                }
                if(i-1>=0 && !vis[i-1][j]){
                    vis[i-1][j] = 1;
                    isWater[i-1][j] = isWater[i][j]+1;
                     q.push({i-1,j});
                }
                if(j+1<n && !vis[i][j+1]){
                    vis[i][j+1] = 1;
                    isWater[i][j+1] = isWater[i][j]+1;
                     q.push({i,j+1});
                }
                if(j-1>=0 && !vis[i][j-1]){
                    vis[i][j-1] = 1;
                    isWater[i][j-1] = isWater[i][j]+1;
                     q.push({i,j-1});
                }
        }
        return isWater;
    }
};