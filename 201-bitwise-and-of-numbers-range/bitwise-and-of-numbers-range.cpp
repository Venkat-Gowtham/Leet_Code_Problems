class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c=0;
        while(left!=right)
        {
            left=left>>1;
            right=right>>1;
            c+=1;
        }
        if(left==0)return 0;
        return left<<c;

    }
};