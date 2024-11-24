class Solution {
public:
    int dp[101][101][101];
    int findmin(vector<int>& nums, int k, int op1, int op2, int ind) {
    if (ind >= nums.size()) return 0;
    int pc = INT_MAX, nc = INT_MAX,op=INT_MAX,on=INT_MAX,np=INT_MAX;
    if(dp[ind][op1][op2]!=-1) return dp[ind][op1][op2];
    if(op1>0 && op2>0){
         pc = nums[ind] / 2 + (nums[ind] % 2 ? 1 : 0);
        if(pc>=k){
            pc=pc-k;
            pc+=findmin(nums,k,op1-1,op2-1,ind+1);
        }
        else pc+=findmin(nums,k,op1-1,op2,ind+1);
        if(nums[ind]>=k){
            nc = nums[ind]-k;
            if(nc==0){
                nc=findmin(nums,k,op1,op2-1,ind+1);
            }
          else nc=nc/2+(nc%2?1:0)+findmin(nums,k,op1-1,op2-1,ind+1);
        }
    }
    if (op1 > 0) {
        op=nums[ind] / 2 + (nums[ind] % 2 ? 1 : 0);
        op +=findmin(nums, k, op1 - 1, op2, ind+1);
        
    }
    if (op2 > 0 && nums[ind] >= k) {
        on=nums[ind]-k;
        on+= findmin(nums, k, op1, op2 - 1, ind+1);
    }
    int no_op = nums[ind] + findmin(nums, k, op1, op2, ind + 1);

    return dp[ind][op1][op2]=min({pc, nc,op,on, no_op});
}


    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp,-1,sizeof(dp));
        return findmin(nums,k,op1,op2,0);
    }
};