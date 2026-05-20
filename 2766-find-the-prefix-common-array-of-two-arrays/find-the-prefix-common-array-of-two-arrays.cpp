class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> hash(n + 1, 0);
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int cnt = 0;
            if(A[i] == B[i]) cnt++;
            if(hash[A[i]] != 0) cnt++;
            if(hash[B[i]] != 0) cnt++;
            if(i > 0) ans[i] = ans[i-1] + cnt;
            else ans[i] = cnt;
            hash[A[i]] = 1;
            hash[B[i]] = 1;
        }
        return ans;
    }
};