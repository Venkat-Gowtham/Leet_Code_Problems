class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>st;
        int n=nums.size(),total=(n*(n+1))/2,ar=0,val=0;
          for(auto it : nums)
          {
              ar+=it;
              if(st.find(it)!=st.end()){val=it;ar-=it;}
              else st.insert(it);
          } 
          return {val,total-ar};
    }
};