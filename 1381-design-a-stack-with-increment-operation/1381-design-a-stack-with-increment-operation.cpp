class CustomStack {
public:
    int i=0;
    int j=0;
    int n;
     vector<int>arr;
    CustomStack(int maxSize) {
        n=maxSize;
        arr.resize(n,0);
    }
    
    void push(int x) {
        if(j<n){
            arr[j++]=x;
        }
    }
    
    int pop() {
        if(j==0)return -1;
        else {
            int x=arr[j-1];
            arr[j-1]=0;
            j--;
            return x;
            
        }
    }
    
    void increment(int k, int val) {
        for(int i=0; i<n && i<k; i++){
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */