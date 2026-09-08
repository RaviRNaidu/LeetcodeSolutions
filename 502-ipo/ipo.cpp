class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());

        priority_queue<int> pq;

        int idx = 0;
        for(int i=0;i<k;i++){
            while(idx < n && arr[idx].first <= w){
                pq.push(arr[idx].second);
                idx++;
            }

            if(pq.empty()){
                break;
            }

            w += pq.top();
            pq.pop();
        }
    
        return w;
    }
};