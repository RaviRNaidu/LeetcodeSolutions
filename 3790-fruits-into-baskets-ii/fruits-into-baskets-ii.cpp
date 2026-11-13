class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            bool flag = true;
            for(int j=0;j<n;j++){
                if(baskets[j] >= fruits[i]){
                    baskets[j] = 0;
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};