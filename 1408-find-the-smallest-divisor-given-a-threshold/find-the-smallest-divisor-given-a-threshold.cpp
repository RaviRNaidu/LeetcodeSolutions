class Solution {
    int sum(vector<int> &arr, int num, int limit){
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += ceil((double)arr[i] / (double)num);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& arr, int limit) {
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi, arr[i]);
        }

        int low = 1;
        int high = maxi;
        while(low <= high){
            int mid = (low + high) / 2;
            int val = sum(arr, mid, limit);
            if(val <= limit){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low; 
    }
};