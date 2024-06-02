class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int ind = 0 , upto = 0 , i=0;
            for(i =0;i<gas.size();i++){
                if(upto+gas[i]-cost[i]<0){
                    upto=0;
                    ind = i+1;
                }
                else{
                    upto+=gas[i]-cost[i];
                }
            }
            i=0;
            while(i<ind){
                if(upto+gas[i]-cost[i]<0){
                    return -1;
                }
                upto+=gas[i]-cost[i];
                i++;
            }
            return ind;
    }
};