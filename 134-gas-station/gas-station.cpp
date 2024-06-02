class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
            int ind = 0 , upto = 0 , i=0;
            for(i =0;i<gas.size();i++){
                upto+=gas[i]-cost[i];
                if(upto<0){
                    upto=0;
                    ind = i+1;
                }
            }
            i=0;
            while(i<ind){
                upto+=gas[i]-cost[i];
                if(upto<0){
                    return -1;
                }
                i++;
            }
            return ind;
    }
};