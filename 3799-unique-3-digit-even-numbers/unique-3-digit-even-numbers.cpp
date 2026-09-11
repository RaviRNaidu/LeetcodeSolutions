class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        int ans = 0;
        unordered_map<int, int> mpp;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int num1 = digits[i];
                    int num2 = digits[j];
                    int num3 = digits[k];
                    if(num3 % 2 == 0){
                        if(num1 != 0 && num2 != 0){
                            int nnum = num1;
                            nnum *= 10;
                            nnum += num2;
                            nnum *= 10;
                            nnum += num3;
                            mpp[nnum]++;

                            nnum = num2;
                            nnum *= 10;
                            nnum += num1;
                            nnum *= 10;
                            nnum += num3;
                            mpp[nnum]++;
                        }
                        else if(num1 || num2){
                            if(num1){
                                int nnum = num1;
                                nnum *= 10;
                                nnum += num2;
                                nnum *= 10;
                                nnum += num3;
                                mpp[nnum]++;
                            }
                            else{
                                int nnum = num2;
                                nnum *= 10;
                                nnum += num1;
                                nnum *= 10;
                                nnum += num3;
                                mpp[nnum]++;
                            }
                        }
                    }
                    if(num2 % 2 == 0){
                        if(num1 != 0 && num3 != 0){
                            int nnum = num1;
                            nnum *= 10;
                            nnum += num3;
                            nnum *= 10;
                            nnum += num2;
                            mpp[nnum]++;

                            nnum = num3;
                            nnum *= 10;
                            nnum += num1;
                            nnum *= 10;
                            nnum += num2;
                            mpp[nnum]++;
                        }
                        else if(num1 || num3){
                            if(num1){
                                int nnum = num1;
                                nnum *= 10;
                                nnum += num3;
                                nnum *= 10;
                                nnum += num2;
                                mpp[nnum]++;
                            }
                            else{
                                int nnum = num3;
                                nnum *= 10;
                                nnum += num1;
                                nnum *= 10;
                                nnum += num2;
                                mpp[nnum]++;
                            }
                        }
                    }
                    if(num1 % 2 == 0){
                        if(num3 != 0 && num2 != 0){
                            int nnum = num3;
                            nnum *= 10;
                            nnum += num2;
                            nnum *= 10;
                            nnum += num1;
                            mpp[nnum]++;

                            nnum = num2;
                            nnum *= 10;
                            nnum += num3;
                            nnum *= 10;
                            nnum += num1;
                            mpp[nnum]++;
                        }
                        else if(num3 || num2){
                            if(num3){
                                int nnum = num3;
                                nnum *= 10;
                                nnum += num2;
                                nnum *= 10;
                                nnum += num1;
                                mpp[nnum]++;
                            }
                            else{
                                int nnum = num2;
                                nnum *= 10;
                                nnum += num3;
                                nnum *= 10;
                                nnum += num1;
                                mpp[nnum]++;
                            }
                        }
                    }
                }
            }
        }
        return mpp.size();
    }
};