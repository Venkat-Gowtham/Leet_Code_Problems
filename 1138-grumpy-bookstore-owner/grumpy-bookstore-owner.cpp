class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0, cr=0 , grmax=0;
        int j = 0;
        for(int i = 0;i<n;i++){
            if(!grumpy[i])ans+=customers[i];
            else{
                cr+=customers[i];
                while(i-j>=minutes){
                    if(grumpy[j])cr-=customers[j];
                    j++;
                }
                grmax  = max(grmax,cr);
            }
        }
        return ans + grmax;
        
        
        
    }
};