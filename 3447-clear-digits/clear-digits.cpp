class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        unordered_set<int>sett;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i]>='a' and s[i]<='z') st.push(i);
            else{
                if(st.empty()) continue;
                else {sett.insert(st.top());sett.insert(i);
                st.pop();}
            }
        }
       string res;
       for(int i = 0;i<s.length();i++){
        if(sett.find(i)==sett.end()){
            res+=s[i];
        }
       }
       return res;
    }
};