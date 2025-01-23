class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        set<vector<int>>st;
        int i = 0, j = i+1,k,l;
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;

        for(int j = i+1;j<n;j++){
               if(j>i+1 && nums[j]==nums[j-1]) continue;
            int k = j+1,l=n-1;
            while(k<l){
                long long int  s= 0;
                s+=nums[i];
                s+=nums[j];
                s+=nums[k];
                s+=nums[l];
                long long int t = target;
                if(s<t){
                    k++;
                }
                else if(s>t){
                    l--;
                }
                else{
                    vector<int>sub;
                    sub.push_back(nums[i]);
                    sub.push_back(nums[j]);
                    sub.push_back(nums[k]);
                    sub.push_back(nums[l]);
                    sort(begin(sub),end(sub));
                    st.insert(sub);
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]){
                        k++;
                    }
                    while(k<l and nums[l]==nums[j+1]){
                        l--;
                    }
                }
            }
        }
        }
        return vector<vector<int>>(st.begin(),st.end());
    }
};