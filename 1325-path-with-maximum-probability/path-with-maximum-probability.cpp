class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>dis(n,0);
        vector<pair<int,double>>adj[n];
        for(int i = 0;i<edges.size();i++){
            auto it  = edges[i];
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
        }
        dis[start_node] = 1;
        priority_queue<pair<double,int>>pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            auto sofar = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                if(dis[node] != 0 and dis[it.first] < ( sofar * it.second))
                {
                    dis[it.first]=sofar * it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
            return dis[end_node];




    }
};