class Solution {
public:
    bool searchh (vector<vector<int>>&matrix , int t , int ind){

        int l = 0 , h = matrix[ind].size()-1;
        while(l<=h){
            int m = (l+h)/2;
            if(matrix[ind][m] == t)return true;
            else if(matrix[ind][m]<t)l=m+1;
            else h = m-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() , n = matrix[0].size();
        int rowtoapplysearch = -1 ;
        for(int i = 0 ; i < m ; i++){
            int l  = matrix[i][0];
            int h  = matrix[i][n-1];
            if(target >= l and target <= h){
                rowtoapplysearch = i;
                break;
            }
            else if(target >h){
                continue ;
            }
            else if(target <l) break;
        }
        if(rowtoapplysearch == -1) return false;
        else{
            return searchh(matrix, target , rowtoapplysearch);
        }
    }
};