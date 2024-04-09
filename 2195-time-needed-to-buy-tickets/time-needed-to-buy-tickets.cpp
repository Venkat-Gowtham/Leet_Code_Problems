class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>pq;
        int c = 0;
        for(int i  = 0 ; i<tickets.size() ; i++){
            int it = tickets[i];
            if(it>1)pq.push({it-1,i});
            else  if(i==k){
                c++;
                return c;
            }
            c++;
        }
        while(!pq.empty()){
            auto it  = pq.front();
            pq.pop();
            if(it.first>1){
                pq.push({it.first-1,it.second});
            }
            else if(it.second == k){
                return c+1;
            }
            c++;
        }

        return c;

    }
};