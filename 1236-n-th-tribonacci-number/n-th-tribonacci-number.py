class Solution:
    def tribonacci(self, n: int) -> int:
        if n==0:
            return 0
        elif n==1 or n==2:
            return 1
        elif n==3:
            return (2)
        else:
            a=0
            b=1
            c=1
            d=a+b+c
            for i in range(4,n+1):
                a=b
                b=c
                c=d
                d=a+b+c
            return d



        