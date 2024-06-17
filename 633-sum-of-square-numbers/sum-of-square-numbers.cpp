class Solution {
public:
#define ll long long 
vector<ll> genSieve(){
    vector<ll>primes;
    for(int i =0;i<=100000;i++){
        primes.push_back(1LL*i*i);
    }
    return primes;
}
bool isPossible(vector<ll>&primes, ll n){
    unordered_set<ll>mp;
    mp.insert(0);
    mp.insert(1);
    for(int i = 0;i<primes.size();i++){
        if(n-primes[i]==primes[i])return 1;
        if(mp.find(n-primes[i])!=mp.end())return 1;
        mp.insert(primes[i]);
    }
    return 0;
}
    bool judgeSquareSum(int c) {
            vector<ll>primes = genSieve();
            return isPossible(primes,c);
    }
};