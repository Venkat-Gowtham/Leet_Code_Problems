class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int s = 0, c= 0;
        mp[0]=1;
        for(int i = 0; i < nums.size() ; i++){
            s+=nums[i];
            int val = s%k;
            if(s%k<0)val+=k;
            if(mp.find(val)!=mp.end()){
                c+=mp[val];
            }
            mp[val]++;
        }
    
        return c;

    }
};