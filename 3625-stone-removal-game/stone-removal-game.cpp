class Solution {
public:
    bool canAliceWin(int n) {
        bool turn = true;
        for(int i=10;i>=0;i--){
            if(n < i){
                if(turn) return false;
                else return true;
            }
            n -= i;
            turn = !turn;
        }
        return true;
    }
};