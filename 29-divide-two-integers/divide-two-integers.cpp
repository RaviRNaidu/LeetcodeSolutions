class Solution {
public:
    int divide(long dividend, long divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;
        if(dividend >= 0 && divisor < 0){
            sign = false;
        }
        else if(dividend <= 0 && divisor > 0){
            sign = false;
        }

        long n = abs(dividend);
        long m = abs(divisor);
        divisor = abs(divisor);
        long ans = 0;

        while(n >= m){
            int pow = 0;
            while(n >= (m<<(pow+1))){
                pow++;
            }
            n = n - (m<<pow);
            ans = ans + (1<<pow);
        }
        
        if(ans == (1<<31) && sign){
            return INT_MAX;
        }
        if(ans == (1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? ans : -1 * ans;
    } 
};