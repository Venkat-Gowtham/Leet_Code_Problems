class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int>res;
        for(auto it :nums){
            res[it]++;
        }
        int fl=0,i=1;
        for( i=1;i<=nums.size();i++){
            if(res[i]==0){
                 fl=1;
                return i;
               
            }
        }
            return i;   
    }
};