class Solution {
public:
    double myPow(double x, long n) {
        double ans = 1;
        int m = n;
        n = abs(n);
        while(n > 0){
            if(n % 2 == 1){
                ans = ans * x;
                n = n - 1;
            }
            else{
                x = x * x;
                n = n / 2;
            }
        }
        if(m < 0){
            ans = 1.0 / ans;
        }
        return ans;
    }
};