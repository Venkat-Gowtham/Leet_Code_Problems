class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>pre(nums.size(),0);
        int n = nums.size();
        for(int i =0;i<n-1;i++){
            if((nums[i]%2 == nums[i+1]%2)){
                pre[i]++;
            }
            if(i>0)pre[i]+=pre[i-1];
            
        }
        for(auto it :pre)cout<<it<<" ";
        vector<bool>res;
        for(auto it : queries){
            if(it[1]==0){res.push_back(true);continue;}
            int ans = pre[it[1]-1];
            if(it[0]==0){
                if(pre[it[1]-1]>0)res.push_back(false);
                else res.push_back(true);
            }
            else{
                ans-=pre[it[0]-1];
                if(ans)res.push_back(false);
                else res.push_back(true);
            }
        }
        return res;
    }
};