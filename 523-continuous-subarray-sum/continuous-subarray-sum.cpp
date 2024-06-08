class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       
        map<int,int>mp;
        mp[0]=-1;
        int s = 0 , zc=0;
        for(int i = 0;i<nums.size();i++){
            s+=nums[i];
            s=s%k;
            // mp[s]++;
           if(mp.find(s)!=mp.end()){
            if(i-mp[s]>1)return 1;
           }
           else mp[s]=i;
        }
        return false;
    }
};