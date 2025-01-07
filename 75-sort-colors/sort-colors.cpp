class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return ;
        if(nums.size()==2){
            if(nums[0]>nums[1]) {swap(nums[0],nums[1]);}
            return ;
        }
        int n = nums.size();
        // 1 2 2 0
        int i = 0, j = 1, k = n-1;
        while(j<=k){
            if(nums[i]==1){
                if(nums[j]==1){
                    j++;
                }
               else if(nums[j]==0){
                    swap(nums[i],nums[j]);
                     i++;
                     j++;
                }
                else if(nums[j]==2){
                    swap(nums[j],nums[k]);
                    k--;
                }
                else if(nums[k]==0){
                    swap(nums[j],nums[k]);
                    swap(nums[i],nums[j]);
                    k--;
                    i++;
                    j++;
                }
                else{
                    i++;
                    j++;
                }
               
            }
            else if(nums[i]==2){
                swap(nums[i],nums[k]);
                if(nums[i]==0){
                    i++;
                    j++;
                }
                k--;
            }
            else {
                i++;
                j++;
            }
        }

        
    }
};