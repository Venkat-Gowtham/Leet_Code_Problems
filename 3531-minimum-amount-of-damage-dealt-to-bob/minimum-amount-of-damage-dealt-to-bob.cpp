class Solution {
public:
    bool static comp(const pair<int,pair<int,double>>&a , const pair<int,pair<int,double>>&b){
        if(a.second.second == b.second.second){
            a.second.first>b.second.first;
        }
        return a.second.second>b.second.second;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int,pair<int,double>>>arr;
        long long s = 0;
        int n = damage.size();
        for(int i = 0;i<n;i++){
              long long sec =health[i] /power;
            if(health[i]%power)sec++;
            arr.push_back({damage[i],{health[i],(double)damage[i]/sec}});
            s+=damage[i];
        }
        sort(arr.begin(),arr.end(),comp);
        long long res = 0;
        for(int i  = 0;i<n;i++){
            // auto it = upper_bound(begin(arr),end(arr),arr[i].first);
            // if(it == )
            long long dis = arr[i].first;
            long long sec = arr[i].second.first/power;
            if(arr[i].second.first%power)sec++;
            res+=(1LL*sec*s);
            s-=arr[i].first;
        }
        return res;
    }
};