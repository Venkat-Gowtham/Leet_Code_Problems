class Solution {
public:
    int findmax(long long  m , vector<int>&quantities,int n){
        int size = quantities.size();
        long long res = 0,c=0;
        cout<<m<<" ";
        for(int i = 0;i<size;i++){
            int x= quantities[i]/m;
            c+=x;
            if(quantities[i]%m)c++;
        }
        cout<<c<<endl;
        return c<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long l = 1 , h= 1e6 , res = 1e6;
        long long  ma = accumulate(begin(quantities),end(quantities),1LL*0);
        h=ma;
        while(l<=h){
            long long  mid = l+(h-l)/2;
            long long val = findmax(mid,quantities,n);
            if(!val){
                l = mid+1;
            }
            else{
                res=min(res,mid);
                h = mid - 1;
            }
        }
        return (int)res;
    }
};