class Solution {
public:
    bool static comp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second)return a.first>b.first;
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums)mp[it]++;
        vector<pair<int,int>>vec(mp.begin(),mp.end());
        sort(begin(vec),end(vec),comp);
        vector<int>ans;
        for(auto it : vec){
            while(it.second--)ans.push_back(it.first);
        }
        return ans;
    }
};