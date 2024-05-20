class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        for(int i =0;i<n;i++)ans|=nums[i];
        return ans<<n-1;
    }
};