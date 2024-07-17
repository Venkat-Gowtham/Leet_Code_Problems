class Solution {
public:
    vector<int> bfs(int start, const vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> distances(n, -1);
        distances[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        return distances;
    }
    
    int findFarthest(const vector<int>& dist) {
        int max_dist = -1;
        int far_node = -1;
        for (int i = 0; i < dist.size(); ++i) {
            if (dist[i] > max_dist) {
                max_dist = dist[i];
                far_node = i;
            }
        }
        return far_node;
    }

    int findDiameter(const vector<vector<int>>& adj) {
        vector<int> dist = bfs(0, adj);
        int farthest = findFarthest(dist);
        dist = bfs(farthest, adj);
        return *max_element(dist.begin(), dist.end());
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& tree1, vector<vector<int>>& tree2) {
        int n = tree1.size();
        int m = tree2.size();
        
        if (n == 0 && m == 0) return 1;
        if (n == 0 || m == 0) return 2;

        vector<vector<int>> adj1(n + 1), adj2(m + 1);
        for (const auto& edge : tree1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (const auto& edge : tree2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        
        int dia1 = findDiameter(adj1);
        int dia2 = findDiameter(adj2);
        
        return max({(dia1 + 1) / 2 + (dia2 + 1) / 2 + 1,dia1,dia2});
    }
};