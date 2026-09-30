class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> sufA(n, 0);
        for(int i=n-2;i>=0;i--){
            sufA[i] = sufA[i+1];
            if(s[i+1] == 'a'){
                sufA[i]++;
            }
        }

        int cntB = 0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, sufA[i] + cntB);
            if(s[i] == 'b'){
                cntB++;
            }
        }

        return ans;
    }
};