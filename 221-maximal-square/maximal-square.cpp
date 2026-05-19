class Solution {
    int findingArea(vector<int> &arr){
        int n = arr.size();
        vector<int> NSE(n), PSE(n);
        stack<int> st;
        int i = n-1;
        while(i >= 0){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                NSE[i] = n;
            }
            else{
                NSE[i] = st.top();
            }
            st.push(i);
            i--;
        }

        while(!st.empty()) st.pop();

        //PSE
        i = 0;
        while(i < n){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                PSE[i] = -1;
            }
            else{
                PSE[i] = st.top();
            }
            st.push(i);
            i++;
        }

        int ans = INT_MIN;
        for(int j=0;j<n;j++){
            int width = NSE[j] - PSE[j] - 1;
            int side = min(width, arr[j]);
            ans = max(ans, side * side);
        }
        return ans;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m, 0);

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    temp[j]++;
                }
                else{
                    temp[j] = 0;
                }
            }
            ans = max(ans, findingArea(temp));
        }

        return ans;
    }
};