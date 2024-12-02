class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i = 0;i<arr.size();i++){
            if(mp.find(arr[i]*2)!=mp.end()){
                return 1;
            }
            else if(arr[i]%2==0 and mp.find(arr[i]/2)!=mp.end()){
                return 1;
            }
            mp[arr[i]]++;
        }
        return 0;

    }
};