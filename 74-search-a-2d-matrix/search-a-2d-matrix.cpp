class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n*m) - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int rowIndex = mid / m;
            int columnIndex = mid % m;
            if(matrix[rowIndex][columnIndex] == target){
                return true;
            }
            else if(matrix[rowIndex][columnIndex] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};