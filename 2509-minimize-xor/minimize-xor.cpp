class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int c =0;
        while(num2){
            c+=num2%2;
            num2/=2;
        }
        int res = 0;
        for(int i = 31;i>=0;i--){
            if((1<<i)&num1){
                c--;
                res|=(1<<i);
                if(c==0)return res;
            }
        }
      
        for(int i=0;i<=31;i++){
            if(!((1<<i)&num1)){
                c--;
            }
            res=res|(1<<i);
            if(c==0)return res;
        }
        return res;


        

    }
};