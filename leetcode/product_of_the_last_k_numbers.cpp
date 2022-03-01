class ProductOfNumbers {
private:
    vector<int> cumProd;
    vector<int> nums;
    int lastZero;
public:
    ProductOfNumbers() {
        lastZero = 1000000000;
        cumProd.push_back(1);
    }
    
    void add(int num) {
        nums.push_back(num);
        if (num == 0){
            lastZero = 1;
            cumProd.push_back(1);
        }
        else{
            lastZero++;
            cumProd.push_back(num*cumProd.back());
        }
        return;
    }
    
    int getProduct(int k) {
        int n  = cumProd.size();
        if (k >= lastZero){return 0;}
        return cumProd[n-1]/cumProd[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */