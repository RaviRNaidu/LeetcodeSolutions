class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int el;
        for(int i=0;i<n;i++){
            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }
            else if(el == nums[i]){
                cnt ++;
            }
            else{
                cnt --;
            }
        }

        int counter = 0;
        for(int j=0;j<n;j++){
            if(nums[j] == el){
                counter += 1;
            }
        }
        if(counter > n/2){
            return el;
        }
        else {
            return -1;
        }
    }
};