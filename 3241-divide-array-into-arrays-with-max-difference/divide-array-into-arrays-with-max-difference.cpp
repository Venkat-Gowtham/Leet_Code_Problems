class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int x=0,n=nums.size(),ind=0;
        vector<vector<int>>res;
        for(int i=0;i<nums.size()-2;i+=3)
        {
            if(nums[i+2]-nums[i]<=k)res.push_back({nums[i],nums[i+1],nums[i+2]});
            else return {};
        }
        return res;
    }
};