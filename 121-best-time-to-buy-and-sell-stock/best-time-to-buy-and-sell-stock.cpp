class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi =prices[0]  , ma = -1;
        int res = 0;
        for(int i = 1;i<prices.size();i++){
            if(prices[i]<mi){
                mi = prices[i];
                ma = -1;
            }
            else{
                ma = max(ma,prices[i]);
                res = max(res,ma-mi);
            }
        }
        return max(0,res);
    }
};