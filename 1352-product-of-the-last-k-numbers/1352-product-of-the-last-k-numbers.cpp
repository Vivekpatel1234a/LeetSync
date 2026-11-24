class ProductOfNumbers {
public:
 int prod=1;
 int idx=0;
 int check=0;
 vector<int>nums;
    ProductOfNumbers() { 
    }
    
    void add(int num) {
        prod=prod*num;
        idx++;
        if(prod==0){
            prod=1;
            check=idx;
        }
        nums.push_back(prod);
    }
    
    int getProduct(int k) {
        int newcheck=check-1;
        int curridx=idx-1;
        int previdx=curridx-k;
        int curr=nums[curridx];
        int prev;
        if(previdx<0)prev=1;
        else prev=nums[previdx];
        if(previdx<newcheck)return 0;
        return curr/prev;


    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */