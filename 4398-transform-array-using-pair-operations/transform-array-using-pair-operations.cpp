class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size();
        long long sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++){
            sum1 += source[i];
            sum2 += target[i];
        }
        if(sum1 != sum2) return false;
        return true;
        // for(int i=0;i<n-1;i++){
        //     if(source[i] != target[i]){
        //         long long delta = (long long)(source[i] + source[n-1]) - target[i];
        //         source[i] = target[i];
        //         source[n-1] = delta;
        //     }
        // }
        // return source[n-1] == target[n-1];
    }
};