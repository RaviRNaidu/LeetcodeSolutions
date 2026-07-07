class Solution {
    long long reversee(int n, long long &sum){
        long long num = 0;
        while(n > 0){
            int rem = n % 10;
            n /= 10;
            sum += rem;
            num += rem;
            if(n > 0) num *= 10;
        }
        return num;
    }
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        while(n > 0){
            int rem = n % 10;\
            n /= 10;
            if(rem == 0) continue;
            num += rem;
            if(n > 0) num *= 10;
        }

        if(num == 0) return 0;

        long long sum = 0;
        num = reversee(num, sum);
        return sum * num;
    }
};