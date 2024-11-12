class Solution {
public:
    bool static comp(const vector<int>&a,const  vector<int>&b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int upper_seach(vector<vector<int>>& items, int price){
        int l = 0 , h = items.size()-1,valid=-1;
        if(items[l][0]>price) return -1;
        while(l<=h){
            int m = (l+h)/2;
            int x = items[m][0];
            if(x>price){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return items[h][0]<=price?h:-1;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(begin(items),end(items),comp);
        int n= items.size();
        vector<int>pre(items.size(),0),ans;
        for(int i = 0;i<n;i++){
            pre[i] = max(pre[i],items[i][1]);
            if(i>0)pre[i]=max(pre[i],pre[i-1]);
        }
        for(auto price : queries){
            // auto it = upper_bound(begin(items),end(items),price);
            auto it = upper_seach(items,price);
            if(it==-1)ans.push_back(0);
            else{
                int ind = it;
                if(items[ind][0]<=price) ans.push_back(pre[ind]);
                else{
                    if(ind>0)ans.push_back(pre[ind-1]);
                    else ans.push_back(0);
                }
            }
        }
        return ans;
    }
};