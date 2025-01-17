class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n==1) return !derived[0];
        if(n == 2 )return derived[0]==derived[1];
        int  v = derived[n-1]; 
        for(int i = n-2;i>0;i--){
            v= v^derived[i];
        }
        return v==derived[0];
    }             
};