class Solution {
public:
    bool can_Make(int n , int cur ,int poww){
        if(n == cur) return 1;
        if(cur>n or poww>15) return 0;
        return can_Make(n,cur+pow(3,poww),poww+1) || can_Make(n,cur,poww+1);
    }
    bool checkPowersOfThree(int n) {
        return can_Make(n,0,0);
    }
};