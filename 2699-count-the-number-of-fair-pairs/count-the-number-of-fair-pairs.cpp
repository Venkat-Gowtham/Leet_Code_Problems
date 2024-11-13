class Solution {
public:

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums),end(nums));
        long long ans = 0;
        for(int i =0;i<nums.size()-1;i++){
            auto right = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            auto left =  lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            ans+=(right-left);
        }
        return ans;
    }
};