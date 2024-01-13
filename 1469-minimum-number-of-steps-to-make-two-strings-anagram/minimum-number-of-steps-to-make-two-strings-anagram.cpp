class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp,np;
          int ans=0;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            np[t[i]]++;
        }
        for(auto it : np)
        {
           int val=mp[it.first];
           if(val==0)ans+=it.second;
           else if(val<it.second)
           {
               ans+=it.second-val;
           }
        }
     return ans;
    }
};
auto init = []() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();