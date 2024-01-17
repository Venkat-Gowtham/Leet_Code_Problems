class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        set<int>l;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            l.insert(it.second);   
        }
        return l.size()==mp.size();
    }
};