class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>suff(n,0);
        suff[n-1]=nums[n-1];
        for(int i = n - 2 ; i>=0;i--){
            suff[i]= max(suff[i+1],nums[i]);
        }
        int ma = nums[0];
        long long res = 0;
        for(int i = 1;i<n-1;i++){
            res = max(res,1LL*(ma-nums[i])*suff[i+1]);
            ma = max(ma,nums[i]);
        }
        return res;
    }
};