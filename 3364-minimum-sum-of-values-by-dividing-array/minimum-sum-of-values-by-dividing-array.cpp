#define ll long long 
class Solution {
public:
    vector<vector<unordered_map<int,int>>> dp;
    ll minVal(vector<int>&nums,vector<int>& andVal, ll ind ,ll cur,ll aa){
        if(ind>=nums.size()){
            if(aa>=andVal.size()) return 0;
            return 1e8;
        }
        else if(aa>=andVal.size())return 1e8;
        if(dp[ind][aa].count(cur))return dp[ind][aa][cur]; 
        // cur = cur&nums[ind];
        ll l = 1e8 , r= 1e8;
        if((cur&nums[ind])==andVal[aa]){
            l=nums[ind]+minVal(nums,andVal,ind+1,(1<<20)-1,aa+1);
        }
        r=minVal(nums,andVal,ind+1,(cur&nums[ind]),aa);
        return dp[ind][aa][cur]=min(l,r);
        
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int sum = 0;
        int n= nums.size();
        int k = andValues.size();
        dp.resize(n+2, vector<unordered_map<int,int>> (10));
       ll x= minVal(nums,andValues,0,(1<<19)-1,0);
            return x==1e8?-1:x;
        
    }
};