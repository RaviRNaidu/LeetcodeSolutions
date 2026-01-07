class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mpp.insert({nums2[i],-1});
                // mpp[nums2[i]] = -1;
            }
            else{
                mpp.insert({nums2[i],st.top()});
                // mpp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        int m = nums1.size();
        for(int i=0;i<m;i++){
            int el = nums1[i];
            if(mpp.find(el) != mpp.end()){
                ans.push_back(mpp[el]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};