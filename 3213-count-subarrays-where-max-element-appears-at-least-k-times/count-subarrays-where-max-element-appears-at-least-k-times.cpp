class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<long long,long long>mp;
        long long ma = 0;
        for(auto it : nums){
            mp[it]++;
            ma=max(ma,1LL*it);
        }
        long long f = mp[ma];
        if(f<k) return 0;
        long long i = 0  , j = 0 , c=0, res = 0 , n = nums.size();
        while(j<n){
            if(nums[j]==ma)c++;
            if(c==k){
                while(c==k){
                    if(nums[i]==ma)c--;
                    i++;
                    res +=n-j;
                }
            }
            j++;
        }
        return res;
    }
};