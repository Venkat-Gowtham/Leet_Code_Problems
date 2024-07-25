class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ac=0,cr=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[abs(nums[i])]<0)return abs(nums[i]);
            nums[abs(nums[i])]*=-1;

        }
        return ac^cr;

    }
};