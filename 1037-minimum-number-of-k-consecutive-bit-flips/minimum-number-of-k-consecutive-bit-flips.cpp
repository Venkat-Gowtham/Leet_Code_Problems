class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
       vector<int>pre(n+2,0);
        int ans = 0;
        for(int i = 0;i<=n-k;i++){
            if(i>0)pre[i]+=pre[i-1];
            if(nums[i]==1 and pre[i]%2!=0){
                ans++;
                pre[i]+=1;
                pre[i+k]-=1;
            }
            else if(nums[i]==0 and pre[i]%2==0){
                ans++;
                pre[i]+=1;
                pre[i+k]-=1;
            }
        }
        for(int i = n-k+1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        for(int i = 0;i<n;i++)cout<<pre[i]<<" ";
        for(int i = 0;i<n;i++){
            if(nums[i]==1 and pre[i]%2!=0){
                return -1;
            }
            else if(nums[i]==0 and pre[i]%2==0){
               return -1;
            }
        }
        return ans;

           
    }
};