class Solution {
    int bouquets(vector<int> &arr, int k, int day){
        int n = arr.size();
        int cnt = 0;
        int possible = 0;
        for(int i=0;i<n;i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                possible += (cnt/k);
                cnt = 0;
            }
        }
        possible += (cnt/k);
        return possible;
    }
public:
    long long minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n/k < m) return -1;
        int low = INT_MAX;
        int high = INT_MIN;
        for(int i=0;i<n;i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        while(low <= high){
            int mid = (low + high)/2;
            int ans = bouquets(bloomDay,k,mid);
            if(ans < m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};