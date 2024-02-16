class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto it : arr)
        {
            mp[it]++;
        }
      vector<int>res;
      for(auto it : mp)
      {
          res.push_back(it.second);
      }
      sort(res.begin(),res.end());
      int c=res.size();
       for(auto it : res)
       {
           if(it<=k)
           {
               c-=1;
               k-=it;
           }
           else break;
       }
       return c;
    }
};