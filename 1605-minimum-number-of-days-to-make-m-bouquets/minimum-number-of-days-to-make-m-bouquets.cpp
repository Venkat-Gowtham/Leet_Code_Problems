class Solution {
public:
    int findMinDays(vector<int>&arr ,int m , int k, int mid){
        
        long long  i = 0, cur = 0,b_count = 0;
        for(int i = 0 ;i < arr.size(); i++){
            if(arr[i]<=mid){
                b_count++;
            }
            else b_count = 0;
            if(b_count == k){
                cur++;
                b_count = 0;
            }
        }
        return cur>=m;
      

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<1LL*m*k)return -1;
        // sort(bloomDay.begin(), bloomDay.end());
        int l = *min_element(begin(bloomDay),end(bloomDay)), h  = *max_element(begin(bloomDay),end(bloomDay));
        int res = INT_MAX;
        while(l<=h){

            int mid = (l+h)/2;
            if(findMinDays(bloomDay,m,k,mid)){
                h = mid-1;
                res = min(res,mid);
            }
            else{
                l = mid+1;
            }
        }
        return res==INT_MAX?-1:res;
    }
};