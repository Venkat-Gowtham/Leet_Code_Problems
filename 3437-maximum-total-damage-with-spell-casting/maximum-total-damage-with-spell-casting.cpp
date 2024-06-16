class Solution {
private:
    // #define long long  long long 
    long long  maxPower(vector<int>&power , int ind , unordered_map<int ,long long >&mp,vector<long long >&dp){
        if(ind<0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int  f = 0;
        long long  left = power[ind] * mp[power[ind]];
        long long   right = maxPower(power,ind-1,mp,dp);
          if(ind>=1 and power[ind]-power[ind-1]==1){

            if(ind>=2 and power[ind]-power[ind-2]==2){
               {f=1; left  += maxPower(power,ind-3,mp,dp);}
            }
            else {f=1;left += maxPower(power,ind-2,mp,dp);}
          }
          else{
            if(ind>0 and power[ind]-power[ind-1]==2){
                left+=maxPower(power,ind-2,mp,dp);
            }
            else{
                left+=maxPower(power,ind-1,mp,dp);
            }
          }
        return dp[ind]=max(left,right);      
    }
    public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int  ,long long >mp;
        for(auto it : power){
            mp[it]++;
        }
        vector<int>uni;
        for(auto it : mp){
            uni.push_back(it.first);
        }
        sort(uni.begin(),uni.end());
        vector<long long >dp(uni.size(),-1);
       
        return maxPower(uni,uni.size()-1,mp,dp);
        
        
        
    }
};