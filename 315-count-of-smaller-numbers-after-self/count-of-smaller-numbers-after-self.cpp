class Solution {
public:
    void merge(vector<int>&count ,int left, int mid,int right,vector<pair<int,int>>&v){
        vector<pair<int,int>>tmp(right-left+1);
        int i = left;
        int j = mid+1;
        int k = 0;
        while(i<=mid && j<=right){
            if(v[i].first <=v[j].first){
                tmp[k++] = v[j++];
            }
            else{
                count[v[i].second]+=right-j+1;
                tmp[k++]=v[i++];
            }
        }
        while(i<=mid){
            tmp[k++] = v[i++];
        }
        while(j<=right) tmp[k++]=v[j++];
        for(int i = left;i<=right;i++){
            v[i] = tmp[i-left];
        }
    }
    void mergesort(vector<int>&count,int left, int right,vector<pair<int,int>>&v){
        if(left>=right) return;
        int mid = left+(right-left)/2;
        mergesort(count,left,mid,v);
        mergesort(count,mid+1,right,v);
        merge(count,left,mid,right,v);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v(n);
        for(int i  = 0;i<n;i++){
            v[i] = {nums[i],i};
        }
        vector<int>count(n,0);
        mergesort(count,0,n-1,v);
        return count;
    }
};  