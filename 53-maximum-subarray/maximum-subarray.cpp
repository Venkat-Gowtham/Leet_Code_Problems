class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0,ma=-1e6;
        for(int i = 0;i<nums.size();i++){
            s+=nums[i];
            ma=max(ma,s);
            if(s<0)s=0;
        }
        return ma;
    }
};