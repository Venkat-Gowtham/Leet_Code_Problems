class Solution {
public:
    bool static comp(const string &a , const string &b){
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto it : nums){
            arr.push_back(to_string(it));
        }
        sort(begin(arr),end(arr),comp);
        string s;
        for(auto it : arr) s+=it;
        if(s[0]=='0') return "0";
        return s;
    }
};