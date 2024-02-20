class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n=accumulate(nums.begin(), nums.end(),0);
         long long x=nums.size() , val=x*(x+1)/2;
        return val-n;
    }
};