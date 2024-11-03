class Solution {
public:
    bool rotateString(string s, string goal) {
        string x ;
        if(s==goal) return 1;
        for(int i = 0;i<s.size();i++){
            x+=s[i];
            string y = s.substr(i+1);
            if(y+x==goal) return 1;
        }
        return 0;
    }
};