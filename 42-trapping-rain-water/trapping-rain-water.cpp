class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int ptr1 = 0;
        int ptr2 = n-1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        while(ptr1 < ptr2){
            if(height[ptr1] <= height[ptr2]){
                if(leftMax > height[ptr1]){
                    ans += leftMax - height[ptr1];
                }
                else{
                    leftMax = height[ptr1];
                }
                ptr1++;
            }
            else{
                if(rightMax > height[ptr2]){
                    ans += rightMax - height[ptr2];
                }
                else{
                    rightMax = height[ptr2];
                }
                ptr2--;
            }
        }
        return ans;
    }
};