class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int largest = 0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int indx = st.top();
                st.pop();
                int PSE = st.empty() ? -1 : st.top();
                int NSE = i;
                int area = heights[indx] * ((NSE - PSE) -1);
                largest = max(largest, area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int indx = st.top();
            st.pop();
            int PSE = st.empty() ? -1 : st.top();
            int NSE = n;
            int area = heights[indx] * ((NSE - PSE) -1);
            largest = max(largest, area);
        }
        return largest;
    }
};