class Solution {
public:
    long long findScore(vector<int>& nums) {
        unordered_set<int>st;
        priority_queue<pair<long long ,int>>pq;
        for(int i =0;i<nums.size();i++)pq.push({-1*nums[i],-1*i});
        long long  ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(st.find(-1*it.second)!=st.end()){
                continue;
            }
            ans+=-1*it.first;
            if(-1*it.second>0)st.insert(-1*it.second-1);
            if(-1*it.second<nums.size()-1)st.insert(-1*it.second+1);
        }
        return ans;
    }
};