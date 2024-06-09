class Solution {
public:
int find_max(unordered_map<int,int>&mp, vector<int>&rewards, int s){
    int p =0;
    if(mp.count(s))return mp[s];
    auto it = lower_bound(begin(rewards),end(rewards),s+1);
    if(it==end(rewards))return 0;
    int in = it-begin(rewards);
    for(int i = in;i<rewards.size();i++){
            p = max(p,rewards[i]+find_max(mp,rewards,s+rewards[i]));
        }
    return mp[s]  = p;
}
    
    int maxTotalReward(vector<int>& rewards) {
        sort(begin(rewards),end(rewards));
        int n= rewards.size();
        cout<<rewards[n-1];
        unordered_map<int,int>mp;
        return find_max(mp,rewards,0);
    }
};