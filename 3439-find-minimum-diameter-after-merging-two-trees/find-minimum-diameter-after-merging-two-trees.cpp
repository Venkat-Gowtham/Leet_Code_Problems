class Solution {
public:
    vector<int>bfs(int start , vector<vector<int>>&adj,int n){
      vector<int>distances(n+1,-1);
      distances[start] = 0;
      queue<int>q;
      q.push(start);
      while(!q.empty()){
          int neighbor = q.front();
          q.pop();
          for(auto it : adj[neighbor]){
              if(distances[it] == -1){
                  distances[it] = distances[neighbor] +1;
                  q.push(it);
              }
          }
      }
      return distances;
  }
  int findFarthest(vector<int>&dist){
      int max_dist = -1;
      int far_node = -1;
      for(int i = 0;i<dist.size(); i++){
          if(dist[i]>max_dist){
              far_node = i;
              max_dist = dist[i];
          }
      }
      return far_node;
  }
    int minimumDiameterAfterMerge(vector<vector<int>>& tree1, vector<vector<int>>& tree2) {
        int n = tree1.size(),m=tree2.size();
        if(n<1 and  m<1)return 1;
        if(n<1 or m<1)return 2;
        // vector<int>adj1[n+1],adj2[m+1];
        vector<vector<int>>adj1(n+1),adj2(m+1);
        for(int i =0;i<tree1.size();i++){
            adj1[tree1[i][0]].push_back(tree1[i][1]);
            adj1[tree1[i][1]].push_back(tree1[i][0]);
            // cout<<tree1[i][0]<<" "<<tree1[i][1]<<endl;
        }
        for(int i = 0;i<tree2.size();i++){
            adj2[tree2[i][0]].push_back(tree2[i][1]);
            adj2[tree2[i][1]].push_back(tree2[i][0]);
        }
        // initial bfs call
        vector<int> dist1 = bfs(0,adj1,n);
        // finding farthest node 
        int firstFarther = findFarthest(dist1);
        
        // finding distances from first fartther 
        // using bfs
        vector<int>ff1 = bfs(firstFarther,adj1,n);
        
        int secondFarther = findFarthest(ff1);
        
        // cout<<secondFarther<<" "<<ff1[secondFarther]<<endl;
        vector<int>ss1 = bfs(secondFarther,adj1,n);
        // cout<<"f- "<<firstFarther<<" "<<"s- "<<secondFarther<<endl;
        vector<int>tree1_dist(n+1,0);
        for(int i = 0 ;i<n+1;i++){
            // cout<<ff1[i]<<" "<<ss1[i]<<endl;
            tree1_dist[i] = max(ff1[i],ss1[i]);
            cout<<i<<" "<<tree1_dist[i]<<endl;
        }
        
        // for tree 2 
        // initial bfs call
        vector<int> dist2 = bfs(0,adj2,m);
        // finding farthest node 
        int firstFarther1 = findFarthest(dist2);
        
        // finding distances from first fartther 
        // using bfs
        vector<int>ff2 = bfs(firstFarther1,adj2,m);
        
        int secondFarther2 = findFarthest(ff2);
        
        vector<int>ss2 = bfs(secondFarther2,adj2,m);
        
        vector<int>tree2_dist(m+1);
        for(int i = 0 ;i<m+1;i++){
            tree2_dist[i] = max(ff2[i],ss2[i]);
            // cout<<tree2_dist[i]<<" "<<i<<endl;
        }
        
        vector<int>res(m);
        int l = *min_element(tree1_dist.begin(),tree1_dist.end());
        // cout<<l<<" ";
        l+= *min_element(tree2_dist.begin(),tree2_dist.end());
        // cout<<l<<" ";
        int a = *max_element(tree1_dist.begin(),tree1_dist.end());
        int b =*max_element(tree2_dist.begin(),tree2_dist.end());
        // cout<<a<<" "<<b;
        // ans+=*min_element(tree2_dist.begin(),tree2_dist.end());
        return max({l+1,a,b});
    }
};