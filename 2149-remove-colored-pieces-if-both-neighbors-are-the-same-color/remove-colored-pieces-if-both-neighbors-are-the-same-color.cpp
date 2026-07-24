class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        int n = colors.size();
        int i = 0;
        while(i < n){
            char c = colors[i];
            int j = i+1;
            while(j < n && colors[j] == c){
                j++;
            }
            int sum = (j - i);
            if(sum >= 3){
                if(c == 'A'){
                    alice += (sum - 2);
                }
                else{
                    bob += (sum - 2);
                }
            }
            i = j;
        }
        return alice > bob;
    }
};