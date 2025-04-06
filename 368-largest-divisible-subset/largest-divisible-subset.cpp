class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n+1,0);
        int ind=0,res=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            int ans=0;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]%nums[i]==0)
                {
                    ans=max(dp[j]+1,ans);
                }
            }
            dp[i]=ans;
            if(ans>res)
            {
                res=max(ans,res);
                ind=i;
            }
        }
        int val=dp[ind];
        vector<int>result;
        for(int i=1;i<n+1;i++)cout<<dp[i]<<" ";
        result.push_back(nums[ind]);
        for(int i=ind+1;i<nums.size();i++)
        {
             if(dp[i]==val-1 and nums[i]%nums[ind]==0)
             {
                result.push_back(nums[i]);
                val-=1;
                ind=i;
             }
        }
        return result;
    }
};