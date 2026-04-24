class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int right = 0;
        int left = 0;
        for(int i=0;i<n;i++){
            if(moves[i] == 'L'){
                right--;
                left++;
            }
            else if(moves[i] == 'R'){
                right++;
                left--;
            }
            else{
                right++;
                left++;
            }
        }
        return max(left,right);
    }
};