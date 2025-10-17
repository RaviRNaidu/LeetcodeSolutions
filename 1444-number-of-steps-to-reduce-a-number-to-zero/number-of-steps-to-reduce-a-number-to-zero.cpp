class Solution {
public:
    int numberOfSteps(int num) {
        int el = num;
        int cnt = 0;
        while(el > 0){
            if(el % 2 == 0){
                cnt++;
                el = el / 2;
            }
            else{
                cnt++;
                el -= 1;
            }
        }
        return cnt;
    }
};