class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0 , j = nums.size()-1;
        while(i<=j){
            int m = (i+j)/2;
            if(nums[i] == target) return i; 
            if(nums[j] == target) return j; 
            if(nums[m] == target) return m;
            else if(nums[i]<=nums[m]){
                if(target<=nums[m] and nums[i]<=target){
                    j = m-1;
                }
                else{
                    i = m+1;
                }
            }
            else{
                if(target>=nums[m] and target<=nums[j]){
                    i = m+1;
                }
                else j = m -1;
            }

        }
        return -1;
    }
};