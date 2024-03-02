class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      set<vector<int>>res;
      vector<vector<int>>result;
      for(int i=0;i<nums.size();i++)
      {
          int l=i+1;
          int h=nums.size()-1;
          while(l<h)
          {
              if(nums[i]+nums[l]+nums[h]==0)
              {
                  vector<int>val;
                  val.push_back(nums[i]);
                  val.push_back(nums[l]);
                  val.push_back(nums[h]);
                //   if(find(res.begin(),res.end(),val)==res.end())
                //   {
                      res.insert(val);
                //   }
               
                  while(l<h and nums[l]==nums[l+1])
                  {
                      l++;
                  }
                  while(l<h and nums[h]==nums[h-1])
                  {
                      h--;
                  }
                     l++;
                  h--;
                  
              }
              else if (nums[i]+nums[l]+nums[h]<0)
              {
                  l++;
              }
              else
              {
                  h--;
              }
          }
      }
        return vector<vector<int>>(res.begin(),res.end());
    }
};