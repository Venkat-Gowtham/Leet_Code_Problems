class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n=temp.size();
        vector<int>res(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                res[i]=0;
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
                    res[i]=st.top()-i;
                }
                st.push(i);
            }
        }
        return res;
    }
};