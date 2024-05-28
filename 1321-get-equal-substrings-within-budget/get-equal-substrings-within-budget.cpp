class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length() , ma = 0,i=0,j=0,su=0;
        while(j<n){
            su+=abs((s[j]-'a')-(t[j]-'a'));
            while(su>maxCost){
                    su-=abs((s[i]-'a')-(t[i]-'a'));
                    i++;
                }
            ma=max(ma,j-i+1);
            j++;
        }
        
        return ma;
        
    }
};