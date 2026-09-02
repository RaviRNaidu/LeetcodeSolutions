class Solution {
    bool check(vector<int>& nums1, bool type, int n){
        for(int i=0;i<n;i++){
            if(type){
                if(nums1[i] % 2 == 0) continue;
                else{
                    bool valid = false;
                    for(int j=0;j<n;j++){
                        if(j == i) continue;
                        int temp = nums1[i] - nums1[j];
                        if(temp % 2 == 0){
                            valid = true;
                            break;
                        }
                    }
                    if(!valid) return false;
                }
            }
            else{
                if(nums1[i] % 2 != 0) continue;
                else{
                    bool valid = false;
                    for(int j=0;j<n;j++){
                        if(j == i) continue;
                        int temp = nums1[i] - nums1[j];
                        if(temp % 2 != 0){
                            valid = true;
                            break;
                        }
                    }
                    if(!valid) return false;
                }
            }
        }
        return true;
    }
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        bool ans = check(nums1, true, n);
        ans = ans || check(nums1, false, n);
        return ans;
    }
};