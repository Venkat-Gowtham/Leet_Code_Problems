class Solution {
public:
 long long int findC(int ind,int n,vector<int>&Arr,int target,long long &ans,vector<vector<long long int>>&dp){       
      if (target < 0)return 0;
    	if(ind==n or target==0){
    		if (target==0)return 1;
    		return 0;
    	}
     	if(dp[ind][target]!=-1)return dp[ind][target];
	    long long int l=findC(ind,n,Arr,target-Arr[ind],ans,dp);//pick   
	    long long int  r=findC(ind+1,n,Arr,target,ans,dp);//non pick
	    return dp[ind][target]=l+r;
    }
    int change(int target, vector<int>& Arr) {
         long long ans = 0,n=Arr.size();
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        return findC(0,n,Arr,target,ans,dp);
    }
};