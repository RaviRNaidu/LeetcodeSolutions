class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for(auto it:st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1;
                // int x = it;
                while(st.find(it + cnt) != st.end()){
                    cnt ++;
                    // x = x + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};