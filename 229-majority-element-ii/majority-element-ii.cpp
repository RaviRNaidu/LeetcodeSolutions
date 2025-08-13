class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        int floor = n/3;
        int el1, el2;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && arr[i] != el2){
                el1 = arr[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && arr[i] != el1){
                el2 = arr[i];
                cnt2 = 1;
            }
            else if(arr[i] == el1){
                cnt1++;
            }
            else if(arr[i] == el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int counter1 = 0;
        int counter2 = 0;
        for(int i=0;i<n;i++){
            if(arr[i] == el1){
                counter1 += 1;
            }
            else if(arr[i] == el2){
                counter2 += 1;
            }
        }

        if(counter1 > floor){
            ans.push_back(el1);
        }
        if(counter2 > floor){
            ans.push_back(el2);
        }
        return ans;
    }
};