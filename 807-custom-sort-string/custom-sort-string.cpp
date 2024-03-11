class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp,store;
        for(auto it: s)mp[it]++;
        string res;
        for( auto it : order){
            if (mp[it]>0){
               while(mp[it]--){
                   res+=it;
               }
                mp.erase(it);
            }
        }
        for(auto it : s){
           if(mp[it])res+=it;
        }
        return res;
        
    }
};