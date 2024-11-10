class Solution {
public:
    int minimumSubarrayLength(vector<int>& arr, int k) {
        
        int n = arr.size();
        if(k==0)return 1;
        vector<vector<int>>pre(n,vector<int>(32,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<32;j++){
                if((arr[i]>>j)&1)pre[i][j]++;
                if(i>0)pre[i][j]+=pre[i-1][j];
            }
        }
        int i = 0 , j = 0 , ans = n+1;
        while(j<n){
            int res = 0;
            for(int ii = 0; ii<32;ii++){
                if(pre[j][ii])res=res|(1<<ii);
            }
               while(res>=k)
               {
                    int val = 0;
                   ans=min(ans,j-i+1);
                     for(int ii = 0; ii<32;ii++)
                     {
                        int rem = pre[j][ii]-pre[i][ii];
                        if(rem)val=val|(1<<ii);
                     }
                   if(val>=k)
                   {
                       ans=min(ans,j-i);
                       i++;
                   }
                    res=val;
                }
            j++;
        }
        return ans == n+1?-1:ans;
        
    }
};