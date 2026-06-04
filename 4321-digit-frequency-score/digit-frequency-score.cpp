class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mpp;
        while(n > 0){
            int rem = n % 10;
            mpp[rem]++;
            n = n / 10;
        }

        int ans = 0;
        for(auto it : mpp){
            ans += (it.first * it.second);
        }

        return ans;
    }
};