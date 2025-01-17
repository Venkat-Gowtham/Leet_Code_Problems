class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int zcf=0,zcs=0;
        for(int i = 0;i<nums1.size();i++)if(nums1[i]==0)zcf++;
        for(int i = 0;i<nums2.size();i++)if(nums2[i]==0)zcs++;

        unordered_map<int,int>mp;
        for(int i =0;i<nums1.size();i++){
                mp[nums1[i]]+=nums2.size()-zcs;
        }
        for(int i =0;i<nums2.size();i++){
                if(nums2[i]==0)continue;
                mp[nums2[i]]+=nums1.size();
        }
        int res = 0;
        for(auto it : mp){
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second%2)res^=it.first;
        }

        return res;


        
      
        

    }
};