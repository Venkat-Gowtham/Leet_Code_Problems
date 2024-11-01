class Solution {
public:
    string makeFancyString(string s) {
        int i = 0;
        if(s.size()<=2) return s;
        while(i<s.size()){
            int j = i+1;
            while(j<s.size() and s[i]==s[j]){
                j++;
            }
            if(j-i>=3){
                if(j-i==3) s.erase(i,1);
                else if(j-i==4) s.erase(i,2);
                else s.erase(i,j-i-2);
                i=i+2;

            }
            else i=j;
        }
        return s;
    }
};