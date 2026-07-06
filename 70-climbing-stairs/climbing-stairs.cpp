class Solution {
public:
    int climbStairs(int n) {
        int left = 1;
        int fLeft = 1;
        for(int i=2;i<=n;i++){
            int curr = left + fLeft;
            fLeft = left;
            left = curr;
        }
        return left;
    }
};