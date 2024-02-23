class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       
        vector<pair<int,int>>adj[n];
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,int>>pq;
        pq.push({src,0});
        vector<int>vis(n,INT_MAX);

       for(int z = 0 ; z<=k;z++)
        {
            int siz  = pq.size();
            for(int i=0;i<siz;i++)
            {
                  int prize = pq.front().second;
                  for(auto it : adj[pq.front().first]){
                      int new_price = it.second+prize;
                      if(new_price<vis[it.first]){
                          vis[it.first] = new_price;
                          pq.push({it.first,new_price});
                      }
                  }
                  pq.pop();
            }
        }
        return vis[dst] == INT_MAX?-1:vis[dst];
        
        
    }
};