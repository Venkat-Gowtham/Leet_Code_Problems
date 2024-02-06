class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>mp;
        vector<vector<string>>val;
        for(auto it : strs)
        {
            auto it2=it;
            sort(it2.begin(),it2.end());
            mp[it2].push_back(it);
        }   
        for(auto it : mp)
        {
            val.push_back(it.second);
        }
        return val;
    }
};