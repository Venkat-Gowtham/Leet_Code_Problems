class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(auto it : s)mp[it]++;
        int c = 0;
        for(auto it : mp)c+=it.second%2?1:2;
        return c;
    }
};