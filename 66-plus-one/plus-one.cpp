class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        int carry = 0;
        int newNum = digits[n-1] + 1;
        if(newNum > 9){
            carry = 1;
            ans.push_back(0);
        }
        else{
            ans.push_back(newNum);
        }
        for(int i=n-2;i>=0;i--){
            int sum = digits[i] + carry;
            carry = 0;
            if(sum > 9){
                carry = 1;
                ans.push_back(0);
            }
            else{
                ans.push_back(sum);
            }
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};