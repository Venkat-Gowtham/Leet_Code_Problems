class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0,j=0 , m = s.length(), n=t.length();
        while(i<m and j<n){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        return n-j;

    }
};