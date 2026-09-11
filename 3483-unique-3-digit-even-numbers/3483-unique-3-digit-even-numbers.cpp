class Solution {
public:



    int totalNumbers(vector<int>& digits) {
        int cnt=0;
        unordered_map<string,int>mp;
        int n=digits.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    for(int k=0; k<n; k++){
                        if(k!=j && k!=i){
                            if(digits[k]%2==0 && digits[i]!=0){
                                cnt++;
                                string x=string(1,digits[i])+string(1,digits[j])+string(1,digits[k]);
                                mp[x]++;
                            }
                        }
                    }
                }
            }
        }
        return mp.size();
    }
};