class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> prefix(n+1,0);
        vector<int> sufix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1];
            if(customers[i-1] == 'N'){
                prefix[i]++;
            }
        }
        for(int i=n-1;i>=0;i--){
            sufix[i] = sufix[i+1];
            if(customers[i] == 'Y'){
                sufix[i]++;
            }
        }

        int best = INT_MAX;
        int ans = 0;
        for(int i=0;i<=n;i++){
            int sum = prefix[i] + sufix[i];
            if(sum < best){
                best = sum;
                ans = i;
            }
        }
        return ans;
    }
};