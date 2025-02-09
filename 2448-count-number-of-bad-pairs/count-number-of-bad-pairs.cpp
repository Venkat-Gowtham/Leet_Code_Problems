class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        #define int long long
        map<int,int>res;
        for(int i=0;i<nums.size();i++){
            res[nums[i]-i]++;
        }
        //4 0 1 0
        long long  c=0;
        for(auto it : res){

            cout<<it.first<< " "<<it.second<<endl;
        }
        for(int i=0;i<nums.size();i++){
            if(res[nums[i]-i]==1){
                c+=nums.size()-1-i;
            }
            else{
                int v=res[nums[i]-i];
                if(v==nums.size())return 0;
                res[nums[i]-i]-=1;
                int p=nums.size()-1-i-v+1;
                c+=p;
            }
        }
        return c;
        #undef int
       //  1 1 1 1 0
    }
};