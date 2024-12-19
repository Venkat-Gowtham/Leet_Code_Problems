class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>res;
        int c = 0;
        for(int i = 0;i<arr.size();i++){
            auto it  = lower_bound(begin(res),end(res),arr[i]);
            res.insert(it,arr[i]);
            if(res.back()==i)c++;
        }
        return c;

        
    }
};