class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)return 0;
        int i = 0 , j = 0 , n = nums.size(), curPro=1,res=0;
        while(j<n){
            curPro*=nums[j];
            while( curPro>= k){
                 curPro/=nums[i++];
            }
            res+=j-i+1;
            j++;
        }  
        // res+=j-i+1;
            return res;

    }
};