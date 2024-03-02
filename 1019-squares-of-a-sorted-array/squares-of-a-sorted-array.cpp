class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i = 0 , j  = 0 , x;
        while(i<nums.size() and nums[i]<0)i++;
        x = i;
        vector<int>res;
        i-=1;
        while(x<nums.size() and i>=0)
        {
            if(abs(nums[x])<=abs(nums[i]))
            {
                res.push_back(pow(nums[x],2));
                x++;
            }
            else
            {
                 res.push_back(pow(nums[i],2));
               i--;
            }
        }
        while(x<nums.size())
        {
             res.push_back(pow(nums[x],2));
                x++;
        }
          while(i>=0)
        {
             res.push_back(pow(nums[i],2));
                i--;
        }
        return res;
        
    }
};