class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>a(26,0),b(26,0);
        int c = 0;
        for(int i = 0;i<s1.size();i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
            if(s1[i]!=s2[i])c++;
        }
        for(int i = 0;i<26;i++){
            if(a[i]!=b[i]) return false;
        }
        return c<=2;
    }
};