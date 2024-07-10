class Solution {
public:
    string removeStars(string s) {
        string res;
        int f=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                res.push_back(s[i]);
                f++;
            }
            else if(s[i]=='*' and f>0){
                    f--;
                    res.pop_back();
            }
        }
        return res;
    }
};