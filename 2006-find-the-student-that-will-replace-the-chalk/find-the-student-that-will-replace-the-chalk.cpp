class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = 0;
        for(int i = 0 ; i<chalk.size();i++){
            s += chalk[i];
        }
        int  rem = 0;
        if(s>=k) rem = k; 
        else rem = k%s;
        if(rem == 0) return 0;
        for(int i = 0;i<chalk.size();i++){
            if(rem>=chalk[i]) rem -=chalk[i];
            else return i;
        }
        return 0;
    }
};