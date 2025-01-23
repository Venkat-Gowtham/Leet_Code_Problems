class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        map<int,int>mp;
        int temp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for (auto it:mp){
            temp=it.first;
            break;
        }
        for(auto it:mp)cout<<it.first;
        int c=1;
       int ma=0;
        for(auto it:mp){
            if(it.first-temp==1){
                temp=it.first;
                c+=1;
            }
            else if(it.first-temp>1){
                temp=it.first;
                if(ma<c){
                    ma=c;
                }
                c=1;
            }
        }
        if(ma<c)ma=c;
        return ma;
        

    }
};