class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size()-1;
        int i = nums.size()-2;
        int n = nums.size();
        // find bep from back
        int bf = -1;
        while(i>=0){
            if(nums[i]<nums[j]){
                bf = i;
                break;
            }
            i--;
            j--;
        }
        if(bf == -1) {reverse(begin(nums),end(nums));return;}
        //find nxt greater ele for starting point after common prefix 
        for(int ii = n-1;ii>=i;ii--){
            if(nums[ii]>nums[i]){
                swap(nums[ii],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};