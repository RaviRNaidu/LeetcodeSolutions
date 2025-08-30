class Solution {
    bool checking(vector<int> &arr, int maxWeight, int days){
        int n = arr.size();
        int weight = arr[0]; int ans = 1;
        for(int i=1;i<n;i++){
            weight += arr[i];
            if(weight <= maxWeight){
                continue;
            }
            else{
                ans += 1;
                weight = arr[i];
            }
        }
        if(ans <= days){
            return true;
        }
        else return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = INT_MIN;
        int high = 0;
        for(int i=0;i<n;i++){
            low = max(low, weights[i]);
            high += weights[i];
        }

        while(low <= high){
            int mid = (low + high) / 2;
            int ans = checking(weights, mid, days);
            if(ans == 1){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};