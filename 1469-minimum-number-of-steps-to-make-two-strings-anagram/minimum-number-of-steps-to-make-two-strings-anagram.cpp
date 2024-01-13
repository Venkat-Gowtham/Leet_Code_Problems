class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp,np;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            np[t[i]]++;
        }
        int extra=0,ans=0;
        // a-3
        // m-1
        // n-1
        // g-1
        // r-1

        // a-3
        // m-1,g-1,r-1,n-1
        for(auto it : np)
        {
           int val=mp[it.first];
        //    cout<<val<<" "<<it.first<<endl;
           if(val==0)ans+=it.second;
           else if(val<it.second)
           {
               ans+=it.second-val;
           }
        }
     return ans;
    }
};