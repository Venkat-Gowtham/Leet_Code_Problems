class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ma = 0;
        int l = 0 , r = 0, n = nums.size();
        while(r<n){
            if(nums[r++]==0)--k;
            if(k<0 and nums[l++]==0)k++;
        }
        return r-l;
    }
};