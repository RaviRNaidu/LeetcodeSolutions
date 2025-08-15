class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i > 0 && arr[i] == arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j > i+1 && arr[j] == arr[j-1]) continue;
                int k = j + 1;
                int h = n - 1;
                while(k < h){
                    long long sum = arr[i];
                    sum += arr[j];
                    sum += arr[k];
                    sum += arr[h];
                    if(sum > target){
                        h--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        vector<int> temp  = {arr[i],arr[j],arr[k],arr[h]};
                        ans.push_back(temp);
                        k++;
                        h--;
                        while(k < h && arr[k] == arr[k-1]) k++;
                        while(k < h && arr[h] == arr[h+1]) h--;
                    }
                }
            }
        }
        return ans;
    }
};