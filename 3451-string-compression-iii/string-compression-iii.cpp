class Solution {
public:
    string compressedString(string word) {
        string ans;
        int c = 1,n=word.length();
        if(n==1){
            return to_string(1)+word[0];
        }
        for(int i =1;i<n;i++){
            if(word[i]!=word[i-1] or c==9){
                ans+=to_string(c)+word[i-1];
                if(i==n-1){
                    ans+=to_string(1)+word[i];
                    // c++;
                }
                c=1;
            }
            else {
                if(i==n-1){
                    c++;
                    ans+=to_string(c)+word[i-1];
                }
                c++;
            }
        }
        return ans;
        
    }
};