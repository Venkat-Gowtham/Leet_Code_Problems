class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int>mp;
        for(int i = 0;i<deck.size();i++){
            mp[deck[i]]++;
        }
        int gcdd=mp[deck[0]];
        for(auto it : mp){
            gcdd = __gcd(it.second,gcdd);
        }
        if(gcdd==1)return 0;
        return 1;
       
    }
};