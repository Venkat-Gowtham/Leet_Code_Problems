class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
       vector<int>mp,np;
        unordered_map<int,int>c1,c2;
        vector<int>a,b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        mp.push_back(nums[0]);
        c1[nums[0]]++;
        c2[nums[1]]++;
        np.push_back(nums[1]);
        for(int i = 2; i<nums.size();i++)
        {
            int x = 0, y = 0;
            auto it  = upper_bound(mp.begin(),mp.end(),nums[i]);
            if (it==mp.end())x=0;
            else
            {
                x=mp.size() - distance(mp.begin(),it);
            }
            auto it2 = upper_bound(np.begin(),np.end(),nums[i]);
             if (it2==np.end())y=0;
            else
            {
                y=np.size() - distance(np.begin(),it2);
            }
                if(x>y)
                {
                    a.push_back(nums[i]);
                    mp.insert(it,nums[i]);
                    c1[nums[i]]++;
                }
                else if(x==y)
                {
                    int c = a.size() , d=b.size();
                   if(c<=d){
                       a.push_back(nums[i]);
                       mp.insert(it,nums[i]);
                    c1[nums[i]]++;
                   }
                    else {
                         np.insert(it2,nums[i]);
                        b.push_back(nums[i]);
                        c2[nums[i]]++;
                    }
                    
                }
                else {
                        b.push_back(nums[i]);
                            np.insert(it2,nums[i]);
                          c2[nums[i]]++;
                     }
        }
        for(int j = 0 ;j<b.size();j++)
        {
           a.push_back(b[j]);
        }
        return a;
        
    }
};