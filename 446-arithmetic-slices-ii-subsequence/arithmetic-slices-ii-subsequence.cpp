class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int,int>>mp(n);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long  dif=1LL*(nums[i])-1LL*(nums[j]);
                if(dif>=INT_MAX or dif<=INT_MIN)continue;
                   int diff=int(dif);
                if(mp[j].find(diff)!=mp[j].end())
                {
                    int prev=mp[j][diff];
                    int cur=mp[i][diff];
                    mp[i][diff]=cur+prev+1;
                    ans+=mp[j][diff];
                }
                else
                {
                    mp[i][diff]++;
                }
            }
        }
        return ans;
    }
};