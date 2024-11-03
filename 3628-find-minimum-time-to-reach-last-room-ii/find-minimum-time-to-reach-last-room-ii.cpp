class Solution {
public:
bool isvalid(int m , int n , int i , int j){
    return i>=0 and j>=0 and i<m and j<n;
}
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        priority_queue<pair<int,pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,{0,0}}});
        int arr[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        
        map<pair<int,int>,int>mp;
        while(!pq.empty())
        {
            int t = pq.top().first*-1;
            int a = pq.top().second.first;
            int b = pq.top().second.second.first;
            int flag = pq.top().second.second.second;
            if(flag==1)flag=2;
            else flag=1;
            // cout<<t<<" "<<a<<" "<<b<<endl;
            pq.pop();
            if(a==m-1 and b==n-1) return t;
            for(auto it : arr)
            {
                int x = a+it[0],y=b+it[1];
                if(mp.count({x,y})) continue;
                if(isvalid(m,n,a+it[0],b+it[1]))
                {
                    int val = moveTime[a+it[0]][b+it[1]];
                    if(t>=val)
                    {
                        pq.push({-1*(t+flag),{a+it[0],{b+it[1],flag}}});    
                    }
                    else
                     {
                        pq.push({-1*(val+flag),{a+it[0],{b+it[1],flag}}});
                    }
                    mp[{x,y}]=1;
                }
            }
        }
        return 0;
    }
};