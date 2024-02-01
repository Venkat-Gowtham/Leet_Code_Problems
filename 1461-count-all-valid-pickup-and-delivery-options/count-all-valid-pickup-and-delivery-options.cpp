class Solution {
public:
int mod=1e9+7;
    int countOrders(int n) {
        if(n==1)return 1;
        if(n==2)return 6;
       long long x=9,prev=6,ans=6;
        for(int i=3;i<=n;i++)
        {
            long long val=(prev+x)%mod;
           ans=(1LL*ans*val)%mod;
           prev=val;
           x=(x+4)%mod;
        }
        return ans;
    }
};