class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())return 0;
        map<char,int>mp,np;
        map<int,int>f1,f2;
        for(auto it : word1)
        {
            mp[it]++;
        }
        for(auto it : word2)
        {
            if(mp[it]==0)return 0;
            np[it]++;
        }
        for(auto it : mp)
        {
            f1[it.second]++;
        }
        for(auto it : np)
        {
            if(f1.find(it.second)!=f1.end())
            {
                f1[it.second]--;
            }
            else
            {
                // cout<<"hhi";
                return 0;
            }
            if(f1[it.second]<=0)f1.erase(it.second);
        }
        return 1;
    }
};