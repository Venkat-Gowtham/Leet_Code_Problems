class Solution {
public:
    bool static cp(pair<string,int>&a,pair<string,int>&b){
        if(a.second==b.second)return a.first<b.first;
        return a.second>b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>>nh;
        for(int i = 0;i<names.size();i++)nh.push_back({names[i],heights[i]});
        sort(begin(nh),end(nh),cp);
        vector<string>res;
        for(auto it : nh)res.push_back(it.first);
        return res;
    }
};