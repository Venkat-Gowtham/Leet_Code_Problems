class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       long long num  = 0,one=1;
        vector<int>ans;
        int cnt =0;
        for(int i = 0;i<A.size();i++){
            if((num>>A[i])&1)cnt++;
            else num = num | (one<<A[i]);
            if((num>>B[i])&1)cnt++;
            else num  = num |(one<<B[i]);
            ans.push_back(cnt);
        }
        return ans;
    }
};