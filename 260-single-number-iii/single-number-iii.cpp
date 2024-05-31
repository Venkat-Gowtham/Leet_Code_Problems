class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int r = 0 , l=0,h=0, pos = 0;
        for(int i =0;i<nums.size();i++)r=nums[i]^r;
        while(r){
            if(r&1){
                break;
            }
            pos++;
            r=r>>1;
        }
        int set = 1<<pos;
        for(int i =0;i<nums.size();i++){
            if(nums[i]&set){
                l=l^nums[i];
            }
            else h=h^nums[i];
        }
        return {l,h};



    
            
    }
};