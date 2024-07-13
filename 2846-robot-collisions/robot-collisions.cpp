class Solution {
public:
    bool static comp(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
       int n = positions.size();
       vector<vector<int>>bot(n);
       for(int i = 0 ; i < n ; i++){
        bot[i].push_back(positions[i]);
        bot[i].push_back(healths[i]);
        bot[i].push_back(directions[i]);
        bot[i].push_back(i);
       }
       sort(begin(bot), end(bot));
       stack<int>st;
    //    for(auto it : bot)cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
       for(int i = 0;i<n;i++){
         if(st.empty()){
            st.push(i);
         }
         else{
            int ind = st.top();
            if(((bot[st.top()][2]==82 and bot[i][2]==76 and bot[st.top()][0]<=bot[i][0]) or (bot[st.top()][2]==76 and bot[i][2]==82 and bot[st.top()][0]>=bot[i][0]))){
                while(!st.empty() and ((bot[st.top()][2]==82 and bot[i][2]==76 and bot[st.top()][0]<=bot[i][0]) or (bot[st.top()][2]==76 and bot[i][2]==82 and bot[st.top()][0]>=bot[i][0]))){
                    int it = st.top();
                    if(bot[it][1]>bot[i][1]){
                        if(bot[it][1]>0){
                            bot[it][1]-=1;
                            break;
                        }
                        else st.pop();
                    }
                    else if(bot[it][1]==bot[i][1]){st.pop();break;}
                    else{
                        st.pop();
                        bot[i][1]-=1;
                        if(bot[i][1]<=0)break;
                        if(st.empty() or bot[st.top()][2]==bot[i][2]) {st.push(i);break;}
                    }
                }
            }
            else st.push(i);
         }

       }
        vector<vector<int>>ans;
       while(!st.empty()){
        ans.push_back({bot[st.top()][3],bot[st.top()][1]});
        st.pop();
       }
   vector<int>res;
       sort(ans.begin(),ans.end());
    for(auto it : ans)res.push_back(it[1]);
       return res;
    }
};