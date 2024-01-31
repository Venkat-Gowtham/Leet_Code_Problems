class Solution {
public:
int mod=1e9+7;
    int numberOfWays(string cor) {
        int ans=1,flag,f=0,n=cor.length(),c=0;
        for(int i=0;i<n;i++)
        {
            if(cor[i]=='S')c++;
            if(c==2)
            {
                if(!f){flag=i;f=1;}
            }
            else if(c>2)
            {
                ans=(1LL*ans*(i-flag))%mod;
                c=1;
                f=0;
            }
        }
        if(c==0)return 0;
        // if(c%2==0)return 1;
        if(c%2)return 0;
        return ans;
    }
};