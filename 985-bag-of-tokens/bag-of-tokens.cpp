class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)return 0;
        sort(tokens.begin(),tokens.end());
        int i = 0  , j = tokens.size()-1, sc = 0 , mc =0;
        while(i<j)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                i++;
                sc++;
            }
            else if(sc>0)
            {
                mc=max(mc,sc);
                sc--;
                power+=tokens[j];
                j--;
            }
            else return mc;
        } 
        if(tokens[i]<=power)sc++;
        mc = max(mc, sc);
        return mc;
        
    }
};