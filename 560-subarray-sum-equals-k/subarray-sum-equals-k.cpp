class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cur =0;
        int c = 0;
        mp[0]=1;
        for(int i = 0;i<nums.size();i++){
            cur+=nums[i];
            int rem = cur - k;
            if(mp.find(rem)!=mp.end()){
                c+=mp[rem];
            }
            mp[cur]++;
            }

        return c;

    }
};