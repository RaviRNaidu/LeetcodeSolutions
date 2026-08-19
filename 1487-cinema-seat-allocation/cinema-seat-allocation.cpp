class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int indx = 0;
        int ans = 0;
        int i = 1;
        for(i=1;i<=n;i++){
            if(indx == reservedSeats.size()){
                break;
            }
            int cnt1 = 1; 
            int cnt2 = 1; 
            int cnt3 = 1;
            while(indx < reservedSeats.size() && reservedSeats[indx][0] == i){
                if(reservedSeats[indx][1] >= 2 && reservedSeats[indx][1] <= 5){
                    cnt1 = 0;
                }
                if(reservedSeats[indx][1] >= 4 && reservedSeats[indx][1] <= 7){
                    cnt2 = 0;
                }
                if(reservedSeats[indx][1] >= 6 && reservedSeats[indx][1] <= 9){
                    cnt3 = 0;
                }
                indx++;
            }
            int sum = cnt1 + cnt2 + cnt3;
            if(sum == 3) sum = 2;
            else if(sum == 2) sum = 1;
            ans = ans + sum;
        }
        if(i != n+1){
            int rem = n - i + 1;
            ans += (rem * 2);
        }
        return ans;
    }
};