class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p=nums.size()-1;
        int q=nums.size()-2;
        while(q>=0){
           
            if(nums[p]>nums[q]){
               break;
            }
            p--;
            q--;
        }
        if(q<0){
            reverse(nums.begin(),nums.end());
            return ;
        }
        int ma = q;
        for(int i = q+1;i<nums.size();i++){
            if(nums[i]>nums[q])ma=i;
        }
        swap(nums[ma],nums[q]);
        reverse(nums.begin()+q+1,end(nums));
    }
};