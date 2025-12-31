class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1 && val == nums[0]) return 0;
        if(n == 1 && val != nums[0]) return 1;
        int ptr1 = 0;
        int ptr2 = n-1;
        while(ptr1 != ptr2){
            if(nums[ptr1] == val){
                int temp = nums[ptr1];
                nums[ptr1] = nums[ptr2];
                nums[ptr2] = temp;
                ptr2--;
            }
            else{
                ptr1++;
            }
        }
        if(nums[ptr1] == val){
            return ptr1;
        }
        return ptr1 + 1;
    }
};