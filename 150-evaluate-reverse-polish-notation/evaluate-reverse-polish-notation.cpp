class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"|| tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int a=st.top();
                char x=tokens[i][0];
                st.pop();
                int b=st.top();
                st.pop();
                // cout<<a<<" "<<b;
                if(x=='+') st.push(a+b);
                else if(x=='-')st.push(b-a);
                else if(x=='*')st.push(a*b);
                else st.push(b/a);
            }
            else
            {
                // cout<<tokens[i][0]-'0';
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};