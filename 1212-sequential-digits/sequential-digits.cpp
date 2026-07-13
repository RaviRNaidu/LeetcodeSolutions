class Solution {
    int len(int num){
        int cnt = 0;
        while(num != 0){
            cnt++;
            num /= 10;
        }
        return cnt;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int minLen = len(low);
        int maxLen = len(high);
        vector<int> ans;
        for(int i=minLen;i<=maxLen;i++){
            for(int j=1;j<=9 - i + 1;j++){
                int num = j;
                int length = i;
                int increment = 1;
                while(length > 1){
                    num *= 10;
                    num += (j + increment);
                    increment++;
                    length--;
                }
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
                else if(num > high){
                    break;
                }
            }
        }
        return ans;
    }
};