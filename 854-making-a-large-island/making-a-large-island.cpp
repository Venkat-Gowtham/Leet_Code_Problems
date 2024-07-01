class Solution {
public:
    int cr = 2;
    void dfs(vector<vector<int>>& grid,int i , int j , int &c){
        if(i<0 or j<0 or i>=grid.size() or j>=grid.size() or grid[i][j]!=1)return ;
        grid[i][j]=0;
        dfs(grid,i+1,j,c);
        dfs(grid,i-1,j,c);
        dfs(grid,i,j+1,c);
        dfs(grid,i,j-1,c);
        grid[i][j]=cr;
        c++;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int  n = grid.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                   int c=0;
                    dfs(grid,i,j,c);
                    cout<<c;
                    if(c==n*n)return n*n;
                    mp[cr]=c;
                    cr++;
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>st;
                    int gow = 0;
                    if(i+1<n) st.insert(grid[i+1][j]);
                    if(i-1>=0)st.insert(grid[i-1][j]);
                    if(j-1>=0)st.insert(grid[i][j-1]);
                    if(j+1<n) st.insert(grid[i][j+1]);
                    for(auto it : st)gow+=mp[it];
                    ans = max(ans,gow+1);
                }
            }
        }
        return ans;
    }
};