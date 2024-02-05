class Solution {
public:
    int firstUniqChar(string s) {
         int n=26;
    vector<int>vis(n,0);
        for(int ind=0;ind<s.length();ind++)
        {
            if(vis[s[ind]-'a']==0)vis[s[ind]-'a']=1;
            else if (vis[s[ind]-'a']==-1)continue;
            else vis[s[ind]-'a']=-1;
        }
        for(int i=0;i<s.length();i++)
        {
            if(vis[s[i]-'a']!=-1)return i;
        }
        return -1;
    }
};