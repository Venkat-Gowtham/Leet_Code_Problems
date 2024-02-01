class Solution {
public:
    int minCost(string colors, vector<int>& needed) {
        stack<pair<char,int>>st;
        int res=0;
        for(int i=0;i<needed.size();i++)
        {
            if(st.empty())
            {
                st.push({colors[i],i});
            }
            else
            {
                if(st.top().first==colors[i])
                {
                    auto it =st.top();
                        if(needed[it.second]<=needed[i])
                        {
                            res+=needed[it.second];
                            st.pop();
                            st.push({colors[i],i});
                        }
                        else res+=needed[i];
                }
               else st.push({colors[i],i});
            }
        }
       return res;
    }
};