class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int flag = 0 , i = 0 , j = 0 , cr = 0, cl = 0;
        int m = mat.size() , n= mat[0].size();
        vector<int>res;
        while((i<m and j<n)){
            if(!flag){
                while(i>=0 and j<n){
                    res.push_back(mat[i--][j++]);
                }
                if(j<n){
                    i=0;
                }
                else {
                    i+=2;
                    j-=1;
                }
                flag = 1;
            }
            else{
                while(i<m and j>=0){
                    res.push_back(mat[i++][j--]);
                }
                if(i<m){
                    j=0;
                }
                else{
                    i-=1;
                    j+=2;
                }
                flag = 0;
            }
        }
    return res;
    }
    // 1  2  3  4
    // 5  6  7  8
    // 9 10  11 12
    // 13 14 15 16
};