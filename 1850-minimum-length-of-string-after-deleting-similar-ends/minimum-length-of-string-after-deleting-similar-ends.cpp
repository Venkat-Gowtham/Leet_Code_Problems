class Solution {
public:
    int minimumLength(string s) {
      int i = 0, j = s.length()-1;
      while(i<j)
      {
         if(s[i] == s[j])
         {
             while(i<j and s[i]==s[i+1])i++;
             while(i<j and s[j]==s[j-1])j--;
             i++;
             j--;
         }
         else break;
      }
      return i>j?0:j-i+1;
    }
};