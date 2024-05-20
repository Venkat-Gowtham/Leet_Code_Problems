class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        if(nums.size()==1)return nums[0];
        for(int i = 0;i<(1<<nums.size());i++)
        {
            int res = 0;
            for(int j = 0;j<nums.size();j++){
                if((1<<j)&i){
                    res = res^nums[j];
                }
            }
            ans+=res;
        }
        return ans;
    }
};