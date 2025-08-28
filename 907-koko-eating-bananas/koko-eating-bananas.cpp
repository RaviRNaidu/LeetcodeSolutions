class Solution {
    long long totalTime(vector<int> &arr, int time){
        int n = arr.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += ceil((double)arr[i]/(double)time);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = INT_MIN;
        for(int i=0;i<n;i++){
            high = max(high, piles[i]);
        }

        while(low <= high){
            int mid = (low + high) / 2;
            long long ans = totalTime(piles, mid);
            if(ans <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};