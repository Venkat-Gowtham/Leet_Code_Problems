class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       long long s=0,res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s>nums[i])
            {
                if(i>=2)res=max(res,nums[i]+s);
                s+=nums[i];
            }
            else s+=nums[i];
        }
      return  res==0?-1:res;
    }
};