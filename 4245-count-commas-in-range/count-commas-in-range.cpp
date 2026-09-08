class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i=1000;i<=n;i++){
            if(i <= 999999){
                ans++;
            }
            else if(i <= 999999999){
                ans += 2;
            }
            else if(i <= 999999999999){
                ans += 3;
            }
            else{
                ans += 4;
            }
        }
        return ans;
    }
};