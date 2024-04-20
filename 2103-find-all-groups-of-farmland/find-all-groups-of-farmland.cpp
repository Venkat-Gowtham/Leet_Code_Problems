class Solution {
public:
    void findd(int &x , int &y , int i , int j , vector<vector<int>>& grid){
        if(i>=grid.size() or j>=grid[0].size() or i<0 or j<0)return ;
        if(grid[i][j]==0)return ;
        grid[i][j]=0;
        // x=i,y=j;
        x=max(x,i);
        y=max(y,j);
        findd(x,y,i+1,j,grid);
        findd(x,y,i,j+1,grid);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        vector<vector<int>>res;
     for(int i = 0; i<grid.size();i++){
         for(int j = 0; j < grid[0].size() ; j++){
            if(grid[i][j]==1){
                vector<int>temp;
                temp.push_back(i);
                temp.push_back(j);
                int x=i,y=j;
                findd(x,y,i,j,grid);
                temp.push_back(x);
                temp.push_back(y);
                res.push_back(temp);
            }
         }
     }   
        return res;
    }
};