class Solution {
public:
int dp[2001][5010];
    int reach(vector<int>&stones , int i , int k){
        if(i == stones.size()-1)return 1;
        if(k==0)return 0;
        if(dp[i][k]!=-1) return dp[i][k]; 
        int l = 0 , s = 0 , r = 0;
        auto less = lower_bound(begin(stones),end(stones),stones[i]+k+1);
        auto same = lower_bound(begin(stones),end(stones),stones[i]+k);
        auto next = lower_bound(begin(stones),end(stones),stones[i]+k-1);
        if(less!=end(stones) and *less == stones[i]+k+1){
            l = reach(stones,less-stones.begin(),k+1);
        } 
        if(same!=end(stones) and *same == stones[i]+k){
            s = reach(stones,same-stones.begin(),k);
        } 
        if(next!=end(stones) and *next == stones[i]+k-1){
            r = reach(stones,next-stones.begin(),k-1);
        } 
        return dp[i][k] = l || r || s ;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return false;
        memset(dp,-1,sizeof(dp));
        return reach(stones,1,1);
    }
};