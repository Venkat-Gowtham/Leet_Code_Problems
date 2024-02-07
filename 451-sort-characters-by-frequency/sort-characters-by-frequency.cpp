class Solution {
public:
    bool static comp(pair<char,int>&a, pair<char,int>&b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int>mp;
        vector<pair<char,int>>v;
        for(auto it : s)
        {
            mp[it]++;
        }   
        for(auto it : mp)
        {
            v.push_back(it);
        }
        sort(v.begin(),v.end(),comp);
        string res;
        for(auto it : v)
        {
            for(int i=0;i<it.second;i++)
            {
                res+=it.first;
            }
        }
        return res;
    }
};