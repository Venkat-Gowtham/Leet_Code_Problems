class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vis1(1001,0),vis2(1001,0),res;
        for(auto it : nums1){
            vis1[it]++;
        }
        for(auto it : nums2){
            if(vis1[it]>0 and vis2[it]==0){
                vis2[it]++;
                res.push_back(it);
            }
        }
        return res;
    }
};