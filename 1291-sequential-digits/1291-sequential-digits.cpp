class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str="123456789";
        int i=0;
        vector<int>arr;
        while(i<9){
            int ans=0;
            int j=i;
            while(j<9){
            ans=ans*10+str[j]-'0';
            if(ans>=low && ans<=high){
                arr.push_back(ans);
            }
            if(ans>high)break;
            j++;
            }
            cout<<endl;
            i++;
        }
        sort(arr.begin(),arr.end());
return arr;

    }
};