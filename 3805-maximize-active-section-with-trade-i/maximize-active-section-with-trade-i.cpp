class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> arr;
        int i = 0;
        int sum = 0;
        while(i < n){
            char c = s[i];
            int j = i;
            while(j < n && s[j] == c){
                j++;
            }
            int num = j - i;
            if(c == '0'){
                arr.push_back(-num);
            }
            else{
                arr.push_back(num);
                sum += num;
            }
            i = j;
        }

        if(arr.size() <= 2) return sum;
        int maxi = 0;
        for(int it=1;it<arr.size()-1;it++){
            if(arr[it] > 0){
                int temp = abs(arr[it-1]) + abs(arr[it+1]);
                if(maxi < temp){
                    maxi = temp;
                }
            }
        }
        sum += maxi;
        return sum;
    }
};