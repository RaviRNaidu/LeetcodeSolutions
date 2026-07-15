class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        int firstOdd = 1;
        int firstEven = 2;
        for(int i=0;i<n;i++){
            sumOdd += firstOdd;
            sumEven += firstEven;
            firstOdd += 2;
            firstEven += 2;
        }
        return gcd(sumOdd, sumEven);
    }
};