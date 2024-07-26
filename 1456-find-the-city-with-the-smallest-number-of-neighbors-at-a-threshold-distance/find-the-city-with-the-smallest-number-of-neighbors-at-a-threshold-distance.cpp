class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
     map<pair<int,int>,int>mp;
      vector<vector<int>>res(n,vector<int>(n,INT_MAX));
        for(int i = 0; i < edges.size();i++){
            res[edges[i][0]][edges[i][1]]=edges[i][2];
            res[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i = 0;i<n;i++)res[i][i]=0;
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j =0;j<n;j++){
                    if(res[i][k]!=INT_MAX and res[k][j]!=INT_MAX){
                        res[i][j] = min(res[i][j],res[i][k]+res[k][j]);
                    }
                }
            }
        }
        int ans = n,ma=n+1;
        for(int i = 0;i<n;i++){
            int val = 0;
            for(int j = 0;j<n;j++){
                if(i!=j and res[i][j]<=distanceThreshold)val++;
            }
            if(val<=ma){
                ans = i;
                ma=val;
            }
        }
        return ans;

    }
};