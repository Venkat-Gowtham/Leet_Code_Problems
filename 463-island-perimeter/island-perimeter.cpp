class Solution {
public:
    int findd(vector<vector<int>>& grid , int &x,int i , int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size()) return 1;
        if(grid[i][j]==0)return 1;
        if(grid[i][j]==-1)return 0;
        grid[i][j]=-1;
      int l =  findd(grid,x,i+1,j);
      int r=   findd(grid,x,i,j-1);
      int z =   findd(grid,x,i-1,j);
      int y =  findd(grid,x,i,j+1);        
        return l+r+z+y;    
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    int x=0;
                  return  findd(grid,x,i,j);
                }
            }
        }
        return 0;
    }
};