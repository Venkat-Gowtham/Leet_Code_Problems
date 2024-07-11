class Solution {
public:
    int findmax(string &s , int k , int f){
        int i=0,j=0,ma=0;
        char c = f==0?'T':'F';
        while(j<s.size()){
            if(s[j] ==c)--k;
            while(k<0){
                if((s[i]==c))k++;
                i++;
            }
            j++;
            ma = max(ma, j - i);
        }
        cout<<j<<" "<<i;
        return ma ;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int tr=findmax(answerKey,k,0);
        int fr=findmax(answerKey,k,1);
        return max(tr,fr);
    }
};