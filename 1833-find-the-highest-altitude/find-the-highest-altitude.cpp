class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int st = 0;
        int n = gain.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            st += gain[i];
            maxi = max(st, maxi);
        }
        return maxi;
    }
};