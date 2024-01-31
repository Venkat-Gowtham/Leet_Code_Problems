class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n=temp.size();
        vector<int>res;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                res.push_back(0);
                st.push(i);
            }
            else
            {
                while( !st.empty() and temp[st.top()]<=temp[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    res.push_back(st.top()-i);
                }
                else
                {
                    res.push_back(0);
                }
                st.push(i);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};