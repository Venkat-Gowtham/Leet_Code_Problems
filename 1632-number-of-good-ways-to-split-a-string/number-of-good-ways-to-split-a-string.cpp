class Solution {
public:
    int numSplits(string s) {
        map<char,int>mp,np;
        for(auto it : s)
        {
            mp[it]++;
        }
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            np[s[i]]++;
            mp[s[i]]--;
            if(mp[s[i]]==0)mp.erase(s[i]);
            if(mp.size()==np.size())
            {
                res++;
            }
        }
        return res;
    }
};