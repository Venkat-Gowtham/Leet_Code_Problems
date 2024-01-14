class Solution {
public:
    int minAddToMakeValid(string s) {
        int oc=0,cs=0,n=s.length();
        if(n==0)return 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')oc++;
            else if(oc>0)oc--;
            else cs++;
        }
        return cs+oc;
    }
};