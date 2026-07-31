class Solution {
public:
    int minimumPushes(string word) {
        vector<int>arr(26);
        for(auto ele:word)arr[ele-'a']++;
        sort(arr.rbegin(),arr.rend());
        int n=arr.size();
        int sum=0;
        int j=0;
        for(int i=0; i<26; i++){
            if(arr[i]){
                sum+=((j++/8)+1)*arr[i];
            }
        }
        return sum;
    }
};