class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=0;i<=t;i++){
            int product = 1;
            int num = n + i;
            int temp = num;
            while(temp > 0){
                int rem = temp % 10;
                temp = temp / 10;
                product *= rem;
            }
            if(product % t == 0) return num;
        }
        return n;
    }
};