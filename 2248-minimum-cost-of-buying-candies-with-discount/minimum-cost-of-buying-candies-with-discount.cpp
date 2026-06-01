class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int sum = 0;
        int i = n-1;
        int taken = 0;
        while(i >= 0){
            if(taken == 2){
                taken = 0;
            }
            else{
                taken++;
                sum += cost[i];
            }
            i--;
        }
        return sum;
    }
};