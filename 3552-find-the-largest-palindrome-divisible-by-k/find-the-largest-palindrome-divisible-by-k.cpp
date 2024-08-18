class Solution {
public:
    bool isPalindrome(const std::string& num) {
    int len = num.length();
    for (int i = 0; i < len / 2; ++i) {
        if (num[i] != num[len - i - 1]) {
            return false;
        }
    }
    return true;
}
    string for4(int n){
        if(n==1)return "8";
        if(n==2) return "88";
        if(n==3) return "888";
        if(n==4) return "8888";
        string r = "88";
        for(int i =0;i<n-4;i++){
            r+="9";
        }
        return r+"88";
    }
    string for8(int n){
        if(n==1)return "8";
        if(n==2) return "88";
        if(n==3) return "888";
        if(n==4) return "8888";
        if(n==6) return "888888";
        if(n==5)return "88888";
        string r = "888";
        for(int i =0;i<n-6;i++){
            r+="9";
        }
         return r+"888";
    }
    string for5(int n){
        if(n==1) return "5";
        if(n==2) return "55";
        string s = "5";
        for(int i =1;i<n/2;i++){
            s+="9";
        }
        if(n%2)s+="9";
        string rev = s.substr(0,n/2);
        reverse(begin(rev),end(rev));
        s+=rev;
        return s;
    }
    string for6(int n){
        if(n==1)return "6";
        if(n==2)return "66";
        string s="8";
        n-=2;
        while(n>2){
            s+="9";
            n-=2;
        }
        string rev = s;
        reverse(begin(rev),end(rev));
       if(n==1)s+='8'+rev;
        else s+="77"+rev;
        return s;
    }
    std::string decrementHalf(std::string half) {
    int len = half.size();
    for (int i = len - 1; i >= 0; --i) {
        if (half[i] > '0') {
            half[i]--;
            break;
        } else {
            half[i] = '9'; // reset to '9' and continue decrementing
        }
    }
    return half;
}

bool isDivisibleBy7(const std::string& num) {
    int remainder = 0;
    for (char digit : num) {
        remainder = (remainder * 10 + (digit - '0')) % 7;
    }
    return remainder == 0;
}

std::string for7(int n) {
    if (n == 1) {
        return "7";
    }

    std::string half = std::string((n + 1) / 2, '9');

    while (true) {
        std::string palindrome;
        if (n % 2 == 0) {
            palindrome = half + std::string(half.rbegin(), half.rend());
        } else {
            palindrome = half + std::string(half.rbegin() + 1, half.rend());
        }

        if (isDivisibleBy7(palindrome)) {
            return palindrome;
        }

        half = decrementHalf(half);

        if (half == std::string(half.size(), '0')) {
            break;
        }
    }

    return "";
}
    string largestPalindrome(int n, int k) {
        string s;
        if(k==1 or k ==3 or k ==9){
            for(int i=0;i<n;i++){
                s+="9";
            }
            return s;
        }
        if(k ==2){
            if(n==2)return "88";
            string s="8";
            for(int i = 1;i<n/2;i++){
                s+="9";
            }
            if(n%2 and n>2)s+="9";
            string rev = s.substr(0,n/2);
            reverse(begin(rev),end(rev));
            s+=rev;
            return s;
        }
        if(k==4)return for4(n);
        if(k==5) return for5(n);
        if(k==6)return for6(n);
        if(k==7)return for7(n);
        if(k==8)return for8(n);
        return "";
        
    }
};