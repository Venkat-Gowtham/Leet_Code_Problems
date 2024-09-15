class Solution {
public:
    bool static comp(vector<int>&a , vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxPathLength(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        int x = arr[k][0];
        int y = arr[k][1];
        sort(begin(arr),end(arr),comp);
        int ind = 0;
        for(int i = 0;i<n;i++){
            if(arr[i][0]==x and arr[i][1]==y){
                ind = i;
                break;
            }
        }
        cout<<ind<<endl;
        vector<int>ans,b;
        for(int i = 0;i<ind;i++){
            if(arr[i][0]>=x or arr[i][1]>=y)continue;
            int se = arr[i][1];
            auto it = lower_bound(begin(ans),end(ans),se);
            if(it == ans.end()){
                ans.push_back(se);
            }
            else *it = se;
        }
        int a = ans.size();
        cout<<a<<endl;
        for(int i =ind+1;i<n;i++){
            if(arr[i][0]<=x or arr[i][1]<=y)continue;
            int se = arr[i][1];
            auto it = lower_bound(begin(b),end(b),se);
            if(it == b.end()){
                b.push_back(se);
            }
            else *it = se;
        }
        // cout<<b.size();
        a+=b.size();
        return a+1;
    }
};