class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long combine = cost1 + cost2;
        if(combine <= costBoth){
            return (long long)((long long)need1 * (long long)cost1) + (long long)((long long)need2 * (long long)cost2);
        }
        else{
            long long total = (long long)min(need1, need2) * (long long)costBoth;
            if(need1 > need2){
                long long rem = need1 - need2;
                total += (long long)min(cost1, costBoth) * rem;
            }
            else{
                long long rem = need2 - need1;
                total += (long long)min(cost2, costBoth) * rem;
            }
            return total;
        }
        return 0;
    }
};