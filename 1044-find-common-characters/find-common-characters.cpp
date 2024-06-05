class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>>mp(words.size(),vector<int>(26,0));
       for(int i = 0;i<words.size();i++){
            for(auto it : words[i]){
                mp[i][it-'a']++;
            }
       }
       vector<string>res;
       for(int i = 0;i<26;i++){
            int ma = INT_MAX;
            for(int j=0;j<words.size();j++){
                ma = min(ma,mp[j][i]);
            }
            for(int j = 0;j<ma;j++){
                string s;
                s+=(char)(i+97);
                res.push_back(s);
            }
       }
       return res;
    }
};