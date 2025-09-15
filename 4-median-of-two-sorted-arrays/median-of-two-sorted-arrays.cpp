class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        int index = (n + m);
        int index2 = index / 2;
        int index1 = index2 - 1;
        int el1 = 0;
        int el2 = 0;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < n && j < m){
            if(arr1[i] <= arr2[j]){
                if(cnt == index1){
                    el1 = arr1[i];
                }
                if(cnt == index2){
                    el2 = arr1[i];
                }
                cnt ++;
                i++;
            }
            else{
                if(cnt == index1){
                    el1 = arr2[j];
                }
                if(cnt == index2){
                    el2 = arr2[j];
                }
                cnt ++;
                j++;
            }
        }

        while(i < n){
            if(cnt == index1){
                el1 = arr1[i];
            }
            if(cnt == index2){
                el2 = arr1[i];
            }
            cnt ++;
            i++;
        }

        while(j < m){
            if(cnt == index1){
                el1 = arr2[j];
            }
            if(cnt == index2){
                el2 = arr2[j];
            }
            cnt ++;
            j++;
        }

        if(index % 2 == 1){
            return el2;
        }
        else {
            double ans = ((double)el1 + (double)el2) / 2.0;
            return ans;
        }
    }
};