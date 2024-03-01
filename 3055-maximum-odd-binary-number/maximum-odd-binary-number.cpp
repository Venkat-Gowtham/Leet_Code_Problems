class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int j = s.length() -1 ,  i = s.length()-1;
        while( j>=0 and s[j]!='1')
        {
            j--;
        }
        s[j] = '0';
        s[i] ='1';
        j-=1;
        int c = 0;
        while(j>=0)
        {
           if(s[j--]=='1') c++;
        }
        cout<<c;
        i = 0;
        while(c--)
        {
            s[i++]='1';
        }
        for(i;i<s.length()-1;i++)s[i]='0';
        return s;

    }
};