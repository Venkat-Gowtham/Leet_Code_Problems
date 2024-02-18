#define pii pair<long long ,long long>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        // priortity_queue<pair<int,int>>pq;
        if(n==1 or meet.size()==1)return 0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        priority_queue<int>mt;
        sort(meet.begin(),meet.end());
        int k = 0 , m = meet.size(); 
        vector<int>res(n,0);
        for(int i=0;i<n;i++)
        {
            // pq.push({meet[i][1],i});   
            // res[i]++;
            mt.push(-1*i);
        }
        for(int i=0;i<meet.size();i++)
        {
            while(!pq.empty() and pq.top().first<=meet[i][0])
            {
                    int x=pq.top().second;
                    mt.push(-x);
                    pq.pop();
            }
            if(!mt.empty())
            {
                long long ro_no=-1*mt.top();
                res[ro_no]++;
                pq.push({meet[i][1],ro_no});
                mt.pop();
            }
            else
            {
                 auto [end, room ] = pq.top();
                  pq.pop();
                  res[room]++;
                 pq.push({end+meet[i][1]-meet[i][0],room});
                  
                 
            }
        }
        return max_element(res.begin(),res.end()) - res.begin();
    }
};