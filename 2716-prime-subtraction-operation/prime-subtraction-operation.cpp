class Solution {
public:
    vector<int>primes;
    vector<int>prime;
    void sieve(){
        primes.resize(1001,1);
        primes[0]=primes[1]=0;
        for(int i = 2;i<=1000;i++){
            if(primes[i]==1){
                for(int j = i*i;j<=1000;j+=i){
                    primes[j]=0;
                }
            }
        }
        for(int i = 2;i<=1000;i++){
            if(primes[i])prime.push_back(i);
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        sieve();
        for(int i = n-2;i>=0;i--){
            cout<<nums[i];
            if(nums[i]==nums[i+1])nums[i]-=2;
            
            else if(nums[i]>nums[i+1]){
                int diff = nums[i]-nums[i+1]+1;
                auto it = lower_bound(begin(prime),end(prime),diff);
                cout<<*it<<" ";
                if(it!=prime.end()){
                    nums[i]-=*it;
                }
                else return false;
                
                // cout<<nums[i]<<" fb";                
            }
            if(nums[i]<=0)return false;

        }
        return 1;
    }
};