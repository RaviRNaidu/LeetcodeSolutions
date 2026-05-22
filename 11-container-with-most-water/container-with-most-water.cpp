class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water = INT_MIN;
        while(i < j){
            int sum = (j - i) * min(height[i], height[j]);
            water = max(water, sum);

            if(height[i] <= height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return water;
    }
};