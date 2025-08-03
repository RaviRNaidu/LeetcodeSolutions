class Solution {
public:
    int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    
        if(sum > maxSum){
            maxSum = sum;
        }
        
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
    }
};