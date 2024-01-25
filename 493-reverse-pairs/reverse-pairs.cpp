class Solution {
public:
int merge(vector<int>&nums, int low,int high)
{
    if(low==high)return 0;
    int m=(low+(high-low)/2);
   int res1= merge(nums,low,m);
    int res2=merge(nums,m+1,high);
    int y=low;
   int  total=0,x=m+1;
    while(y<=m)
    {
        while(x<=high)
        {
            long long val=1LL*2*nums[x];
            if(nums[y]<=val)break;
            x++;
        }
        total+=x-1-m;
        y++;
    }
    vector<int>ans;
    x=m+1;
    y=low;
    while(y<=m and x<=high)
    {
        if(nums[y]<=nums[x])
        {
            ans.push_back(nums[y]);
            y++;
        }
        else
        {
            ans.push_back(nums[x]);
            x++;
        }
    }
    while(y<=m)
    {
         ans.push_back(nums[y]);
         y++;
    }
    while(x<=high)
    {
         ans.push_back(nums[x]);
         x++;
    }
    int k=0;
    for(int i=low;i<=high;i++)
    {
        nums[i]=ans[k++];
    }
    return res1+res2+total;
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return merge(nums,0,n-1);

    }
};