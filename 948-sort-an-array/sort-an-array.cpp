class Solution {
public:
    void combine(vector<int>&nums,vector<int>&temp,int l,int m ,int r){
        int k = 0 , i =l,j=m+1;
        while(i<=m and j<=r){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }
        while(i<=m) temp[k++]=nums[i++];
        while(j<=r) temp[k++]=nums[j++];
        for(int i = l;i<=r;i++){
            nums[i]=temp[i-l];
        }
    }
    void mergesort(vector<int>&nums,vector<int>&temp,int left , int right){
        if(right>left){
            int mid = (left+right)/2;
            mergesort(nums,temp,left,mid);
            mergesort(nums,temp,mid+1,right);
           combine(nums,temp,left,mid,right);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n);
         mergesort(nums,temp,0,n-1);
         return nums;
    }
};