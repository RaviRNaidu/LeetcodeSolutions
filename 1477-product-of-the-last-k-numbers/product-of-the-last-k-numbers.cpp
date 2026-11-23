class ProductOfNumbers {
public:
    vector<int> arr{1};
    ProductOfNumbers() {

    }
    
    void add(int num) {
        if(num == 0){
            arr = {1};
        }
        else{
            arr.push_back(arr.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = arr.size();
        if(k >= n){
            return 0;
        }
        else{
            return arr[n-1] / arr[n-1-k];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */