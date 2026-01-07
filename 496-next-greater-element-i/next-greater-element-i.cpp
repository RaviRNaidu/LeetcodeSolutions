class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();

        vector<int> ans(m,-1);
        for(int i=0;i<m;i++){
            int el = nums1[i];
            for(int j=0;j<n;j++){
                if(nums2[j] == el){
                    for(int k = j;k<n;k++){
                        if(nums2[k] > el){
                            ans[i] = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};