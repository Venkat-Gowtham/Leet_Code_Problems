class Solution {
public:
   long long  findmax(vector<int >&arr,int k, int ind,vector<long long>&dp)
    {
        if(ind>=arr.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
       long long  mi=0,ans=0;
        for(int i=ind;i<arr.size();i++)
        {
            if(i-ind+1>k)break;
              mi=max(1LL*arr[i],mi);
          ans=max(ans,findmax(arr,k,i+1,dp)+(1LL*mi*(i-ind+1)));
        }
        // cout<<ind<<" "<<ans<<endl;
        return dp[ind]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size()+1;
        vector<long long >dp(n,-1);
       return findmax(arr,k,0,dp);
    }
};