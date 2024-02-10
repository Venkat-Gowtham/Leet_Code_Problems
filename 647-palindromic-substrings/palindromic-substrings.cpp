class Solution {
public:
    int c=0;
    bool ispal(int i, int j, string&s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    void findd(int i, int j, string&s)
    {
         while(i>=0 and j<s.length())
           {
               if(ispal(i,j,s))
               {
                   c++;
                   i--;
                   j++;
               }
               else break;
           }
    }
    int countSubstrings(string s) {
        for(int i=0;i<s.length();i++)
        {
            findd(i,i,s);
           findd(i,i+1,s);
        }
        return c;
    }
};