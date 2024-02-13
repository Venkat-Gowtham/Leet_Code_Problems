class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto it : words)
        {
            int i=0,j=it.length()-1,f=0;
            while(i<j)
            {
                if(it[i]!=it[j])
                {
                    f=1;
                    break;
                }
                i++;
                j--;
            }
            if(!f)return it;
        }
        return "";
    }
};