class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<pair<int,int>,int>mp;
        int n = s.length();
        unordered_map<int,int>fst,lst;
        for(int i =0;i<n;i++){
            if(fst.find(s[i]-'a')==fst.end()){
                fst[s[i]-'a']=i;
            }
            else{
                lst[s[i]-'a']=i;
            }
        }
        for(int i = 0;i<n;i++){
            char c = s[i];
            for(int j=0;j<26;j++){
                if(fst[j]<i and lst[j]>i){
                    mp[{c-'a',j}]++;
                }
            }
        }
        return mp.size();
         
    }
};