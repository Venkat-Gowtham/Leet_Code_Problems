class Solution {
public:
    int merge(vector<int>&nums , int l , int h ){
        if(l == h) return 0;
        int m = l+(h-l)/2;
        int res1 = merge(nums,l,m);
        int res2 = merge(nums,m+1,h);
        int x = l , y = m+1, total=0;
        while(x<=m){
            while(y<=h){

                long long val = 1LL*nums[y]*2;
                if(nums[x]<=val) break;
                y++;
            }
            total+=y-m-1;
            x++;
        }
        vector<int>res;
        x=l,y=m+1;
        while(x<=m and y<=h){
            if(nums[x]<=nums[y]){
                res.push_back(nums[x]);
                x++;
            }
            else{
                res.push_back(nums[y]);
                y++;
            }
        }
        while(x<=m){
            res.push_back(nums[x++]);
        }
        while(y<=h){
            res.push_back(nums[y++]);
        }
        int k = 0;
        for(int i = l;i<=h;i++){
            nums[i] = res[k++];
        }
        return res1+res2+total;

    }
    int reversePairs(vector<int>& nums) {
        
        return merge(nums,0,nums.size()-1);
    }
};